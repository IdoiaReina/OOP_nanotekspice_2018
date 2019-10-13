/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4040
*/

#include "C4040.hpp"

C4040::C4040(const std::string &value) : nts::IComponent(), _value(value), _inputs(2), _outputs(12), _links(2), _ptrs(2), _isUsed(12)
{
    setAllOutputs(nts::FALSE);
    setAllIsUsed(false);
    this->_inputs[10] = nts::UNDEFINED;
    this->_inputs[11] = nts::UNDEFINED;
}

C4040::C4040(const C4040 &other) : nts::IComponent(), _value(other._value), _inputs(other._inputs), _outputs(other._outputs), _links(other._links), _ptrs(other._ptrs)
{
}

C4040::~C4040()
{
}

void C4040::setAllOutputs(nts::Tristate state)
{
    this->_outputs[1] = state;
    this->_outputs[2] = state;
    this->_outputs[3] = state;
    this->_outputs[4] = state;
    this->_outputs[5] = state;
    this->_outputs[6] = state;
    this->_outputs[7] = state;
    this->_outputs[9] = state;
    this->_outputs[12] = state;
    this->_outputs[13] = state;
    this->_outputs[14] = state;
    this->_outputs[15] = state;
}

void C4040::setAllIsUsed(bool state)
{
    this->_isUsed[1] = state;
    this->_isUsed[2] = state;
    this->_isUsed[3] = state;
    this->_isUsed[4] = state;
    this->_isUsed[5] = state;
    this->_isUsed[6] = state;
    this->_isUsed[7] = state;
    this->_isUsed[9] = state;
    this->_isUsed[12] = state;
    this->_isUsed[13] = state;
    this->_isUsed[14] = state;
    this->_isUsed[15] = state;
}

nts::Tristate C4040::compute(size_t pin)
{
    if (checkSameSimulation(pin))
        return (this->_outputs[pin]);
    setAllInputs();
    if (this->_inputs[11] == nts::TRUE)
        setAllOutputs(nts::FALSE);
    else if (this->_inputs[10] != nts::UNDEFINED && this->_inputs[10] != nts::TRUE) {
        getResult();
    }
    return (this->_outputs[pin]);
}

bool C4040::checkSameSimulation(size_t pin)
{
    if (this->_isUsed[pin] == true) {
        setAllIsUsed(false);
        this->_isUsed[pin] = true;
        return (false);
    }
    for (std::pair<size_t, bool> output : this->_isUsed) {
        if (output.second) {
            this->_isUsed[pin] = true;
            return (true);
        }
    }
    this->_isUsed[pin] = true;
    return (false);
}

void C4040::setAllInputs()
{
    this->_inputs[10] = this->_ptrs.find(10)->second.compute(this->_links[10]);
    this->_inputs[11] = this->_ptrs.find(11)->second.compute(this->_links[11]);
}

void C4040::getResult()
{
    int i = 0;
    std::vector<nts::Tristate> outputs = convertToVector();

    while (i < 12) {
        if (outputs[i] == nts::TRUE) {
            outputs[i] = nts::FALSE;
        }
        else {
            outputs[i] = nts::TRUE;
            break;
        }
        i += 1;
    }
    updateMap(outputs);
}

void C4040::updateMap(std::vector<nts::Tristate> outputs)
{
    this->_outputs[9] = outputs[0];
    this->_outputs[7] = outputs[1];
    this->_outputs[6] = outputs[2];
    this->_outputs[5] = outputs[3];
    this->_outputs[3] = outputs[4];
    this->_outputs[2] = outputs[5];
    this->_outputs[4] = outputs[6];
    this->_outputs[13] = outputs[7];
    this->_outputs[12] = outputs[8];
    this->_outputs[14] = outputs[9];
    this->_outputs[15] = outputs[10];
    this->_outputs[1] = outputs[11];
}

std::vector<nts::Tristate> C4040::convertToVector()
{
    std::vector<nts::Tristate> outputs;

    outputs.push_back(this->_outputs[9]);
    outputs.push_back(this->_outputs[7]);
    outputs.push_back(this->_outputs[6]);
    outputs.push_back(this->_outputs[5]);
    outputs.push_back(this->_outputs[3]);
    outputs.push_back(this->_outputs[2]);
    outputs.push_back(this->_outputs[4]);
    outputs.push_back(this->_outputs[13]);
    outputs.push_back(this->_outputs[12]);
    outputs.push_back(this->_outputs[14]);
    outputs.push_back(this->_outputs[15]);
    outputs.push_back(this->_outputs[1]);

    return (outputs);
}

void C4040::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    this->_links[pin] = otherPin;
    this->_ptrs.insert({pin, other});
}

void C4040::dump() const
{
    std::cout << "Component C4040: " << this->_value << std::endl;
    std::cout << "Inputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> link : this->_inputs) {
        std::cout << "\t" << link.first << ": " << link.second << std::endl;
    }
    std::cout << "Outputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> output : this->_outputs) {
        std::cout << "\t" << output.first << ": " << output.second << std::endl;
    }
}

std::unordered_map<size_t, nts::Tristate> &C4040::getInputs()
{
    return (this->_inputs);
}

std::unordered_map<size_t, nts::Tristate> &C4040::getOutputs()
{
    return (this->_outputs);
}

C4040 &C4040::operator=(const C4040 &other)
{
    if (this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_inputs = other._inputs;
    this->_value = other._value;
    return(*this);
}

bool C4040::testLink(size_t pin)
{
    (void)pin;
    if (this->_links[10] == 0 || this->_links[11] == 0)
        return (false);
    return (true);
}