/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Links
*/

#ifndef LINKS_HPP_
	#define LINKS_HPP_

#include "Parser/Chipsets/Chipsets.hpp"

class Links {
	public:
		Links();
		~Links();

    struct links_t {
        std::string pinName1;
        std::string pinName2;
        int pin1;
        int pin2;
    };

    struct outputs_t {
        nts::IComponent &component;
        size_t pin;
    };

    int verifPins(int pin, int comp, const std::vector<Chipsets::chipset_t> &_chipsets);

    void putLinks(const std::string &line, const std::vector<Chipsets::chipset_t> &_chipsets);
    void linkStarto(links_t links, const std::vector<Chipsets::chipset_t> &_chipsets);
    void checkLinks();

    std::vector<links_t> _links;
    std::vector<outputs_t> _outputs;
	protected:
    private:
};

std::string findName(const std::string &line, size_t *i);
int findPin(const std::string &line, size_t *i, bool end);

#endif /* !LINKS_HPP_ */
