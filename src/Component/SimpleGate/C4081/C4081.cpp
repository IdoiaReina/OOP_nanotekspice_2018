/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4081
*/

#include "C4081.hpp"

C4081::C4081(const std::string &value) : SimpleGate(value)
{
}

C4081::C4081(const C4081 &other) : SimpleGate(other)
{
}

C4081::~C4081()
{
}

void C4081::dump() const
{
    std::cout << "Component 4081: " << this->_value << std::endl;
    std::cout << "Inputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> link : this->_inputs) {
        std::cout << "\t" << link.first << ": " << link.second << std::endl;
    }
    std::cout << "Outputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> output : this->_outputs) {
        std::cout << "\t" << output.first << ": " << output.second << std::endl;
    }
}

nts::Tristate C4081::getResult(nts::Tristate input1, nts::Tristate input2)
{
    if (input1 == nts::TRUE && input2 == nts::TRUE)
        return (nts::TRUE);
    else if (input1 == nts::FALSE || input2 == nts::FALSE)
        return (nts::FALSE);
    return (nts::UNDEFINED);
}

C4081 &C4081::operator=(const C4081 &other)
{
    if (this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_inputs = other._inputs;
    this->_value = other._value;
    return(*this);
}