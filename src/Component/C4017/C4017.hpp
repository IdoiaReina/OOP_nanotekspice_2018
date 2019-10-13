/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4017
*/

#ifndef C4017_HPP_
	#define C4017_HPP_

#include <vector>
#include "../IComponent.hpp"

class C4017 : public nts::IComponent {
	public:
		C4017(const std::string &value);
		C4017(const C4017 &other);
		~C4017();

		nts::Tristate compute(std::size_t pin = 1) final;
    	void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
		void dump() const final;
		bool testLink(size_t pin) final;
		C4017 &operator=(const C4017 &other);
		std::unordered_map<size_t, nts::Tristate> &getInputs() final;
		std::unordered_map<size_t, nts::Tristate> &getOutputs() final;

	private:
		std::string _value;
		std::unordered_map<size_t, nts::Tristate> _inputs;
		std::unordered_map<size_t, nts::Tristate> _outputs;
		std::unordered_map<size_t, size_t> _links;
		std::unordered_map<size_t, nts::IComponent &> _ptrs;
		std::unordered_map<size_t, bool> _isUsed;
		void getResult();
		void setAllInputs();
		void setAllOutputs(nts::Tristate state);
		std::vector<nts::Tristate> convertToVector();
		void updateMap(std::vector<nts::Tristate> outputs);
		void setAllIsUsed(bool state);
		bool checkSameSimulation(size_t pin);
};

#endif /* !C4017_HPP_ */