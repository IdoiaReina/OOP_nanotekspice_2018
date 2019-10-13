/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4081
*/

#ifndef C4081_HPP_
	#define C4081_HPP_

#include <unordered_map>
#include "../SimpleGate.hpp"

class C4081 : public SimpleGate {
	public:
		C4081(const std::string &value);
		C4081(const C4081 &other);
		~C4081();

		void dump() const final;
		C4081 &operator=(const C4081 &other);

	private:
		nts::Tristate getResult(nts::Tristate input1, nts::Tristate input2) final;
};

#endif /* !C4081_HPP_ */