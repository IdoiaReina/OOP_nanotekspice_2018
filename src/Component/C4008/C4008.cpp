/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4008
*/

#include "C4008.hpp"

C4008::C4008(const std::string &value) : nts::IComponent(), _value(value), _inputs(9), _outputs(5), _links(9), _ptrs(9)
{
    this->_outputs[10] = nts::UNDEFINED;
    this->_outputs[11] = nts::UNDEFINED;
    this->_outputs[12] = nts::UNDEFINED;
    this->_outputs[13] = nts::UNDEFINED;
    this->_outputs[14] = nts::UNDEFINED;
    this->_inputs[1] = nts::UNDEFINED;
    this->_inputs[2] = nts::UNDEFINED;
    this->_inputs[3] = nts::UNDEFINED;
    this->_inputs[4] = nts::UNDEFINED;
    this->_inputs[5] = nts::UNDEFINED;
    this->_inputs[6] = nts::UNDEFINED;
    this->_inputs[7] = nts::UNDEFINED;
    this->_inputs[9] = nts::UNDEFINED;
    this->_inputs[15] = nts::UNDEFINED;
}

C4008::C4008(const C4008 &other) : nts::IComponent(), _value(other._value), _inputs(other._inputs), _outputs(other._outputs), _links(other._links), _ptrs(other._ptrs)
{
}

C4008::~C4008()
{
}

nts::Tristate C4008::compute(std::size_t pin)
{
    nts::Tristate result = nts::UNDEFINED;

    setAllInputs(pin);
    if (pin == 10 || pin == 11 || pin == 12 || pin == 13 || pin == 14) {
        result = getResult(this->_inputs[6], this->_inputs[7], this->_inputs[9]);
        this->_outputs[10] = result;
    }
    if (pin == 11 || pin == 12 || pin == 13 || pin == 14) {
        result = getResult(this->_inputs[4], this->_inputs[5], result);
        this->_outputs[11] = result;
    }
    if (pin == 12 || pin == 13 || pin == 14) {
        result = getResult(this->_inputs[2], this->_inputs[3], result);
        this->_outputs[12] = result;
    }
    if (pin == 13 || pin == 14) {
        result = getResult(this->_inputs[1], this->_inputs[15], result);
        this->_outputs[13] = result;
        this->_outputs[14] = result;
    }
    return (this->_outputs[pin]);
}

nts::Tristate C4008::getResult(nts::Tristate input1, nts::Tristate input2, nts::Tristate input3)
{
    int count = 0;

    if (input1 == nts::TRUE)
        count += 1;
    if (input2 == nts::TRUE)
        count += 1;
    if (input3 == nts::TRUE)
        count += 1;
    if (count >= 2)
        return (nts::TRUE);
    return (nts::FALSE);
}

void C4008::setAllInputs(size_t pin)
{
    if (pin == 10 || pin == 11 || pin == 12 || pin == 13 || pin == 14) {
        this->_inputs[6] = this->_ptrs.find(6)->second.compute(this->_links[6]);
        this->_inputs[7] = this->_ptrs.find(7)->second.compute(this->_links[7]);
        this->_inputs[9] = this->_ptrs.find(9)->second.compute(this->_links[9]);
    }
    if (pin == 11 || pin == 12 || pin == 13 || pin == 14) {
        this->_inputs[4] = this->_ptrs.find(4)->second.compute(this->_links[4]);
        this->_inputs[5] = this->_ptrs.find(5)->second.compute(this->_links[5]);
    }
    if (pin == 12 || pin == 13 || pin == 14) {
        this->_inputs[2] = this->_ptrs.find(2)->second.compute(this->_links[2]);
        this->_inputs[3] = this->_ptrs.find(3)->second.compute(this->_links[3]);
    }
    if (pin == 13 || pin == 14) {
        this->_inputs[1] = this->_ptrs.find(1)->second.compute(this->_links[1]);
        this->_inputs[15] = this->_ptrs.find(15)->second.compute(this->_links[15]);
    }
}

void C4008::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    this->_links[pin] = otherPin;
    this->_ptrs.insert({pin, other});
}

void C4008::dump() const
{
    std::cout << "Component C4008: " << this->_value << std::endl;
    std::cout << "Inputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> link : this->_inputs) {
        std::cout << "\t" << link.first << ": " << link.second << std::endl;
    }
    std::cout << "Outputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> output : this->_outputs) {
        std::cout << "\t" << output.first << ": " << output.second << std::endl;
    }
}

C4008 &C4008::operator=(const C4008 &other)
{
    if (this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_inputs = other._inputs;
    this->_value = other._value;
    return(*this);
}

std::unordered_map<size_t, nts::Tristate> &C4008::getInputs()
{
    return (this->_inputs);
}

std::unordered_map<size_t, nts::Tristate> &C4008::getOutputs()
{
    return (this->_outputs);
}

bool C4008::testLink(size_t pin)
{
    if (pin == 10 || pin == 11 || pin == 12 || pin == 13 || pin == 14) {
        if (this->_links[6] == 0 || this->_links[7] == 0 || this->_links[9] == 0)
            return (false);
    }
    if (pin == 11 || pin == 12 || pin == 13 || pin == 14) {
        if (this->_links[4] == 0 || this->_links[5] == 0)
            return (false);
    }
    if (pin == 12 || pin == 13 || pin == 14) {
        if (this->_links[2] == 0 || this->_links[3] == 0)
            return (false);
    }
    if (pin == 13 || pin == 14) {
        if (this->_links[1] == 0 || this->_links[15] == 0)
            return (false);
    }
    return (true);
}