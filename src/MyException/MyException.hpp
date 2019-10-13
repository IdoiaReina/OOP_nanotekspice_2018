/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** MyException
*/

#ifndef MYEXCEPTION_HPP_
	#define MYEXCEPTION_HPP_

#include <exception>
#include <iostream>

class MyException : public std::exception {
	public:
    MyException(const std::string &msg) noexcept;
    ~MyException();

    const char *what() const noexcept override { return _msg.data(); }
    void displayError() noexcept;

    protected:
    std::string _msg;
};

#endif /* !MyException_HPP_ */