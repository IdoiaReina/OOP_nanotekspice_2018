/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Chipsets
*/

#include "Chipsets.hpp"

Chipsets::Chipsets() : _chipsets(0)
{
    std::vector<std::string> chipsetlist = {"true", "false", "clock", \
    "input", "output", "4001", "4008", "4011", "4013", "4017", "4030", \
    "4040", "4069", "4071", "4081", "4094", "4514", "4801", "2716"};
    _chipsetsList = chipsetlist;
}

Chipsets::~Chipsets()
{
}

int Chipsets::compareChipsets(std::string type)
{
    std::vector<std::string> list = getChipsetsList();

    for (size_t i = 0; i < getChipsetsList().size(); i++) {
        if (list[i] == type)
            return (0);
    }
    throw MyException("Chipset in file doesn't exist.");
}

void Chipsets::compareChipNames(std::string name)
{
    for (size_t i = 0; i < _chipsets.size(); i++) {
        if (_chipsets[i].name == name)
            throw MyException("Chipsets can't have the same name.");
    }
}

void Chipsets::putChipset(const std::string &line)
{
    size_t i = 0;
    chipset_t chip;

    while (line[i] != ' ' && line[i] != '\t') {
        if (line[i] == '\n' || line[i] == '\0' || line[i] == '#')
            throw MyException("Chipset Syntax must be ['type' 'name'].");
        chip.type += line[i];
        i += 1;
    }
    while (line[i] == ' ' || line[i] == '\t')
        i += 1;
    while (line[i] != '\n' && line[i] != '\0' && line[i] != '#' \
    && line[i] != ' ' && line[i] != '\t') {
        chip.name += line[i];
        i += 1;
    }
    try {
        compareChipsets(chip.type);
        compareChipNames(chip.name);
    }
    catch (MyException &msg) {throw msg;}
    pushChipset(chip);
}

void Chipsets::pushChipset(chipset_t &chip)
{
    Component comp;
    int size = _chipsets.size();
    _chipsets.resize(size + 1);
    _chipsets[size].type = chip.type;
    _chipsets[size].name = chip.name;
    _chipsets[size].component = comp.createComponent(chip.type, chip.name);
}

                /*Getters*/

int Chipsets::getChipsetsSize() const
{
    return (_chipsets.size());
}

const std::vector<Chipsets::chipset_t> &Chipsets::getChipsets() const
{
    return (_chipsets);
}

const std::string &Chipsets::getChipsetName(size_t i) const
{
    return(_chipsets[i].name);
}

const std::vector<std::string> &Chipsets::getChipsetsList() const
{
    return (_chipsetsList);
}
