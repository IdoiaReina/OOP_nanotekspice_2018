/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** SimpleGate
*/

#ifndef SIMPLEGATE_HPP_
	#define SIMPLEGATE_HPP_

#include <unordered_map>
#include "../IComponent.hpp"

class SimpleGate : public nts::IComponent {
	public:
		SimpleGate(const std::string &value);
		SimpleGate(const SimpleGate &other);
		~SimpleGate();

        nts::Tristate compute(std::size_t pin = 1) final;
    	void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
		void dump() const override;
		bool testLink(size_t pin) final;
		SimpleGate &operator=(const SimpleGate &other);
		std::unordered_map<size_t, nts::Tristate> &getInputs() final;
		std::unordered_map<size_t, nts::Tristate> &getOutputs() final;

	protected:
		std::string _value;
		std::unordered_map<size_t, nts::Tristate> _inputs;
		std::unordered_map<size_t, nts::Tristate> _outputs;
		std::unordered_map<size_t, size_t> _links;
		std::unordered_map<size_t, nts::IComponent &> _ptrs;
		virtual nts::Tristate getResult(nts::Tristate input1, nts::Tristate input2);
		void setAllInputs(size_t pin);
};

#endif /* !SIMPLEGATE_HPP_ */