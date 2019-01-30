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
#include "Error.hpp"

std::ifstream Parser::Parser::OpenFile(const std::string &filepath)
{
    std::ifstream file(filepath);

    if (file.is_open() == false)
        throw Error::Paser::FileError("The file cannot be opened", "OpenFile");
    return file;
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

        // TODO: put this in the new getlink function ---->

        // Split the string for the first time
        size_t pos = line.find_first_of(' ');
        if (pos == std::string::npos)
            pos = line.find_first_of('\t');
        if (pos == std::string::npos)
            throw Error::Paser::FormatError("Links must be two key/value separated by a space or tab", "GetLinks");
        std::string source = line.substr(0, pos);
        std::string destination = line.substr(pos + 1);

        // Split the substrings, fill the new Link struct
        Component::Link newLink;
        pos = source.find_first_of(':');
        if (pos == std::string::npos)
            throw Error::Paser::FormatError("Links destination must be separated by ':'", "GetLinks");
        newLink.OriginName = source.substr(0, pos);
        newLink.OriginPin = std::atoi(source.substr(pos + 1).c_str());
        pos = destination.find_first_of(':');
        if (pos == std::string::npos)
            throw Error::Paser::FormatError("Links destination must be separated by ':'", "GetLinks");
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

void Parser::Parser::CheckNames(const std::vector<Component::ComponentSetting> &chipsetInfo)
{
    for (unsigned int i = 0; i < chipsetInfo.size(); i++) {
        for (unsigned int j = 0; j < chipsetInfo.size(); j++) {
            if (j == i)
                continue;
            if (chipsetInfo.at(i).value == chipsetInfo.at(j).value)
                throw Error::Paser::FormatError("Name appear twice on file", "CheckNames");
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
            throw Error::Paser::FormatError("The type a chipset is incorrect", "CheckType");
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
        throw Error::Paser::FormatError("Must have a links section", "BeginParsing");
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
        throw Error::Paser::FormatError("Must have a chipset section", "ParseFile");
    return chipsetInfo;
}