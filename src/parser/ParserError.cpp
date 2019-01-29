/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** File containing all the error for the parsing namespace and class
*/

#include <string>
#include "Parser.hpp"

Parser::Error::Error(const std::string &message, const std::string &where) : _where(where), _message(message)
{
}

const std::string &Parser::Error::where() const
{
    return _where;
}

const char *Parser::Error::what() const noexcept
{
    return _message.c_str();
}