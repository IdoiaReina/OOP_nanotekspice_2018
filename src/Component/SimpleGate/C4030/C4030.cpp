/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4030
*/

#include "C4030.hpp"

C4030::C4030(const std::string &value) : SimpleGate(value)
{
}

C4030::C4030(const C4030 &other) : SimpleGate(other)
{
}

C4030::~C4030()
{
}

void C4030::dump() const
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

nts::Tristate C4030::getResult(nts::Tristate input1, nts::Tristate input2)
{

    if (input1 == nts::UNDEFINED || input2 == nts::UNDEFINED)
        return (nts::UNDEFINED);
    else if (input1 == input2)
        return (nts::FALSE);
    return (nts::TRUE);
}

C4030 &C4030::operator=(const C4030 &other)
{
    if (this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_inputs = other._inputs;
    this->_value = other._value;
    return(*this);
}