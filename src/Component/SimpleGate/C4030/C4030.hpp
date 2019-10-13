/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4030
*/

#ifndef C4030_HPP_
	#define C4030_HPP_

#include <unordered_map>
#include "../SimpleGate.hpp"

class C4030 : public SimpleGate {
	public:
		C4030(const std::string &value);
		C4030(const C4030 &other);
		~C4030();

		void dump() const final;
		C4030 &operator=(const C4030 &other);

	private:
		nts::Tristate getResult(nts::Tristate input1, nts::Tristate input2) final;
};

#endif /* !C4030_HPP_ */