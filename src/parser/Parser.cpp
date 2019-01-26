/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Parser class and its function
*/

#include <map>
#include <fstream>
#include "Component.hpp"
#include "Parser.hpp"

Parser::Parser::~Parser()
{
}

std::ifstream Parser::Parser::openFile(const std::string &filepath)
{
    std::ifstream file(filepath);

    return file;
}

std::map<std::string, Component::ComponentSetting> Parser::Parser::ParseFile(const std::string &filepath)
{
    std::map<std::string, Component::ComponentSetting> ret;
    std::ifstream file = Parser::Parser::openFile(filepath);

    return ret;
}