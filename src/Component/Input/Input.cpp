/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Input
*/

#include "Input.hpp"

Input::Input(const std::string &value) : nts::IComponent(), _value(value), _fix(1), _outputs(1)
{
    this->_outputs[1] = nts::UNDEFINED;
    this->_fix[37298] = nts::UNDEFINED;
}

Input::Input(const Input &other) : nts::IComponent(), _value(other._value), _outputs(1)
{
}

Input::~Input()
{
}

nts::Tristate Input::compute(std::size_t pin)
{
    (void)pin;
    return (this->_outputs[1]);
}

void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    (void)other;
    (void)otherPin;

    if (pin == 0)
        this->_outputs[1] = nts::FALSE;
    else if (pin == 1)
        this->_outputs[1] = nts::TRUE;
    else
        this->_outputs[1] = nts::UNDEFINED;
}

void Input::dump() const
{
    std::cout << "Component Input: " << this->_value << std::endl;
    std::cout << "State:" << this->_outputs.find(1)->second << std::endl;
}

std::unordered_map<size_t, nts::Tristate> &Input::getInputs()
{
    return (this->_fix);
}

std::unordered_map<size_t, nts::Tristate> &Input::getOutputs()
{
    return (this->_outputs);
}

Input &Input::operator=(const Input &other)
{
    if (this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_value = other._value;
    return (*this);
}

bool Input::testLink(size_t pin)
{
    (void)pin;
    return (true);
}