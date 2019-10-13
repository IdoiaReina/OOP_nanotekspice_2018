/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Chipsets
*/

#ifndef CHIPSETS_HPP_
#define CHIPSETS_HPP_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "MyException/MyException.hpp"
#include "Component/Component.hpp"

class Chipsets {
	public:
		Chipsets();
		~Chipsets();

    struct chipset_t {
        std::string type;
        std::string name;
        std::unique_ptr<nts::IComponent> component;
    };

    void putChipset(const std::string &line);
    void pushChipset(chipset_t &chip);
    /**/
    const std::string &getChipsetName(size_t i) const;
    int getChipsetsSize() const;
    const std::vector<Chipsets::chipset_t> &getChipsets() const;
    const std::vector<std::string> &getChipsetsList() const;
    /**/
    int compareChipsets(std::string type);
    void compareChipNames(std::string name);

    std::vector<chipset_t> _chipsets;
    std::vector<std::string> _chipsetsList;
};

#endif /* !CHIPSETS_HPP_ */