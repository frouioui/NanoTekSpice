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

Parser::Parser::Parser(const std::string &filename) : _filename(filename)
{
}

Parser::Parser::~Parser()
{
}

std::ifstream Parser::Parser::OpenFile() const
{
    std::ifstream file(_filename);

    if (file.is_open() == false)
        throw Error::Parser::FileError("The file cannot be opened", "OpenFile");
    return file;
}

void Parser::Parser::AddLinksToChipsetInfo(const std::vector<Component::Link> &allLinks, std::vector<Component::ComponentSetting> &components)
{
    for (unsigned int j = 0; j < components.size(); j++) {
        for (unsigned int i = 0; i < allLinks.size(); i++) {
            if (allLinks[i].originName == allLinks[i].destinationName &&
                allLinks[i].originPin == allLinks[i].destinationPin) {
                throw Error::Parser::FileError("A link cannot be linked to itself", "AddLinksToChipsetInfo");
            }
            if (allLinks[i].originName.compare(components[j].name.c_str()) == 0) {
                components[j].links.push_back(allLinks[i]);
            }
        }
    }
}

void Parser::Parser::ReadFile()
{
    std::ifstream file = OpenFile();

    while (file.eof() == false) {
        std::string line;
        getline(file, line);
        Checker checker(line);
        LineParser lineParser(line);
        if (checker.IsUseless() == true)
            continue;
        lineParser.RemoveComment();
        lineParser.ClearLine();
        _lines.push_back(lineParser.GetLine());
    }
}

void Parser::Parser::HandleChipsets(unsigned int &i, std::vector<Component::ComponentSetting> &ret)
{
    i++;
    while (i < _lines.size() && _lines[i].compare(".links:") != 0) {
        LineParser lineParser(_lines[i]);
        Component::ComponentSetting info;
        info = lineParser.GetInfoComponent();
        ret.push_back(info);
        if (_lines[i + 1].compare(".links:") == 0)
            break;
        else
            i++;
    }
}

void Parser::Parser::HandleLinks(unsigned int &i, std::vector<Component::Link> &allLinks)
{
    i++;
    while (i < _lines.size() && _lines[i].compare(".chipsets:") != 0) {
        LineParser lineParser(_lines[i]);
        Component::Link link = lineParser.GetLink();
        allLinks.push_back(link);
        if (_lines.size() > i + 1 && _lines[i + 1].compare(".chipsets:") == 0)
            break;
        else
            i++;
    }
}

const Parser::container_setting_t Parser::Parser::Parse()
{
    container_setting_t ret;
    container_link_t allLinks;
    bool chipsetKeyword = false;
    bool linksKeyword = false;

    ReadFile();
    for (unsigned int i = 0; i < _lines.size(); i++) {
        if (_lines[i].compare(".chipsets:") == 0) {
            HandleChipsets(i, ret);
            chipsetKeyword = true;
        } else if (_lines[i].compare(".links:") == 0) {
            HandleLinks(i, allLinks);
            Checker check(allLinks);
            check.CheckLinksMultiple();
            linksKeyword = true;
        }
    }
    if (chipsetKeyword == false || linksKeyword == false)
        throw Error::Parser::FormatError("Must have a .chipsets and a .links in your file", "Parse");
    AddLinksToChipsetInfo(allLinks, ret);
    Checker check(ret, allLinks);
    check.Check();
    return ret;
}