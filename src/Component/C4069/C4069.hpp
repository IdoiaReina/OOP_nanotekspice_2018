/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4069
*/

#ifndef C4069_HPP_
	#define C4069_HPP_

#include <unordered_map>
#include "../IComponent.hpp"

class C4069 : public nts::IComponent {
	public:
		C4069(const std::string &value);
		C4069(const C4069 &other);
		~C4069();

        nts::Tristate compute(std::size_t pin = 1) final;
    	void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
		void dump() const final;
		bool testLink(size_t pin) final;
		C4069 &operator=(const C4069 &other);
		std::unordered_map<size_t, nts::Tristate> &getInputs() final;
		std::unordered_map<size_t, nts::Tristate> &getOutputs() final;

	protected:
		std::string _value;
		std::unordered_map<size_t, nts::Tristate> _inputs;
		std::unordered_map<size_t, nts::Tristate> _outputs;
		std::unordered_map<size_t, size_t> _links;
		std::unordered_map<size_t, nts::IComponent &> _ptrs;
		nts::Tristate getResult(nts::Tristate input);
		void setAllInputs(size_t pin);
};

#endif /* !C4069_HPP_ */