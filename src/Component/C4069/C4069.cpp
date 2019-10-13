/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4069
*/

#include "C4069.hpp"

C4069::C4069(const std::string &value) : nts::IComponent(), _value(value), _inputs(6), _outputs(6), _links(6), _ptrs(6)
{
    this->_outputs[2] = nts::UNDEFINED;
    this->_outputs[4] = nts::UNDEFINED;
    this->_outputs[6] = nts::UNDEFINED;
    this->_outputs[8] = nts::UNDEFINED;
    this->_outputs[10] = nts::UNDEFINED;
    this->_outputs[12] = nts::UNDEFINED;
    this->_inputs[1] = nts::UNDEFINED;
    this->_inputs[3] = nts::UNDEFINED;
    this->_inputs[5] = nts::UNDEFINED;
    this->_inputs[9] = nts::UNDEFINED;
    this->_inputs[11] = nts::UNDEFINED;
    this->_inputs[13] = nts::UNDEFINED;
}

C4069::C4069(const C4069 &other) : nts::IComponent(), _value(other._value), _inputs(other._inputs), _outputs(other._outputs)
{
}

C4069::~C4069()
{
}

nts::Tristate C4069::compute(std::size_t pin)
{
    setAllInputs(pin);
    if (pin <= 6)
        this->_outputs[pin] = getResult(this->_inputs[pin - 1]);
    else
        this->_outputs[pin] = getResult(this->_inputs[pin + 1]);
    return (this->_outputs[pin]);
}

void C4069::setAllInputs(size_t pin)
{
    if (pin <= 6)
        this->_inputs[pin - 1] = this->_ptrs.find(pin - 1)->second.compute(this->_links[pin - 1]);
    else
        this->_inputs[pin + 1] = this->_ptrs.find(pin + 1)->second.compute(this->_links[pin + 1]);
}

nts::Tristate C4069::getResult(nts::Tristate input)
{
    if (input == nts::TRUE) {
        return (nts::FALSE);
    }
    else if (input == nts::FALSE) {
        return (nts::TRUE);
    }
    return (nts::UNDEFINED);
}

void C4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    this->_links[pin] = otherPin;
    this->_ptrs.insert({pin, other});
}

void C4069::dump() const
{
    std::cout << "Component C4069: " << this->_value << std::endl;
    std::cout << "Inputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> link : this->_inputs) {
        std::cout << "\t" << link.first << ": " << link.second << std::endl;
    }
    std::cout << "Outputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> output : this->_outputs) {
        std::cout << "\t" << output.first << ": " << output.second << std::endl;
    }
}

std::unordered_map<size_t, nts::Tristate> &C4069::getInputs()
{
    return (this->_inputs);
}

std::unordered_map<size_t, nts::Tristate> &C4069::getOutputs()
{
    return (this->_outputs);
}

C4069 &C4069::operator=(const C4069 &other)
{
    if (this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_inputs = other._inputs;
    this->_value = other._value;
    return(*this);
}

bool C4069::testLink(size_t pin)
{
    if (pin <= 6 && this->_links[pin - 1] == 0) {
        return (false);
    }
    else if (pin > 6 && this->_links[pin + 1] == 0) {
        return (false);
    }
    return (true);
}