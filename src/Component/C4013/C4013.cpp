/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4013
*/

#include "C4013.hpp"

C4013::C4013(const std::string &value) : nts::IComponent(), _value(value), _inputs(8), _outputs(4), _links(8), _ptrs(8)
{
    this->_outputs[1] = nts::UNDEFINED;
    this->_outputs[2] = nts::UNDEFINED;
    this->_outputs[12] = nts::UNDEFINED;
    this->_outputs[13] = nts::UNDEFINED;
    this->_inputs[3] = nts::UNDEFINED;
    this->_inputs[4] = nts::UNDEFINED;
    this->_inputs[5] = nts::UNDEFINED;
    this->_inputs[6] = nts::UNDEFINED;
    this->_inputs[8] = nts::UNDEFINED;
    this->_inputs[9] = nts::UNDEFINED;
    this->_inputs[10] = nts::UNDEFINED;
    this->_inputs[11] = nts::UNDEFINED;
}

C4013::C4013(const C4013 &other) : nts::IComponent(), _value(other._value), _inputs(other._inputs), _outputs(other._outputs), _links(other._links), _ptrs(other._ptrs)
{
}

C4013::~C4013()
{
}

nts::Tristate C4013::compute(std::size_t pin)
{
    if (pin == 12 || pin == 13)
        getResult(this->_inputs[8], this->_inputs[10], this->_inputs[9], this->_inputs[11], pin);
    else
        getResult(this->_inputs[6], this->_inputs[4], this->_inputs[5], this->_inputs[3], pin);
    return (this->_outputs[pin]);
}

void C4013::setAllInputs(size_t pin)
{
    if (pin == 12 || pin == 13) {
        this->_inputs[8] = this->_ptrs.find(8)->second.compute(this->_links[8]);
        this->_inputs[9] = this->_ptrs.find(9)->second.compute(this->_links[9]);
        this->_inputs[10] = this->_ptrs.find(10)->second.compute(this->_links[10]);
        this->_inputs[11] = this->_ptrs.find(11)->second.compute(this->_links[11]);
    }
    else {
        this->_inputs[3] = this->_ptrs.find(3)->second.compute(this->_links[3]);
        this->_inputs[4] = this->_ptrs.find(4)->second.compute(this->_links[4]);
        this->_inputs[5] = this->_ptrs.find(5)->second.compute(this->_links[5]);
        this->_inputs[6] = this->_ptrs.find(6)->second.compute(this->_links[6]);
    }
}

void C4013::getResult(nts::Tristate set, nts::Tristate reset, nts::Tristate data, nts::Tristate clock, size_t pin)
{
    if (set == nts::UNDEFINED || reset == nts::UNDEFINED) {
        setOutputs(nts::UNDEFINED, nts::UNDEFINED, pin);
        return;
    }
    else if (set == nts::FALSE && reset == nts::FALSE) {
        if (clock == nts::UNDEFINED || (clock == nts::TRUE && data == nts::UNDEFINED)) {
            setOutputs(nts::UNDEFINED, nts::UNDEFINED, pin);
        }
        else if (clock == nts::TRUE) {
            if (data == nts::FALSE)
                setOutputs(nts::FALSE, nts::TRUE, pin);
            else
                setOutputs(nts::TRUE, nts::FALSE, pin);
        }
    }
    else {
        if (set == nts::FALSE)
            setOutputs(nts::FALSE, nts::TRUE, pin);
        else if (reset == nts::FALSE)
            setOutputs(nts::TRUE, nts::FALSE, pin);
        else
            setOutputs(nts::TRUE, nts::TRUE, pin);
    }
}

void C4013::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    this->_links[pin] = otherPin;
    this->_ptrs.insert({pin, other});
}

void C4013::setOutputs(nts::Tristate state1, nts::Tristate state2, size_t pin)
{
    if (pin == 12 || pin == 13) {
        this->_outputs[12] = state2;
        this->_outputs[13] = state1;
    }
    else {
        this->_outputs[2] = state2;
        this->_outputs[1] = state1;
    }
}

void C4013::dump() const
{
    std::cout << "Component C4013: " << this->_value << std::endl;
    std::cout << "Inputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> link : this->_inputs) {
        std::cout << "\t" << link.first << ": " << link.second << std::endl;
    }
    std::cout << "Outputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> output : this->_outputs) {
        std::cout << "\t" << output.first << ": " << output.second << std::endl;
    }
}

C4013 &C4013::operator=(const C4013 &other)
{
    if (this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_inputs = other._inputs;
    this->_value = other._value;
    return(*this);
}

std::unordered_map<size_t, nts::Tristate> &C4013::getInputs()
{
    return (this->_inputs);
}

std::unordered_map<size_t, nts::Tristate> &C4013::getOutputs()
{
    return (this->_outputs);
}

bool C4013::testLink(size_t pin)
{
    if (pin == 12 || pin == 13) {
        if (this->_links[8] == 0 || this->_links[9] == 0 || this->_links[10] == 0 || this->_links[11] == 0)
            return (false);
    }
    else {
        if (this->_links[3] == 0 || this->_links[4] == 0 || this->_links[5] == 0 || this->_links[6] == 0)
            return (false);
    }
    return (true);
}