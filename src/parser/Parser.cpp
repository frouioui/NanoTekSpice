/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Parser class and its function
*/

#include <map>
#include <fstream>
#include <algorithm>
#include <string>
#include <iostream>
#include "Component.hpp"
#include "Parser.hpp"

Parser::Parser::~Parser()
{
}

std::ifstream Parser::Parser::OpenFile(const std::string &filepath)
{
    std::ifstream file(filepath);

    if (file.is_open() == false)
        throw FileError("The file cannot be opened", "OpenFile");
    return file;
}

const std::string Parser::Parser::ClearLine(std::string &line)
{
   std::string result;

   for (size_t i = 0; i < line.size(); i++) {
        if ((SPACE(line[i]) || TAB(line[i])) && i + 1 == line.length()) {
            break;
        } else if (!((line[i] == ' ' || line[i] == '\t') && (line[i + 1] == ' ' || line[i + 1] == '\t'))) {
            result += line[i];
        }
   }
    return result;
}

std::map<std::string, Component::ComponentSetting> Parser::Parser::ParseFile(const std::string &filepath)
{
    std::map<std::string, Component::ComponentSetting> ret;
    std::ifstream file = Parser::Parser::OpenFile(filepath);
    std::string line;

    while (file.eof() == false) {
        std::getline(file, line);
    }
    return ret;
}