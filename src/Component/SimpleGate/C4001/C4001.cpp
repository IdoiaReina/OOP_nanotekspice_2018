/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4001
*/

#include "C4001.hpp"

C4001::C4001(const std::string &value) : SimpleGate(value)
{   
}

C4001::C4001(const C4001 &other) : SimpleGate(other)
{
}

C4001::~C4001()
{
}

void C4001::dump() const
{
    std::cout << "Component C4001: " << this->_value << std::endl;
    std::cout << "Inputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> link : this->_inputs) {
        std::cout << "\t" << link.first << ": " << link.second << std::endl;
    }
    std::cout << "Outputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> output : this->_outputs) {
        std::cout << "\t" << output.first << ": " << output.second << std::endl;
    }
}

nts::Tristate C4001::getResult(nts::Tristate input1, nts::Tristate input2)
{
    if (input1 == nts::TRUE || input2 == nts::TRUE)
        return (nts::FALSE);
    else if (input1 == nts::UNDEFINED || input2 == nts::UNDEFINED)
        return (nts::UNDEFINED);
    return (nts::TRUE);
}

C4001 &C4001::operator=(const C4001 &other)
{
    if (this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_inputs = other._inputs;
    this->_value = other._value;
    return(*this);
}