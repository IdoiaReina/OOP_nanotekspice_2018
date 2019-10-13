/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4094
*/

#ifndef C4094_HPP_
	#define C4094_HPP_

#include <unordered_map>
#include "../IComponent.hpp"

class C4094 : public nts::IComponent {
	public:
		C4094(const std::string &value);
		C4094(const C4094 &other);
		~C4094();

		nts::Tristate compute(std::size_t pin = 1) override;
    	void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
		void dump() const override;
		bool testLink(size_t pin) final;
		C4094 &operator=(const C4094 &other);
		std::unordered_map<size_t, nts::Tristate> &getInputs() final;
		std::unordered_map<size_t, nts::Tristate> &getOutputs() final;

	private:
		std::string _value;
		std::unordered_map<size_t, nts::Tristate> _inputs;
		std::unordered_map<size_t, nts::Tristate> _outputs;
		std::unordered_map<size_t, size_t> _links;
		std::unordered_map<size_t, nts::IComponent &> _ptrs;
		void getResult();
		void setAllInputs();
		void setAllParallelOutputs(nts::Tristate state);
		void setAllParallelOutputsCascading(nts::Tristate state);
};

#endif /* !C4094_HPP_ */