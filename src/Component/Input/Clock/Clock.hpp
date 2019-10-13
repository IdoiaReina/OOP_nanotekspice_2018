/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
	#define CLOCK_HPP_

#include "../Input.hpp"

class Clock : public Input {
	public:
		Clock(const std::string &value);
        Clock(const Clock &other);
		~Clock();

		void dump() const final;
		Clock &operator=(const Clock &other);
};

#endif /* !CLOCK_HPP_ */
