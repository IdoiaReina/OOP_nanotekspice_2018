/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4013
*/

#ifndef C4013_HPP_
	#define C4013_HPP_

#include <vector>
#include <unordered_map>
#include "../IComponent.hpp"

class C4013 : public nts::IComponent {
	public:
		C4013(const std::string &value);
		C4013(const C4013 &other);
		~C4013();

		nts::Tristate compute(std::size_t pin = 1) final;
    	void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
		void dump() const final;
		bool testLink(size_t pin) final;
		C4013 &operator=(const C4013 &other);
		std::unordered_map<size_t, nts::Tristate> &getInputs() final;
		std::unordered_map<size_t, nts::Tristate> &getOutputs() final;

	private:
		std::string _value;
		std::unordered_map<size_t, nts::Tristate> _inputs;
		std::unordered_map<size_t, nts::Tristate> _outputs;
		std::unordered_map<size_t, size_t> _links;
		std::unordered_map<size_t, nts::IComponent &> _ptrs;
		void getResult(nts::Tristate set, nts::Tristate reset, nts::Tristate data, nts::Tristate clock, size_t pin);
		void setOutputs(nts::Tristate state1, nts::Tristate state2, size_t pin);
		void setAllInputs(size_t pin);
};

#endif /* !C4013_HPP_ */