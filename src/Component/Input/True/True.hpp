/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** True
*/

#ifndef TRUE_HPP_
	#define TRUE_HPP_

#include "../Input.hpp"

class True : public Input {
	public:
		True(const std::string &value);
        True(const True &other);
		~True();

		void dump() const final;
		True &operator=(const True &other);
};

#endif /* !TRUE_HPP_ */
