/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4071
*/

#include "C4071.hpp"

C4071::C4071(const std::string &value) : SimpleGate(value)
{
}

C4071::C4071(const C4071 &other) : SimpleGate(other)
{
}

C4071::~C4071()
{
}

void C4071::dump() const
{
    std::cout << "Component 4071: " << this->_value << std::endl;
    std::cout << "Inputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> link : this->_inputs) {
        std::cout << "\t" << link.first << ": " << link.second << std::endl;
    }
    std::cout << "Outputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> output : this->_outputs) {
        std::cout << "\t" << output.first << ": " << output.second << std::endl;
    }
}

nts::Tristate C4071::getResult(nts::Tristate input1, nts::Tristate input2)
{

    if (input1 == nts::TRUE || input2 == nts::TRUE)
        return (nts::TRUE);
    else if (input1 == nts::UNDEFINED || input2 == nts::UNDEFINED)
        return(nts::UNDEFINED);
    return(nts::FALSE);
}

C4071 &C4071::operator=(const C4071 &other)
{
    if (this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_inputs = other._inputs;
    this->_value = other._value;
    return(*this);
}