/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Component
*/

#include "Component.hpp"

Component::Component() : _map()
{
    _map["4001"] = &Component::create4001;
    _map["4011"] = &Component::create4011;
    _map["4030"] = &Component::create4030;
    _map["4071"] = &Component::create4071;
    _map["4081"] = &Component::create4081;
    _map["input"] = &Component::createInput;
    _map["output"] = &Component::createOutput;
    _map["clock"] = &Component::createClock;
    _map["false"] = &Component::createFalse;
    _map["true"] = &Component::createTrue;
    _map["4008"] = &Component::create4008;
    _map["4040"] = &Component::create4040;
    _map["4069"] = &Component::create4069;
    _map["4013"] = &Component::create4013;
    _map["4514"] = &Component::create4514;
    _map["4017"] = &Component::create4017;
    _map["4094"] = &Component::create4094;
}

Component::~Component()
{
}

/* SimpleGate Components */

std::unique_ptr<nts::IComponent> Component::create4001(const std::string &value) const noexcept
{
    std::unique_ptr<C4001> ptr(new C4001(value));
    return (ptr);
}

std::unique_ptr<nts::IComponent> Component::create4011(const std::string &value) const noexcept
{
    std::unique_ptr<C4011> ptr(new C4011(value));
    return (ptr);
}

std::unique_ptr<nts::IComponent> Component::create4030(const std::string &value) const noexcept
{
    std::unique_ptr<C4030> ptr(new C4030(value));
    return (ptr);
}

std::unique_ptr<nts::IComponent> Component::create4071(const std::string &value) const noexcept
{
    std::unique_ptr<C4071> ptr(new C4071(value));
    return (ptr);
}

std::unique_ptr<nts::IComponent> Component::create4081(const std::string &value) const noexcept
{
    std::unique_ptr<C4081> ptr(new C4081(value));
    return (ptr);
}

/* Input Components */

std::unique_ptr<nts::IComponent> Component::createInput(const std::string &value) const noexcept
{
    std::unique_ptr<Input> ptr(new Input(value));
    return (ptr);
}

std::unique_ptr<nts::IComponent> Component::createOutput(const std::string &value) const noexcept
{
    std::unique_ptr<Output> ptr(new Output(value));
    return (ptr);
}

std::unique_ptr<nts::IComponent> Component::createClock(const std::string &value) const noexcept
{
    std::unique_ptr<Clock> ptr(new Clock(value));
    return (ptr);
}

std::unique_ptr<nts::IComponent> Component::createFalse(const std::string &value) const noexcept
{
    std::unique_ptr<False> ptr(new False(value));
    return (ptr);
}

std::unique_ptr<nts::IComponent> Component::createTrue(const std::string &value) const noexcept
{
    std::unique_ptr<True> ptr(new True(value));
    return (ptr);
}

std::unique_ptr<nts::IComponent> Component::create4008(const std::string &value) const noexcept
{
    std::unique_ptr<C4008> ptr(new C4008(value));
    return (ptr);
}

std::unique_ptr<nts::IComponent> Component::create4040(const std::string &value) const noexcept{
    std::unique_ptr<C4040> ptr(new C4040(value));
    return (ptr);
}

std::unique_ptr<nts::IComponent> Component::create4069(const std::string &value) const noexcept
{
    std::unique_ptr<C4069> ptr(new C4069(value));
    return (ptr);
}

std::unique_ptr<nts::IComponent> Component::create4013(const std::string &value) const noexcept
{
    std::unique_ptr<C4013> ptr(new C4013(value));
    return (ptr);
}

std::unique_ptr<nts::IComponent> Component::create4514(const std::string &value) const noexcept
{
    std::unique_ptr<C4514> ptr(new C4514(value));
    return (ptr);
}

std::unique_ptr<nts::IComponent> Component::create4017(const std::string &value) const noexcept
{
    std::unique_ptr<C4017> ptr(new C4017(value));
    return (ptr);
}

std::unique_ptr<nts::IComponent> Component::create4094(const std::string &value) const noexcept
{
    std::unique_ptr<C4094> ptr(new C4094(value));
    return (ptr);
}

std::unique_ptr<nts::IComponent> Component::createComponent(const std::string &type, const std::string &value)
{
    return ((this->*_map[type])(value));
}