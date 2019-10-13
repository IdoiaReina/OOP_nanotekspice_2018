/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock(const std::string &value) : Input(value)
{
}

Clock::Clock(const Clock &other) : Input(other)
{
}

Clock::~Clock()
{
}

void Clock::dump() const
{
    std::cout << "Component Clock: " << this->_value << std::endl;
    std::cout << "State:" << this->_outputs.find(1)->second << std::endl;
}

Clock &Clock::operator=(const Clock &other)
{
    if (this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_value = other._value;
    return (*this);
}