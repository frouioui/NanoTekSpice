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
        throw Error::Paser::FileError("The file cannot be opened", "OpenFile");
    return file;
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

void Parser::Parser::ReadFile()
{
    std::ifstream file = OpenFile();

    while (file.eof() == false) {
        std::string line;
        getline(file, line);
        LineParser lineParser(line);
        if (lineParser.IsUseless() == true)
            continue;
        lineParser.RemoveComment();
        lineParser.ClearLine();
        _lines.push_back(lineParser.GetLine());
    }
}

void Parser::Parser::HandleChipsets(unsigned int &i, std::vector<Component::ComponentSetting> &ret)
{
    i++;
    while (i < _lines.size() && _lines[i + 1].compare(".links:") != 0) {
        LineParser lineParser(_lines[i]);
        Component::ComponentSetting info;
        info = lineParser.GetInfoComponent();
        ret.push_back(info);
        i++;
    }
}

void Parser::Parser::HandleLinks(unsigned int &i, std::vector<Component::Link> &allLinks)
{
    i++;
    while (i < _lines.size() && _lines[i + 1].compare(".chipsets:") != 0) {
        LineParser lineParser(_lines[i]);
        Component::Link link = lineParser.GetLink();
        allLinks.push_back(link);
        i++;
    }
}

const std::vector<Component::ComponentSetting> Parser::Parser::Parse()
{
    std::vector<Component::ComponentSetting> ret;
    std::vector<Component::Link> allLinks;
    Checker check;
    bool chipsetKeyword = false;
    bool linksKeyword = false;

    ReadFile();
    for (unsigned int i = 0; i < _lines.size(); i++) {
        if (_lines[i].compare(".chipsets:") == 0) {
            HandleChipsets(i, ret);
            chipsetKeyword = true;
        } else if (_lines[i].compare(".links:") == 0) {
            HandleLinks(i, allLinks);
            linksKeyword = true;
        }
    }
    if (chipsetKeyword == false || linksKeyword == false)
        throw Error::Paser::FormatError("Must have a .chipsets and a .links in your file", "Parse");
    AddLinksToChipsetInfo(allLinks, ret);
    check.Check(ret);
    return ret;
}