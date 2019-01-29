/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Parser class and its function
*/

// TODO: Documentation

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

Component::Type Parser::Parser::GetType(const std::string &type)
{
    if (type.compare("input") == 0)
        return Component::Type::INPUT;
    else if (type.compare("output") == 0)
        return Component::Type::OUTPUT;
    else if (type.compare("clock") == 0)
        return Component::Type::CLOCK;
    return Component::Type::NOT_SET;
}

const std::vector<Component::Link> Parser::Parser::GetLinks(std::ifstream &file)
{
    std::vector<Component::Link> links;

    while (file.eof() == false) {
        std::string line;
        std::getline(file, line);
        if (IsLineUseless(line) == true)
            continue;
        line = RemoveComment(line);
        line = ClearLine(line);

        // Split the string for the first time
        size_t pos = line.find_first_of(' ');
        if (pos == std::string::npos)
            pos = line.find_first_of('\t');
        std::string source = line.substr(0, pos);
        std::string destination = line.substr(pos + 1);

        // Split the substrings, fill the new Link struct
        Component::Link newLink;
        pos = source.find_first_of(':');
        newLink.OriginName = source.substr(0, pos);
        newLink.OriginPin = std::atoi(source.substr(pos + 1).c_str());
        pos = destination.find_first_of(':');
        newLink.DestinationName = destination.substr(0, pos);
        newLink.DestinationPin = std::atoi(destination.substr(pos + 1).c_str());
        links.push_back(newLink);
    }
    return links;
}

void Parser::Parser::AddLinksToChipsetInfo(const std::vector<Component::Link> &allLinks, std::vector<Component::ComponentSetting> &components)
{
    for (unsigned int j = 0; j < components.size(); j++) {
        for (unsigned int i = 0; i < allLinks.size(); i++) {
            if (allLinks.at(i).OriginName.compare(components.at(j).value.c_str()) == 0) {
                components.at(j).links.push_back(allLinks.at(i));
            }
        }
    }
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

const Component::ComponentSetting Parser::Parser::CreateNewChipsetInfo(const std::string &key, const std::string &value)
{
    Component::ComponentSetting newInfo;

    newInfo.value = value;
    newInfo.type = GetType(key);
    return (newInfo);
}

std::map<std::string, std::string> Parser::Parser::SplitLineInTwo(const std::string &line)
{
    std::map<std::string, std::string> map;
    size_t pos = line.find_first_of(' ');

    if (pos == std::string::npos) {
        pos = line.find_first_of('\t');
    }
    map["value"] = line.substr(pos + 1);
    map["key"] = line.substr(0, pos);
    return map;
}

std::vector<Component::ComponentSetting> Parser::Parser::BeginParsing(std::ifstream &file)
{
    std::vector<Component::ComponentSetting> chipsetInfo;
    std::vector<Component::Link> allLinks;

    while (file.eof() == false) {
        std::string line;
        std::getline(file, line);

        if (IsLineUseless(line) == true)
            continue;
        line = RemoveComment(line);
        line = ClearLine(line);

        if (line.compare(".links:") == 0) {
            allLinks = GetLinks(file);
            AddLinksToChipsetInfo(allLinks, chipsetInfo);
            // TODO: Verify each link
            break;
        }
        std::map<std::string, std::string> lineInfo = SplitLineInTwo(line);
        chipsetInfo.push_back(CreateNewChipsetInfo(lineInfo["key"], lineInfo["value"]));
    }
    return chipsetInfo;
}

std::vector<Component::ComponentSetting> Parser::Parser::ParseFile(const std::string &filepath)
{
    std::vector<Component::ComponentSetting> ret;
    std::ifstream file = Parser::Parser::OpenFile(filepath);

    while (file.eof() == false) {
        std::string line;
        std::getline(file, line);

        if (IsLineUseless(line) == true)
            continue;
        line = RemoveComment(line);
        line = ClearLine(line);

        if (line.compare(".chipsets:") == 0) {
            ret = BeginParsing(file);
        }
    }
    return ret;
}