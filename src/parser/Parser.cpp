/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Parser class and its function
*/

#include <map>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstddef>
#include "Component.hpp"
#include "Parser.hpp"

std::ifstream Parser::Parser::OpenFile(const std::string &filepath)
{
    std::ifstream file(filepath);

    if (file.is_open() == false)
        throw FileError("The file cannot be opened", "OpenFile");
    return file;
}

bool Parser::Parser::IsLineComment(const std::string &line)
{
    unsigned int i = 0;

    while (i < line.size() && SPACE_OR_TAB(line[i])) {
        i++;
    }
    return line[i] == '#';
}

const std::string Parser::Parser::RemoveComment(std::string &line)
{
    std::size_t pos = line.rfind('#');

    if (pos == std::string::npos)
        return line;
    line.erase(pos);
    return line;
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

        if (IsLineComment(line) == true) {
            continue;
        }
    }
    return ret;
}