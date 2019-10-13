/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4040
*/

#ifndef C4040_HPP_
	#define C4040_HPP_

#include <vector>
#include <unordered_map>
#include "../IComponent.hpp"

class C4040 : public nts::IComponent {
	public:
		C4040(const std::string &value);
		C4040(const C4040 &other);
		~C4040();

		nts::Tristate compute(std::size_t pin = 1) final;
    	void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
		void dump() const final;
		bool testLink(size_t pin) final;
		nts::Tristate getState(size_t pin);
		C4040 &operator=(const C4040 &other);
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
		std::vector<nts::Tristate> convertToVector();
		void updateMap(std::vector<nts::Tristate> outputs);
		void setAllInputs();
		void setAllOutputs(nts::Tristate state);
		void setAllIsUsed(bool state);
		bool checkSameSimulation(size_t pin);
};

#endif /* !C4040_HPP_ */