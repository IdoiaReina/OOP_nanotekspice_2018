/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Parser
*/

#ifndef PARSER_HPP_
	#define PARSER_HPP_

#include "Chipsets/Chipsets.hpp"
#include "Links/Links.hpp"
#include <list>
#include <signal.h>

class Parser {
	public:
	Parser(int ac, char **av);
	~Parser();

    int parsingArgs(int ac, char **av);
    void parsingLine(const std::string &line);
    void fileReader();
	const std::string &getFilename() const;
    void inputReader(int ac, char **av);
    /**/
    const std::vector<std::string> &getContent() const;
    const std::string &getContentAtPos(size_t i) const;
    void putInContent(const std::string &line);
    /**/
    void openAndReadFile();
    /**/
    void readChipsets(size_t i);
    Chipsets _myChipsets;
    /**/
    void readLinks(size_t i);
    Links _myLinks;
    /**/
    void simulate(bool isFirst);
    void display();
    void dump();
    void loop(Parser &ptr);

    protected:
    std::string _filename;
    std::vector<std::string> _content;
    std::vector<Links::links_t> _inputs;
};

void displayUsage();

#endif /* !PARSER_HPP_ */
