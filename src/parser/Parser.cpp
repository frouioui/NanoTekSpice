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

bool Parser::Parser::IsLineUseless(const std::string &line)
{
    unsigned int i = 0;

    while (i < line.size() && SPACE_OR_TAB(line[i])) {
        i++;
    }
    return line[i] == '#' || i == line.size();
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

    if (line[0] == '\n')
        line.erase(0);
    for (size_t i = 0; i < line.size(); i++) {
        if ((SPACE(line[i]) || TAB(line[i])) && i + 1 == line.length()) {
            break;
        } else if (!((line[i] == ' ' || line[i] == '\t') && (line[i + 1] == ' ' || line[i + 1] == '\t'))) {
            result += line[i];
        }
    }
    return result;
}

std::map<std::string, std::string> Parser::Parser::ChipsetHandler(std::ifstream &file)
{
    std::map<std::string, std::string> chipsetInfo;
    std::string line;

    std::getline(file, line);
    while (file.eof() == false) {
        std::getline(file, line);

        if (IsLineUseless(line) == true)
            continue;
        line = RemoveComment(line);
        line = ClearLine(line);
        std::cout << line << std::endl;
    }
    return chipsetInfo;
}

std::map<std::string, Component::ComponentSetting> Parser::Parser::ParseFile(const std::string &filepath)
{
    std::map<std::string, Component::ComponentSetting> ret;
    std::map<std::string, std::string> chipsetInfo;
    std::ifstream file = Parser::Parser::OpenFile(filepath);

    while (file.eof() == false) {
        std::string line;
        std::getline(file, line);

        if (IsLineUseless(line) == true)
            continue;
        line = RemoveComment(line);
        line = ClearLine(line);

        if (line.compare(".chipsets:") == 0) {
            chipsetInfo = ChipsetHandler(file);
        }
    }
    return ret;
}