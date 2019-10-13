/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** SimpleGate
*/

#include "SimpleGate.hpp"

SimpleGate::SimpleGate(const std::string &value) : nts::IComponent(), _value(value), _inputs(8), _outputs(4), _links(8), _ptrs(8)
{
    this->_outputs[3] = nts::UNDEFINED;
    this->_outputs[4] = nts::UNDEFINED;
    this->_outputs[10] = nts::UNDEFINED;
    this->_outputs[11] = nts::UNDEFINED;
    this->_inputs[1] = nts::UNDEFINED;
    this->_inputs[2] = nts::UNDEFINED;
    this->_inputs[5] = nts::UNDEFINED;
    this->_inputs[6] = nts::UNDEFINED;
    this->_inputs[8] = nts::UNDEFINED;
    this->_inputs[9] = nts::UNDEFINED;
    this->_inputs[12] = nts::UNDEFINED;
    this->_inputs[13] = nts::UNDEFINED;
}

SimpleGate::SimpleGate(const SimpleGate &other) : nts::IComponent(), _value(other._value), _inputs(other._inputs), _outputs(other._outputs), _links(other._links), _ptrs(other._ptrs)
{
}

SimpleGate::~SimpleGate()
{
}

nts::Tristate SimpleGate::compute(std::size_t pin)
{
    setAllInputs(pin);
    if (pin == 3) {
        this->_outputs[3] = getResult(this->_inputs[1], this->_inputs[2]);
        return (this->_outputs[3]);
    }
    else if (pin == 4) {
        this->_outputs[4] = getResult(this->_inputs[5], this->_inputs[6]);
        return (this->_outputs[4]);
    }
    else if (pin == 10) {
        this->_outputs[10] = getResult(this->_inputs[8], this->_inputs[9]);
        return (this->_outputs[10]);
    }
    this->_outputs[11] = getResult(this->_inputs[12], this->_inputs[13]);
    return (this->_outputs[11]);
}

void SimpleGate::setAllInputs(size_t pin)
{
    if (pin == 3) {
        this->_inputs[1] = this->_ptrs.find(1)->second.compute(this->_links[1]);
        this->_inputs[2] = this->_ptrs.find(2)->second.compute(this->_links[2]);
    }
    else if (pin == 4) {
        this->_inputs[5] = this->_ptrs.find(5)->second.compute(this->_links[5]);
        this->_inputs[6] = this->_ptrs.find(6)->second.compute(this->_links[6]);
    }
    else if (pin == 10) {
        this->_inputs[8] = this->_ptrs.find(8)->second.compute(this->_links[8]);
        this->_inputs[9] = this->_ptrs.find(9)->second.compute(this->_links[9]);
    }
    else if (pin == 11) {
        this->_inputs[12] = this->_ptrs.find(12)->second.compute(this->_links[12]);
        this->_inputs[13] = this->_ptrs.find(13)->second.compute(this->_links[13]);
    }
}

void SimpleGate::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    this->_links[pin] = otherPin;
    this->_ptrs.insert({pin, other});
}

void SimpleGate::dump() const
{
    std::cout << "Component SimpleGate: " << this->_value << std::endl;
    std::cout << "Inputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> link : this->_inputs) {
        std::cout << "\t" << link.first << ": " << link.second << std::endl;
    }
    std::cout << "Outputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> output : this->_outputs) {
        std::cout << "\t" << output.first << ": " << output.second << std::endl;
    }
}

nts::Tristate SimpleGate::getResult(nts::Tristate input1, nts::Tristate input2)
{
    if (input1 == nts::TRUE || input2 == nts::TRUE)
        return (nts::FALSE);
    else if (input1 == nts::UNDEFINED || input2 == nts::UNDEFINED)
        return (nts::UNDEFINED);
    return (nts::TRUE);
}

std::unordered_map<size_t, nts::Tristate> &SimpleGate::getInputs()
{
    return (this->_inputs);
}

std::unordered_map<size_t, nts::Tristate> &SimpleGate::getOutputs()
{
    return (this->_outputs);
}

SimpleGate &SimpleGate::operator=(const SimpleGate &other)
{
    if (this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_inputs = other._inputs;
    this->_value = other._value;
    return(*this);
}

bool SimpleGate::testLink(size_t pin)
{
    int test = 0;

    for (std::pair<size_t, size_t> input : this->_inputs) {
        if (pin == 3 && (input.first == 1 || input.first == 2))
            test += 1;
        else if (pin == 4 && (input.first == 5 || input.first == 6))
            test += 1;
        else if (pin == 10 && (input.first == 8 || input.first == 9))
            test += 1;
        else if (pin == 11 && (input.first == 12 || input.first == 13))
            test += 1;
    }
    if (test == 2)
        return (true);
    return (false);
}