/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
	#define OUTPUT_HPP_

#include "../Input.hpp"

class Output : public Input {
	public:
		Output(const std::string &value);
        Output(const Output &other);
		~Output();

        nts::Tristate compute(std::size_t pin = 1) final;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
		void dump() const final;
		bool testLink(size_t pin) final;
		Output &operator=(const Output &other);
		std::unordered_map<size_t, nts::Tristate> &getInputs() final;
		std::unordered_map<size_t, nts::Tristate> &getOutputs() final;

    private:
        std::unordered_map<size_t, size_t> _links;
		std::unordered_map<size_t, nts::IComponent &> _ptrs;
};

#endif /* !OUTPUT_HPP_ */
