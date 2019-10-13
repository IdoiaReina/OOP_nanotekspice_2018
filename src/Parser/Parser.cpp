/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser(int ac, char **av)
{
    if (ac > 1) {
    std::string newfilename(av[1]);
    _filename = newfilename;
    }
}

Parser::~Parser()
{
}

const std::string &Parser::getFilename() const
{
    return (_filename);
}

const std::vector<std::string> &Parser::getContent() const
{
    return (_content);
}

const std::string &Parser::getContentAtPos(size_t i) const
{
    return (_content[i]);
}

void Parser::putInContent(const std::string &line)
{
    _content.push_back(line);
}

void Parser::readChipsets(size_t i)
{
    while (getContentAtPos(i) != ".links:" && i < getContent().size()) {
        try { _myChipsets.putChipset(getContentAtPos(i)); }
        catch (MyException &msg) { throw msg; }
        i += 1;
    }
}

void Parser::readLinks(size_t i)
{
    while (i < getContent().size()) {
        try { _myLinks.putLinks(getContentAtPos(i), _myChipsets._chipsets); }
        catch (MyException &msg) { throw msg; }
        i += 1;
    }
    try { _myLinks.checkLinks(); }
    catch (MyException &msg) {throw msg; }
}

void Parser::openAndReadFile()
{
    std::ifstream fs;
    std::string line;
    size_t i = 0;

    fs.open(getFilename());
    if (!fs.is_open())
        throw MyException("File not found.");
    while (std::getline(fs, line)) {
        if (line.size() > 0 && line[0] != '#' && line[0] != '\n') {
                line[line.size()] = '\n';
            if (line[0] == '.')
                i += 1;
            putInContent(line);
        }
    }
    if (i != 2)
        throw MyException("File must contain '.links:' and '.chipsets:'.");
    fs.close();
}

void Parser::fileReader()
{
    size_t i = 0;

    try { openAndReadFile(); }
    catch (MyException &msg) { throw msg; }
    for (const std::string &line : getContent()) {
        if (line[0] == '.' && line == ".chipsets:")
            readChipsets(++i);
        else if (line[0] == '.' && line == ".links:")
            readLinks(i);
        else if (line[0]== '.')
            throw MyException("Section isn't '.chipsets' nor '.links'.");
        i += 1;
    }
}

void displayUsage()
{
    std::cout << "NanoTekSpice:\nUSAGE :\n\t" << \
    "./nanotekspice circuit_file.nts input_name=input_value\n" << std::endl;
}

void Parser::inputReader(int ac, char **av)
{
    Links::links_t in;
    int j = 0;

    for(int i = 2; i < ac; i++) {
        j = 0;
        in.pinName1.clear();
        in.pinName2.clear();
        while (av[i][j] != '=' && av[i][j] != '\0' && av[i][j] != '#') {
            in.pinName1 += av[i][j];
            j++;
        }
        if (av[i][j] == '\0')
            throw MyException("Input Value Syntax: [input=value]");
        j++;
        while (av[i][j] != '\0' && av[i][j] != '#') {
            in.pinName2 += av[i][j];
            j++;
        }
        if (in.pinName2 != "1" && in.pinName2 != "-1" && in.pinName2 != "0")
            throw MyException("Input Value must be 0, 1 or -1.");
        in.pin1 = stoi(in.pinName2);
        j = 0;
        while (in.pinName1 != _myChipsets._chipsets[j].name)
            j++;
        if (in.pin1 != -1)
            _myChipsets._chipsets[j].component->setLink\
            (in.pin1, *_myChipsets._chipsets[j].component, 0);
        else
            _myChipsets._chipsets[j].component->setLink\
            (2, *_myChipsets._chipsets[j].component, 0);
        _inputs.push_back(in);
    }
}

int Parser::parsingArgs(int ac, char **av)
{
    if (ac < 2) {
        if (ac == 2 && av[1][0] == '-') {
            displayUsage();
            return (0);
        }
        throw MyException("Missing Argument(s).");
    }
    try {
        fileReader();
        inputReader(ac, av);
    }
    catch (MyException &msg) { throw msg; }
    return (0);
}

void Parser::parsingLine(const std::string &line)
{
    Links::links_t in;
    int j = 0;

    for(size_t i = 0; i < line.length(); i++) {
        in.pinName1.clear();
        in.pinName2.clear();
        while (line[i] == ' ' && line[i] == '\t')
        i++;
        while (line[i] != '=' && line[i] != '\0') {
            in.pinName1 += line[i];
            i++;
        }
        if (line[i] == '\0')
            throw MyException("Input Value Syntax: [input=value]");
        i++;
        while (line[i] != '\0' && line[i] != ' ') {
            in.pinName2 += line[i];
            i++;
        }
        if (in.pinName2 != "1" && in.pinName2 != "-1" && in.pinName2 != "0")
            throw MyException("Input Value must be 0, 1 or -1.");
        in.pin1 = stoi(in.pinName2);
        while (in.pinName1 != _myChipsets._chipsets[j].name)
            j++;
        if (in.pin1 != -1)
            _myChipsets._chipsets[j].component->setLink\
            (in.pin1, *_myChipsets._chipsets[j].component, 0);
        else
            _myChipsets._chipsets[j].component->setLink\
            (2, *_myChipsets._chipsets[j].component, 0);
        _inputs.push_back(in);
    }
}

static bool boolLoop;

void Parser::simulate(bool isFirst)
{
    for (size_t i = 0; i < _myChipsets._chipsets.size(); i++) {
        if (_myChipsets._chipsets[i].type == "clock" && !isFirst) {
            if (_myChipsets._chipsets[i].component->\
            getOutputs()[1] == nts::TRUE) {
                _myChipsets._chipsets[i].component->\
                setLink(0, *_myChipsets._chipsets[i].component, 4);
            }
            else if (_myChipsets._chipsets[i].component->\
            getOutputs()[1] == nts::FALSE) {
                _myChipsets._chipsets[i].component->\
                setLink(1, *_myChipsets._chipsets[i].component, 4);
            }
        }
    }
    for (size_t i = 0; i < _myChipsets._chipsets.size(); i++) {
        if (_myChipsets._chipsets[i].type == "output")
            _myChipsets._chipsets[i].component->compute();
    }
}

void Parser::display()
{
    int j = 0;
    std::list<std::string> list;
    for (size_t i = 0; i < _myChipsets._chipsets.size(); i++) {
        if (_myChipsets._chipsets[i].type == "output") {
            list.push_back(_myChipsets._chipsets[i].name);
        }
    }
    list.sort();
    while (list.size() > 0) {
        while (_myChipsets._chipsets[j].name != list.front())
            j++;
        std::cout << _myChipsets._chipsets[j].name << '=';
        if (_myChipsets._chipsets[j].component->getInputs()[1] == nts::UNDEFINED)
            std::cout << "U" << std::endl;
        else {
            std::cout << _myChipsets._chipsets[j].component->getInputs()[1] \
            << std::endl;
        }
        j = 0;
        list.remove(list.front());
    }
}

void Parser::dump()
{
    for (size_t i = 0; i < _myChipsets._chipsets.size(); i++) {
        _myChipsets._chipsets[i].component->dump();
    }
}

void handleSignal(int signal)
{
    (void)signal;
    boolLoop = false;
}

void Parser::loop(Parser &ptr)
{
    struct sigaction sh;

    boolLoop = true;
    sh.sa_handler = handleSignal;
    sigemptyset(&sh.sa_mask);
    sh.sa_flags = 0;
    sigaction(SIGINT, &sh, NULL);
    while(boolLoop)
        ptr.simulate(false);
}