/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** False
*/

#ifndef FALSE_HPP_
	#define FALSE_HPP_

#include "../Input.hpp"

class False : public Input {
	public:
		False(const std::string &value);
        False(const False &other);
		~False();

		void dump() const final;
		False &operator=(const False &other);
};

#endif /* !FALSE_HPP_ */