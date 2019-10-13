/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4001
*/

#ifndef C4001_HPP_
	#define C4001_HPP_

#include <unordered_map>
#include "../SimpleGate.hpp"

class C4001 : public SimpleGate {
	public:
		C4001(const std::string &value);
		C4001(const C4001 &other);
		~C4001();

		void dump() const final;
		C4001 &operator=(const C4001 &other);

	private:
		nts::Tristate getResult(nts::Tristate input1, nts::Tristate input2) final;
};

#endif /* !C4001_HPP_ */