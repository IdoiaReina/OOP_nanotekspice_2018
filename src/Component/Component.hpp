/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <iostream>
#include <memory>
#include <unordered_map>
#include "IComponent.hpp"
#include "SimpleGate/C4001/C4001.hpp"
#include "SimpleGate/C4011/C4011.hpp"
#include "SimpleGate/C4030/C4030.hpp"
#include "SimpleGate/C4071/C4071.hpp"
#include "SimpleGate/C4081/C4081.hpp"
#include "Input/Clock/Clock.hpp"
#include "Input/False/False.hpp"
#include "Input/True/True.hpp"
#include "Input/Output/Output.hpp"
#include "C4008/C4008.hpp"
#include "C4013/C4013.hpp"
#include "C4017/C4017.hpp"
#include "C4040/C4040.hpp"
#include "C4069/C4069.hpp"
#include "C4094/C4094.hpp"
#include "C4514/C4514.hpp"

class Component
{
  public:
    Component();
    ~Component();
    typedef std::unique_ptr<nts::IComponent> (Component::*create)(const std::string &) const;
    std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &value);

  private:
    std::unordered_map<std::string, create> _map;
    std::unique_ptr<nts::IComponent> create4001(const std::string &value) const noexcept;
    std::unique_ptr<nts::IComponent> create4011(const std::string &value) const noexcept;
    std::unique_ptr<nts::IComponent> create4030(const std::string &value) const noexcept;
    std::unique_ptr<nts::IComponent> create4071(const std::string &value) const noexcept;
    std::unique_ptr<nts::IComponent> create4081(const std::string &value) const noexcept;
    std::unique_ptr<nts::IComponent> createInput(const std::string &value) const noexcept;
    std::unique_ptr<nts::IComponent> createOutput(const std::string &value) const noexcept;
    std::unique_ptr<nts::IComponent> createClock(const std::string &value) const noexcept;
    std::unique_ptr<nts::IComponent> createFalse(const std::string &value) const noexcept;
    std::unique_ptr<nts::IComponent> createTrue(const std::string &value) const noexcept;
    std::unique_ptr<nts::IComponent> create4008(const std::string &value) const noexcept;
    std::unique_ptr<nts::IComponent> create4040(const std::string &value) const noexcept;
    std::unique_ptr<nts::IComponent> create4069(const std::string &value) const noexcept;
    std::unique_ptr<nts::IComponent> create4514(const std::string &value) const noexcept;
    std::unique_ptr<nts::IComponent> create4013(const std::string &value) const noexcept;
    std::unique_ptr<nts::IComponent> create4017(const std::string &value) const noexcept;
    std::unique_ptr<nts::IComponent> create4094(const std::string &value) const noexcept;
};

#endif /* !COMPONENT_HPP_ */