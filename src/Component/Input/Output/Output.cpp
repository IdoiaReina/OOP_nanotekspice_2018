/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Output
*/

#include "Output.hpp"

Output::Output(const std::string &value) : Input(value), _links(1), _ptrs(1)
{
}

Output::Output(const Output &other) : Input(other)
{
}

Output::~Output()
{
}

nts::Tristate Output::compute(std::size_t pin)
{
    (void)pin;
    this->_outputs[1] = this->_ptrs.find(1)->second.compute(this->_links[1]);
    return (this->_outputs[1]);
}

void Output::dump() const
{
    std::cout << "Component Output: " << this->_value << std::endl;
    std::cout << "State:" << this->_outputs.find(1)->second << std::endl;
}

void Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{ 
    this->_links[pin] = otherPin;
    this->_ptrs.insert({pin, other});
}

Output &Output::operator=(const Output &other)
{
    if (this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_value = other._value;
    return (*this);
}

bool Output::testLink(size_t pin)
{
    (void)pin;
    if (this->_links[1] != 0)
        return (true);
    return (false);
}

std::unordered_map<size_t, nts::Tristate> &Output::getInputs()
{
    return (this->_outputs);
}

std::unordered_map<size_t, nts::Tristate> &Output::getOutputs()
{
    return (this->_fix);
}