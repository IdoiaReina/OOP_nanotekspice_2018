/*
** EPITECH PROJECT, 2019
** bs_nanotekspice
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>
#include <unordered_map>

namespace nts
{
    enum Tristate
    {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent
    {
        public:
            virtual ~IComponent() = default;

        public:
            virtual nts::Tristate compute(std::size_t pin = 1) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual std::unordered_map<size_t, nts::Tristate> &getInputs() = 0;
		    virtual std::unordered_map<size_t, nts::Tristate> &getOutputs() = 0;
            virtual bool testLink(size_t pin) = 0;
    };
} // namespace nts

#endif /* !ICOMPONENT_HPP_ */
