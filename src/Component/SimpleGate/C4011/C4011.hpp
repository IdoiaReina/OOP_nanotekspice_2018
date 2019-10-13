/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4011
*/

#ifndef C4011_HPP_
	#define C4011_HPP_

#include <unordered_map>
#include "../SimpleGate.hpp"

class C4011 : public SimpleGate {
	public:
		C4011(const std::string &value);
		C4011(const C4011 &other);
		~C4011();

		void dump() const final;
		C4011 &operator=(const C4011 &other);

	private:
		nts::Tristate getResult(nts::Tristate input1, nts::Tristate input2) final;
};

#endif /* !C4011_HPP_ */