/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** True
*/

#include "True.hpp"

True::True(const std::string &value) : Input(value)
{
    this->_outputs[1] = nts::TRUE;
}

True::True(const True &other) : Input(other)
{
}

True::~True()
{
}

void True::dump() const
{
    std::cout << "Component True: " << this->_value << std::endl;
    std::cout << "State:" << this->_outputs.find(1)->second << std::endl;
}

True &True::operator=(const True &other)
{
    if (this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_value = other._value;
    return (*this);
}