/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** MyException
*/

#include "MyException.hpp"

MyException::MyException(const std::string &msg) noexcept : _msg(msg)
{
}

MyException::~MyException()
{
}

void MyException::displayError() noexcept
{
    std::cerr << "Error: " << _msg << std::endl;
}