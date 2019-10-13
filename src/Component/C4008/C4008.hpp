/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4008
*/

#ifndef C4008_HPP_
	#define C4008_HPP_

#include "../IComponent.hpp"

class C4008 : public nts::IComponent {
	public:
		C4008(const std::string &value);
		C4008(const C4008 &other);
		~C4008();

		nts::Tristate compute(std::size_t pin = 1) final;
    	void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
		void dump() const final;
		bool testLink(size_t pin) final;
		C4008 &operator=(const C4008 &other);
		std::unordered_map<size_t, nts::Tristate> &getInputs() final;
		std::unordered_map<size_t, nts::Tristate> &getOutputs() final;

	private:
		std::string _value;
		std::unordered_map<size_t, nts::Tristate> _inputs;
		std::unordered_map<size_t, nts::Tristate> _outputs;
		std::unordered_map<size_t, size_t> _links;
		std::unordered_map<size_t, nts::IComponent &> _ptrs;
		nts::Tristate getResult(nts::Tristate input1, nts::Tristate input2, nts::Tristate input3);
		void setAllInputs(size_t pin);
};

#endif /* !C4008_HPP_ */