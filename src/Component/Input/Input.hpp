/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Input
*/

#ifndef INPUT_HPP_
	#define INPUT_HPP_

#include "../IComponent.hpp"

class Input : public nts::IComponent {
	public:
		Input(const std::string &value);
        Input(const Input &other);
		~Input();

	    nts::Tristate compute(std::size_t pin = 1) override;
    	void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
		void dump() const override;
		bool testLink(size_t pin) override;
		Input &operator=(const Input &other);
		std::unordered_map<size_t, nts::Tristate> &getInputs() override;
		std::unordered_map<size_t, nts::Tristate> &getOutputs() override;

	protected:
		std::string _value;
		std::unordered_map<size_t, nts::Tristate> _fix;
		std::unordered_map<size_t, nts::Tristate> _outputs;
};

#endif /* !INPUT_HPP_ */