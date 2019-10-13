/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** False
*/

#include "False.hpp"

False::False(const std::string &value) : Input(value)
{
    this->_outputs[1] = nts::FALSE;
}

False::False(const False &other) : Input(other)
{
}

False::~False()
{
}

void False::dump() const
{
    std::cout << "Component False: " << this->_value << std::endl;
    std::cout << "State:" << this->_outputs.find(1)->second << std::endl;
}

False &False::operator=(const False &other)
{
    if (this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_value = other._value;
    return (*this);
}