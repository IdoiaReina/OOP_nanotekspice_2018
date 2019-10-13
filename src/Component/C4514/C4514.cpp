/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4514
*/

#include "C4514.hpp"

C4514::C4514(const std::string &value) : nts::IComponent(), _value(value), _inputs(6), _outputs(16)
{
    setAllOutputs(nts::UNDEFINED);
    this->_inputs[1] = nts::UNDEFINED;
    this->_inputs[2] = nts::UNDEFINED;
    this->_inputs[3] = nts::UNDEFINED;
    this->_inputs[21] = nts::UNDEFINED;
    this->_inputs[22] = nts::UNDEFINED;
    this->_inputs[23] = nts::UNDEFINED;
}

C4514::C4514(const C4514 &other) : nts::IComponent(), _value(other._value), _inputs(other._inputs), _outputs(other._outputs)
{
}

C4514::~C4514()
{
}

void C4514::setAllOutputs(nts::Tristate state)
{
    this->_outputs[4] = state;
    this->_outputs[5] = state;
    this->_outputs[6] = state;
    this->_outputs[7] = state;
    this->_outputs[8] = state;
    this->_outputs[9] = state;
    this->_outputs[10] = state;
    this->_outputs[11] = state;
    this->_outputs[13] = state;
    this->_outputs[14] = state;
    this->_outputs[15] = state;
    this->_outputs[16] = state;
    this->_outputs[17] = state;
    this->_outputs[18] = state;
    this->_outputs[19] = state;
    this->_outputs[20] = state;
}

nts::Tristate C4514::compute(std::size_t pin)
{
    setAllInputs();
    if (this->_inputs[22] == nts::TRUE)
        setAllOutputs(nts::FALSE);
    else if (this->_inputs[1] == nts::TRUE)
        getState();
    return (this->_outputs[pin]);
}

void C4514::setAllInputs()
{
    this->_inputs[1] = this->_ptrs.find(1)->second.compute(this->_links[1]);
    this->_inputs[2] = this->_ptrs.find(2)->second.compute(this->_links[2]);
    this->_inputs[3] = this->_ptrs.find(3)->second.compute(this->_links[3]);
    this->_inputs[21] = this->_ptrs.find(21)->second.compute(this->_links[21]);
    this->_inputs[22] = this->_ptrs.find(22)->second.compute(this->_links[22]);
}

std::unordered_map<std::string, size_t> C4514::createMap()
{
    std::unordered_map<std::string, size_t> map(16);

    map["0000"] = 11;
    map["0001"] = 9;
    map["0010"] = 10;
    map["0011"] = 8;
    map["0100"] = 7;
    map["0101"] = 6;
    map["0110"] = 5;
    map["0111"] = 4;
    map["1000"] = 18;
    map["1001"] = 17;
    map["1010"] = 20;
    map["1011"] = 19;
    map["1100"] = 14;
    map["1101"] = 13;
    map["1110"] = 16;
    map["1111"] = 15;

    return (map);
}

std::string C4514::getOrder()
{
    std::string order = "";

    if (this->_inputs[22] == nts::TRUE)
        order += "1";
    else
        order += "0";
    if (this->_inputs[21] == nts::TRUE)
        order += "1";
    else
        order += "0";
    if (this->_inputs[3] == nts::TRUE)
        order += "1";
    else
        order += "0";
    if (this->_inputs[2] == nts::TRUE)
        order += "1";
    else
        order += "0";
    return (order);
}

void C4514::getState()
{
    std::unordered_map<std::string, size_t> map = createMap();
    std::string order = getOrder();

    setAllOutputs(nts::FALSE);
    this->_outputs[map[order]] = nts::TRUE;
}

void C4514::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    this->_links[pin] = otherPin;
    this->_ptrs.insert({pin, other});
}

void C4514::dump() const
{
    std::cout << "Component C4514: " << this->_value << std::endl;
    std::cout << "Inputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> link : this->_inputs) {
        std::cout << "\t" << link.first << ": " << link.second << std::endl;
    }
    std::cout << "Outputs:" << std::endl;
    for (std::pair<size_t, nts::Tristate> output : this->_outputs) {
        std::cout << "\t" << output.first << ": " << output.second << std::endl;
    }
}

std::unordered_map<size_t, nts::Tristate> &C4514::getInputs()
{
    return (this->_inputs);
}

std::unordered_map<size_t, nts::Tristate> &C4514::getOutputs()
{
    return (this->_outputs);
}

C4514 &C4514::operator=(const C4514 &other)
{
    if (this == &other)
        return *this;
    this->_outputs = other._outputs;
    this->_inputs = other._inputs;
    this->_value = other._value;
    return(*this);
}

bool C4514::testLink(size_t pin)
{
    (void)pin;
    if (this->_links[1] == 0 || this->_links[2] == 0 || this->_links[3] == 0 || this->_links[21] == 0 || this->_links[22] == 0)
        return (false);
    return (true);
}