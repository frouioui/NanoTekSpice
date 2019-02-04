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
    char types[Component::NUMBER_OF_TYPE][10] = {"input", "output", "clock", "true", "false",
    "4001", "4008", "4011", "4013", "4017", "4030", "4040", "4069", "4071",
    "4081", "4094", "4801", "2716"};

    for (unsigned int i = 0; i < Component::NUMBER_OF_TYPE; i++) {
        if (type.compare(types[i]) == 0) {
            return Component::Type(i + 1);
        }
    }
    throw FormatError("The given type doesn't exist", "GetTypes");
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
        if (pos == std::string::npos)
            throw FormatError("Links must be two key/value separated by a space or tab", "GetLinks");
        std::string source = line.substr(0, pos);
        std::string destination = line.substr(pos + 1);

        // Split the substrings, fill the new Link struct
        Component::Link newLink;
        pos = source.find_first_of(':');
        if (pos == std::string::npos)
            throw FormatError("Links destination must be separated by ':'", "GetLinks");
        newLink.originName = source.substr(0, pos);
        newLink.originPin = std::atoi(source.substr(pos + 1).c_str());
        pos = destination.find_first_of(':');
        if (pos == std::string::npos)
            throw FormatError("Links destination must be separated by ':'", "GetLinks");
        newLink.destinationName = destination.substr(0, pos);
        newLink.destinationPin = std::atoi(destination.substr(pos + 1).c_str());
        links.push_back(newLink);
    }
    return links;
}

void Parser::Parser::AddLinksToChipsetInfo(const std::vector<Component::Link> &allLinks, std::vector<Component::ComponentSetting> &components)
{
    for (unsigned int j = 0; j < components.size(); j++) {
        for (unsigned int i = 0; i < allLinks.size(); i++) {
            if (allLinks.at(i).originName.compare(components.at(j).value.c_str()) == 0) {
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

// Create a new ComponentSetting struct with the given information
const Component::ComponentSetting Parser::Parser::CreateNewChipsetInfo(const std::string &key, const std::string &value)
{
    Component::ComponentSetting newInfo;

    newInfo.value = value;
    newInfo.type = GetType(key);
    return (newInfo);
}

// This function splits a line in two, the separator if ' ' or '\t'
std::map<std::string, std::string> Parser::Parser::SplitLineInTwo(const std::string &line)
{
    std::map<std::string, std::string> map;
    size_t pos = line.find_first_of(' ');

    if (pos == std::string::npos)
        pos = line.find_first_of('\t');
    if (pos == std::string::npos)
        throw FormatError("Chipset line was incorect, needs a key and a value", "SplitLineInTwo");
    map["value"] = line.substr(pos + 1);
    map["key"] = line.substr(0, pos);
    return map;
}

void Parser::Parser::CheckNames(const std::vector<Component::ComponentSetting> &chipsetInfo)
{
    for (unsigned int i = 0; i < chipsetInfo.size(); i++) {
        for (unsigned int j = 0; j < chipsetInfo.size(); j++) {
            if (j == i)
                continue;
            if (chipsetInfo.at(i).value == chipsetInfo.at(j).value)
                throw FormatError("Name appear twice on file", "CheckNames");
        }
    }
}

void Parser::Parser::CheckLinks(const std::vector<Component::ComponentSetting> &chipsetInfo)
{

}

void Parser::Parser::CheckType(const std::vector<Component::ComponentSetting> &chipsetInfo)
{
    for (unsigned int i = 0; i < chipsetInfo.size(); i++) {
        if (chipsetInfo.at(i).type == Component::NOT_SET)
            throw FormatError("The type a chipset is incorrect", "CheckType");
    }
}

// BeginParsing will parse the whole file from the ".chipsets:" to the end
// This function is called by the ParseFile function
std::vector<Component::ComponentSetting> Parser::Parser::BeginParsing(std::ifstream &file)
{
    bool correct = false;
    std::vector<Component::ComponentSetting> chipsetInfo;
    std::vector<Component::Link> allLinks;

    // Iterates from the .chipset to the end of the file
    while (file.eof() == false) {
        std::string line;
        std::getline(file, line);

        // Remove useless data on the line
        if (IsLineUseless(line) == true)
            continue;
        line = RemoveComment(line);
        line = ClearLine(line);

        // Once we reach the .links section, launch the links parser
        // and check the values once it is done
        if (line.compare(".links:") == 0) {
            correct = true;
            allLinks = GetLinks(file);
            AddLinksToChipsetInfo(allLinks, chipsetInfo);
            CheckLinks(chipsetInfo);
            break;
        } else {
            // Parse the current line and add it to the chipsetInfo array
            std::map<std::string, std::string> lineInfo = SplitLineInTwo(line);
            chipsetInfo.push_back(CreateNewChipsetInfo(lineInfo["key"], lineInfo["value"]));
        }
    }
    if (correct == false)
        throw FormatError("Must have a links section", "BeginParsing");
    return chipsetInfo;
}

// ParseFile will parse the given file
// And return and array of ComponentSetting
std::vector<Component::ComponentSetting> Parser::Parser::ParseFile(const std::string &filepath)
{
    bool correct = false;
    std::vector<Component::ComponentSetting> chipsetInfo;
    std::ifstream file = Parser::Parser::OpenFile(filepath);

    // This loop will iterate until the first section begins (".chipsets:")
    while (file.eof() == false) {
        std::string line;
        std::getline(file, line);

        // Remove useless data on the line
        if (IsLineUseless(line) == true)
            continue;
        line = RemoveComment(line);
        line = ClearLine(line);

        // Launch the main parsing loop
        if (line.compare(".chipsets:") == 0) {
            correct = true;
            chipsetInfo = BeginParsing(file);
            CheckNames(chipsetInfo);
            CheckType(chipsetInfo);
        }
    }
    // If there is no .chipsets section
    if (correct == false)
        throw FormatError("Must have a chipset section", "ParseFile");
    return chipsetInfo;
}