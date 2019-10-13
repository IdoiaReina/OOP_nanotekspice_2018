/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4017
*/

#include "C4017.hpp"

C4017::C4017(const std::string &value) : nts::IComponent(), _value(value), _inputs(3), _outputs(11), _links(3), _ptrs(3), _isUsed(11)
{
    setAllOutputs(nts::FALSE);
    this->_outputs[3] = nts::TRUE;
    this->_inputs[13] = nts::UNDEFINED;
    this->_inputs[14] = nts::UNDEFINED;
    this->_inputs[15] = nts::UNDEFINED;
}

C4017::C4017(const C4017 &other) : nts::IComponent(), _value(other._value), _inputs(other._inputs), _outputs(other._outputs), _links(other._links), _ptrs(other._ptrs)
{
}

C4017::~C4017()
{
}

void C4017::setAllOutputs(nts::Tristate state)
{
    this->_outputs[1] = state;
    this->_outputs[2] = state;
    this->_outputs[3] = state;
    this->_outputs[4] = state;
    this->_outputs[5] = state;
    this->_outputs[6] = state;
    this->_outputs[7] = state;
    this->_outputs[9] = state;
    this->_outputs[10] = state;
    this->_outputs[11] = state;
    this->_outputs[12] = state;
}

void C4017::setAllIsUsed(bool state)
{
    this->_isUsed[1] = state;
    this->_isUsed[2] = state;
    this->_isUsed[3] = state;
    this->_isUsed[4] = state;
    this->_isUsed[5] = state;
    this->_isUsed[6] = state;
    this->_isUsed[7] = state;
    this->_isUsed[9] = state;
    this->_isUsed[10] = state;
    this->_isUsed[11] = state;
    this->_isUsed[12] = state;
}

nts::Tristate C4017::compute(std::size_t pin)
{
    if (checkSameSimulation(pin))
        return (this->_outputs[pin]);
    setAllInputs();
    if (this->_inputs[15] == nts::TRUE) {
        setAllOutputs(nts::FALSE);
        this->_outputs[3] = nts::TRUE;
        this->_outputs[12] = nts::TRUE;
    }
    else if (this->_inputs[13] != nts::UNDEFINED && this->_inputs[14] != nts::UNDEFINED && this->_inputs[13] != this->_inputs[14]) {
        getResult();
    }
    return (this->_outputs[pin]);
}

bool C4017::checkSameSimulation(size_t pin)
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

void C4017::getResult()
{
    size_t highPin;
    std::vector<nts::Tristate> outputs = convertToVector();

    for (int i = 0; i < 10; i++) {
        if (outputs[i] == nts::TRUE) {
            outputs[i] = nts::FALSE;
            if (i == 9)
                outputs[0] = nts::TRUE;
            else
                outputs[i + 1] = nts::TRUE;
            highPin = i;
            break;
        }
    }
    if (highPin < 5)
        outputs[10] = nts::TRUE;
    else
        outputs[10] = nts::FALSE;
    updateMap(outputs);
}

void C4017::updateMap(std::vector<nts::Tristate> outputs)
{
    this->_outputs[3] = outputs[0];
    this->_outputs[2] = outputs[1];
    this->_outputs[4] = outputs[2];
    this->_outputs[7] = outputs[3];
    this->_outputs[10] = outputs[4];
    this->_outputs[1] = outputs[5];
    this->_outputs[5] = outputs[6];
    this->_outputs[6] = outputs[7];
    this->_outputs[9] = outputs[8];
    this->_outputs[11] = outputs[9];
    this->_outputs[12] = outputs[10];
}

std::vector<nts::Tristate> C4017::convertToVector()
{
    std::vector<nts::Tristate> outputs;

    outputs.push_back(this->_outputs[3]);
    outputs.push_back(this->_outputs[2]);
    outputs.push_back(this->_outputs[4]);
    outputs.push_back(this->_outputs[7]);
    outputs.push_back(this->_outputs[10]);
    outputs.push_back(this->_outputs[1]);
    outputs.push_back(this->_outputs[5]);
    outputs.push_back(this->_outputs[6]);
    outputs.push_back(this->_outputs[9]);
    outputs.push_back(this->_outputs[11]);
    outputs.push_back(this->_outputs[12]);

    return (outputs);
}

void C4017::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    this->_links[pin] = otherPin;
    this->_ptrs.insert({pin, other});
}

void C4017::setAllInputs()
{
    this->_inputs[13] = this->_ptrs.find(13)->second.compute(this->_links[13]);
    this->_inputs[14] = this->_ptrs.find(14)->second.compute(this->_links[14]);
    this->_inputs[15] = this->_ptrs.find(15)->second.compute(this->_links[15]);
}

void C4017::dump() const
{
    std::cout << "Component C4017: " << this->_value << std::endl;
    std::cout << "Inputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> link : this->_inputs) {
        std::cout << "\t" << link.first << ": " << link.second << std::endl;
    }
    std::cout << "Outputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> output : this->_outputs) {
        std::cout << "\t" << output.first << ": " << output.second << std::endl;
    }
}

std::unordered_map<size_t, nts::Tristate> &C4017::getInputs()
{
    return (this->_inputs);
}

std::unordered_map<size_t, nts::Tristate> &C4017::getOutputs()
{
    return (this->_outputs);
}

C4017 &C4017::operator=(const C4017 &other)
{
    if (this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_inputs = other._inputs;
    this->_value = other._value;
    return(*this);
}

bool C4017::testLink(size_t pin)
{
    (void)pin;
    if (this->_links[13] == 0 || this->_links[14] == 0 || this->_links[15] == 0)
        return (false);
    return (true);
}