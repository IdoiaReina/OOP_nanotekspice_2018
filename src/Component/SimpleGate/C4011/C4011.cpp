/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4011
*/

#include "C4011.hpp"

C4011::C4011(const std::string &value) : SimpleGate(value)
{   
}

C4011::C4011(const C4011 &other) : SimpleGate(other)
{
}

C4011::~C4011()
{
}

void C4011::dump() const
{
    std::cout << "Component C4011: " << this->_value << std::endl;
    std::cout << "Inputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> link : this->_inputs) {
        std::cout << "\t" << link.first << ": " << link.second << std::endl;
    }
    std::cout << "Outputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> output : this->_outputs) {
        std::cout << "\t" << output.first << ": " << output.second << std::endl;
    }
}

C4011 &C4011::operator=(const C4011 &other)
{
    if (this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_inputs = other._inputs;
    this->_value = other._value;
    return(*this);
}

nts::Tristate C4011::getResult(nts::Tristate input1, nts::Tristate input2)
{
    if (input1 == nts::FALSE || input2 == nts::FALSE)
        return (nts::TRUE);
    else if (input1 == nts::UNDEFINED || input2 == nts::UNDEFINED)
        return (nts::UNDEFINED);
    return (nts::FALSE);
}