/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4514
*/

#ifndef C4514_HPP_
	#define C4514_HPP_

#include <unordered_map>
#include "../IComponent.hpp"

class C4514 : public nts::IComponent {
	public:
		C4514(const std::string &value);
		C4514(const C4514 &other);
		~C4514();

		nts::Tristate compute(std::size_t pin = 1) override;
    	void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
		void dump() const override;
		bool testLink(size_t pin) final;
		void getState();
		C4514 &operator=(const C4514 &other);
		std::unordered_map<size_t, nts::Tristate> &getInputs() final;
		std::unordered_map<size_t, nts::Tristate> &getOutputs() final;

	private:
		std::string _value;
		std::unordered_map<size_t, nts::Tristate> _inputs;
		std::unordered_map<size_t, nts::Tristate> _outputs;
		std::unordered_map<size_t, size_t> _links;
		std::unordered_map<size_t, nts::IComponent &> _ptrs;
		void flipFlopGate(nts::Tristate input1, nts::Tristate input2, nts::Tristate &output1, nts::Tristate &output2);
		void setAllOutputs(nts::Tristate state);
		void setAllInputs();
		std::unordered_map<std::string, size_t> createMap();
		std::string getOrder();
};

#endif /* !C4514_HPP_ */