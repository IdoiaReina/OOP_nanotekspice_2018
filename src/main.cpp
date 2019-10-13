/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** main
*/

#include "Parser/Parser.hpp"
#include "MyException/MyException.hpp"

int main(int ac, char **av)
{
    std::string line;
    try {
        Parser ptr(ac, av);
        ptr.parsingArgs(ac, av);
        ptr.simulate(true);
        ptr.display();
        std::cout << "> ";
        while (line != "exit") {
            std::cin >> line;
            if (line == "exit")
                return (0);
            else if (line == "display")
                ptr.display();
            else if (line == "simulate")
                ptr.simulate(false);
            else if (line == "dump")
                ptr.dump();
            else if (line == "loop")
                ptr.loop(ptr);
            else
                ptr.parsingLine(line);
            std::cout << "> ";
        }
    }
    catch (MyException &msg) { msg.displayError(); return(84); }
    return (0);
}