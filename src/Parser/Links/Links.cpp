/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Links
*/

#include "./Links.hpp"

Links::Links() : _links(), _outputs()
{
}

Links::~Links()
{
}

std::string findName(const std::string &line, size_t *i)
{
    std::string name1;

    while (line[i[0]] != ':' && line[i[0]] != '\n' && line[i[0]] != '\0' \
    && line[i[0]] != '#') {
        name1 += line[i[0]];
        i[0] += 1;
    }
    if (line[i[0]] == '\n' || line[i[0]] == '\0' || line[i[0]] == '#')
        throw MyException("Wrong Links Syntax.");
    i[0] +=1;
    if (line[i[0]] == '\n' || line[i[0]] == '\0' || line[i[0]] == '#')
        throw MyException("Wrong Links Syntax.");
    if (name1.length() == 0)
        throw MyException("Wrong Links Syntax.");
    return (name1);
}

int findPin(const std::string &line, size_t *i, bool end)
{
    std::string pin1;

    while (line[i[0]] != ' ' && line[i[0]] != '\t' && line[i[0]] != '\n' \
    && line[i[0]] != '\0' && line[i[0]] != '#') {
        pin1 += line[i[0]];
        i[0] += 1;
    }
    if (pin1.length() == 0)
        throw MyException("Wrong Links Syntax.");
    for (size_t len = 0; len < pin1.length(); len++) {
        if (pin1[len] < '0' || pin1[len] > '9')
            throw MyException("Pin must be an integer.");
    }
    if (end == true)
        return (stoi(pin1));
    if (line[i[0]] == '\n' || line[i[0]] == '\0')
            throw MyException("Wrong Links Syntax.");
    return (stoi(pin1));
}

int Links::verifPins(int pin, int comp, const std::vector<Chipsets::chipset_t> &_chipsets)
{
    int which = 0;

    std::unordered_map<size_t, nts::Tristate> inputs =\
    _chipsets[comp].component->getInputs();
    for (std::pair<size_t, nts::Tristate> input : inputs) {
        if (input.first == (size_t)pin) {
            which = 1;
            break;
        }
    }

    std::unordered_map<size_t, nts::Tristate> outputs =\
    _chipsets[comp].component->getOutputs();
    for (std::pair<size_t, nts::Tristate> output : outputs) {
        if (output.first == (size_t)pin) {
            which += 2;
            break;
        }
    }
    return (which);
}

void Links::linkStarto(links_t links, const std::vector<Chipsets::chipset_t> &_chipsets)
{
    int i = 0;
    int first = 0;
    int verif_first = 0;
    int verif_second = 0;

    while (links.pinName1 != _chipsets[first].name)
        first++;
    while (links.pinName2 != _chipsets[i].name)
        i++;
    verif_first = verifPins(links.pin1, first, _chipsets);
    verif_second = verifPins(links.pin2, i, _chipsets);
    if (verif_second == 0 || verif_first == 0)
        throw MyException("Cannont find pin in file.");
    if (verif_first == verif_second)
        throw MyException("Cannot link two input or outputs together.");
    else if (verif_first == 2) {
        _chipsets[i].component->setLink(links.pin2, *_chipsets[first].component, links.pin1);
        outputs_t toAdd = {*_chipsets[first].component, (size_t)links.pin1};
        _outputs.push_back(toAdd);
    }
    else {
        _chipsets[first].component->setLink(links.pin1, *_chipsets[i].component, links.pin2);
        outputs_t toAdd = {*_chipsets[i].component, (size_t)links.pin2};
        _outputs.push_back(toAdd);
    }
}

void Links::checkLinks()
{
    for (outputs_t link : this->_outputs) {
        if (!link.component.testLink(link.pin))
            throw MyException("Link not set.");
    }
}

void Links::putLinks(const std::string &line, const std::vector<Chipsets::chipset_t> &_chipsets)
{
    size_t i = 0;
    links_t links;

    try {
        links.pinName1 = findName(line, &i);
        links.pin1 = findPin(line, &i, false);
        while (line[i] == ' ' || line[i] == '\t')
            i += 1;
        links.pinName2 = findName(line, &i);
        links.pin2 = findPin(line, &i, true);
        linkStarto(links, _chipsets);
        _links.push_back(links);
    }
    catch (MyException &msg) {throw msg;};
}