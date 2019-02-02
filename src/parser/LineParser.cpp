/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Contains all the function related to the parsing
*/

#include <map>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstddef>
#include "Component.hpp"
#include "Parser.hpp"
#include "Error.hpp"

Parser::LineParser::LineParser(const std::string &line) : _line(line)
{
}

Parser::LineParser::~LineParser()
{
}

const std::string &Parser::LineParser::GetLine() const
{
    return _line;
}

void Parser::LineParser::ClearLine()
{
    std::string newString;

    if (_line[0] == '\n')
        _line.erase(0);

    for (size_t i = 0; i < _line.size(); i++) {
        if ((SPACE(_line[i]) || TAB(_line[i])) && i + 1 == _line.size()) {
            break;
        } else if (!((SPACE(_line[i]) || TAB(_line[i])) && (SPACE(_line[i + 1]) || TAB(_line[i + 1])))) {
            newString.push_back(_line[i]);
        }
    }
    _line = newString;
}

void Parser::LineParser::RemoveComment()
{
    std::size_t pos = _line.rfind('#');

    if (pos != std::string::npos)
        _line.erase(pos);
}

Component::Type Parser::LineParser::GetType(const std::string &typeStr) const
{
    char types[Component::NUMBER_OF_TYPE][10] = {"input", "output", "clock", "true", "false",
    "4001", "4008", "4011", "4013", "4017", "4030", "4040", "4069", "4071",
    "4081", "4094", "4801", "2716"};

    for (unsigned int i = 0; i < Component::NUMBER_OF_TYPE; i++) {
        if (typeStr.compare(types[i]) == 0) {
            return Component::Type(i + 1);
        }
    }
    throw Error::Paser::FormatError("The given type doesn't exist", "GetTypes");
}

std::map<std::string, std::string> Parser::LineParser::SplitLineInTwo() const
{
    std::map<std::string, std::string> map;
    size_t pos = _line.find_first_of(' ');

    if (pos == std::string::npos)
        pos = _line.find_first_of('\t');

    if (pos == std::string::npos)
        throw Error::Paser::FormatError("Chipset line was incorect, needs a key and a value", "SplitLineInTwo");

    map["value"] = _line.substr(pos + 1);
    map["key"] = _line.substr(0, pos);
    return map;
}

Component::ComponentSetting Parser::LineParser::GetInfoComponent() const
{
    Component::ComponentSetting newInfo;
    std::map<std::string, std::string> lineInfo;
    
    lineInfo = SplitLineInTwo();

    newInfo.value = lineInfo["value"];
    newInfo.type = GetType(lineInfo["key"]);
    return newInfo;
}

Component::Link Parser::LineParser::GetLink() const
{
    std::map<std::string, std::string> lineInfo = SplitLineInTwo();
    Component::Link link;
    size_t pos = 0;

    // Get the source
    pos = lineInfo["key"].find_first_of(':');
    if (pos == std::string::npos)
        throw Error::Paser::FormatError("Links source must be separated by ':'", "GetLinks");
    link.OriginName = lineInfo["key"].substr(0, pos);
    link.OriginPin = std::atoi(lineInfo["key"].substr(pos + 1).c_str());

    // Get the destination
    pos = lineInfo["value"].find_first_of(':');
    if (pos == std::string::npos)
        throw Error::Paser::FormatError("Links destination must be separated by ':'", "GetLinks");
    link.DestinationName = lineInfo["value"].substr(0, pos);
    link.DestinationPin = std::atoi(lineInfo["value"].substr(pos + 1).c_str());
    return link;
}