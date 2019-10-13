/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** C4071
*/

#ifndef C4071_HPP_
	#define C4071_HPP_

#include <unordered_map>
#include "../SimpleGate.hpp"

class C4071 : public SimpleGate {
	public:
		C4071(const std::string &value);
		C4071(const C4071 &other);
		~C4071();

		void dump() const final;
		C4071 &operator=(const C4071 &other);

	private:
		nts::Tristate getResult(nts::Tristate input1, nts::Tristate input2) final;
};

#endif /* !C4071_HPP_ */