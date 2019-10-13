/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4094
*/

#include "C4094.hpp"

C4094::C4094(const std::string &value) : nts::IComponent(), _value(value), _inputs(4), _outputs(10), _links(4), _ptrs(4)
{
    this->_outputs[4] = nts::UNDEFINED;
    this->_outputs[5] = nts::UNDEFINED;
    this->_outputs[6] = nts::UNDEFINED;
    this->_outputs[7] = nts::UNDEFINED;
    this->_outputs[9] = nts::UNDEFINED;
    this->_outputs[10] = nts::UNDEFINED;
    this->_outputs[11] = nts::UNDEFINED;
    this->_outputs[12] = nts::UNDEFINED;
    this->_outputs[13] = nts::UNDEFINED;
    this->_outputs[14] = nts::UNDEFINED;
    this->_inputs[1] = nts::UNDEFINED;
    this->_inputs[2] = nts::UNDEFINED;
    this->_inputs[3] = nts::UNDEFINED;
    this->_inputs[15] = nts::UNDEFINED;
}

C4094::C4094(const C4094 &other)  : nts::IComponent(), _value(other._value), _inputs(other._inputs), _outputs(other._outputs)
{
}

C4094::~C4094()
{
}

nts::Tristate C4094::compute(std::size_t pin)
{
    setAllInputs();
    if (this->_inputs[15] == nts::FALSE) {
        setAllParallelOutputs(nts::UNDEFINED);
        if (this->_inputs[3] == nts::TRUE)
            this->_outputs[9] = nts::UNDEFINED;
        else
            this->_outputs[10] = nts::UNDEFINED;
        
    }
    else {
        getResult();
    }
    return (this->_outputs[pin]);
}

void C4094::setAllParallelOutputs(nts::Tristate state)
{
    this->_outputs[4] = state;
    this->_outputs[5] = state;
    this->_outputs[6] = state;
    this->_outputs[7] = state;
    this->_outputs[11] = state;
    this->_outputs[12] = state;
    this->_outputs[13] = state;
    this->_outputs[14] = state;
}

void C4094::setAllParallelOutputsCascading(nts::Tristate state)
{
    this->_outputs[9] = this->_outputs[12];
    this->_outputs[11] = this->_outputs[12];
    this->_outputs[12] = this->_outputs[13];
    this->_outputs[13] = this->_outputs[14];
    this->_outputs[14] = this->_outputs[7];
    this->_outputs[7] = this->_outputs[6];
    this->_outputs[6] = this->_outputs[5];
    this->_outputs[5] = this->_outputs[4];
    this->_outputs[4] = state;
}

void C4094::setAllInputs()
{
    this->_inputs[1] = this->_ptrs.find(1)->second.compute(this->_links[1]);
    this->_inputs[2] = this->_ptrs.find(2)->second.compute(this->_links[2]);
    this->_inputs[3] = this->_ptrs.find(3)->second.compute(this->_links[3]);
    this->_inputs[15] = this->_ptrs.find(15)->second.compute(this->_links[15]);
}

void C4094::getResult()
{
    if (this->_inputs[3] == nts::TRUE) {
        if (this->_inputs[1] == nts::FALSE) {
            this->_outputs[9] = this->_outputs[12];
        }
        else {
            if (this->_inputs[2] == nts::TRUE)
                setAllParallelOutputsCascading(nts::TRUE);
            else
                setAllParallelOutputsCascading(nts::FALSE);
        }
    }
    else if (this->_inputs[3] == nts::FALSE && this->_inputs[1] == nts::TRUE && this->_inputs[2] == nts::TRUE) {
        this->_outputs[10] = this->_outputs[12];
    }
}

void C4094::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    this->_links[pin] = otherPin;
    this->_ptrs.insert({pin, other});
}

void C4094::dump() const
{
    std::cout << "Component C4094: " << this->_value << std::endl;
    std::cout << "Inputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> link : this->_inputs) {
        std::cout << "\t" << link.first << ": " << link.second << std::endl;
    }
    std::cout << "Outputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> output : this->_outputs) {
        std::cout << "\t" << output.first << ": " << output.second << std::endl;
    }
}

std::unordered_map<size_t, nts::Tristate> &C4094::getInputs()
{
    return (this->_inputs);
}

std::unordered_map<size_t, nts::Tristate> &C4094::getOutputs()
{
    return (this->_outputs);
}

C4094 &C4094::operator=(const C4094 &other)
{
    if (this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_inputs = other._inputs;
    this->_value = other._value;
    return(*this);
}

bool C4094::testLink(size_t pin)
{
    (void)pin;
    if (this->_links[1] == 0 || this->_links[2] == 0 || this->_links[3] == 0 || this->_links[15] == 0)
        return (false);
    return (true);
}