/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Check the various error
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

Parser::Checker::Checker(const container_setting_t &chipsetInfo, const container_link_t &allLinks) : _chipsetInfo(chipsetInfo), _allLinks(allLinks)
{
}

Parser::Checker::Checker(const container_setting_t &chipsetInfo) : _chipsetInfo(chipsetInfo)
{
}

Parser::Checker::Checker(const container_link_t &allLinks) : _allLinks(allLinks)
{
}

Parser::Checker::Checker(const std::string &line) : _line(line)
{
}

Parser::Checker::~Checker()
{
}

void Parser::Checker::Check()
{
    CheckOutputs();
    CheckType();
    CheckNames();
}

void Parser::Checker::CheckOutputs() const
{
    bool found = false;

    for (unsigned int i = 0; i < _chipsetInfo.size(); i++) {
        if (_chipsetInfo[i].type != Component::Type::OUTPUT)
            continue;
        for (unsigned int j = 0; j < _allLinks.size(); j++) {
            if (_allLinks[j].destinationName == _chipsetInfo[i].value ||
            _allLinks[j].originName == _chipsetInfo[i].value) {
                found = true;
                break;
            }
        }
        if (found == false)
            throw Error::Paser::FormatError("Output must have at least one link", "CheckOutputs");
        found = true;
    }
}

void Parser::Checker::CheckLinksMultiple() const
{
    std::string name;
    int pin;

    for (unsigned int i = 0; i < _allLinks.size(); i++) {
        name = _allLinks[i].originName;
        pin = _allLinks[i].originPin;
        for (unsigned int j = 0; j < _allLinks.size(); j++) {
            if (j != i) {
                if ((name == _allLinks[j].originName && pin == _allLinks[j].originPin) ||
                    (name == _allLinks[j].destinationName && pin == _allLinks[j].destinationPin))
                    throw Error::Paser::FormatError("Link is already used somewhere else", "CheckLinksMultiple");
            } else {
                if (name == _allLinks[j].destinationName && pin == _allLinks[j].destinationPin)
                    throw Error::Paser::FormatError("Link is already used somewhere else", "CheckLinksMultiple");
            }
        }
    }
}

void Parser::Checker::CheckNames() const
{
    for (unsigned int i = 0; i < _chipsetInfo.size(); i++) {
        for (unsigned int j = 0; j < _chipsetInfo.size(); j++) {
            if (j == i)
                continue;
            if (_chipsetInfo[i].value == _chipsetInfo[j].value)
                throw Error::Paser::FormatError("Name appear twice on file", "CheckNames");
        }
    }
}

void Parser::Checker::CheckType() const
{
    for (unsigned int i = 0; i < _chipsetInfo.size(); i++) {
        if (_chipsetInfo[i].type == Component::NOT_SET)
            throw Error::Paser::FormatError("The type a chipset is incorrect", "CheckType");
    }
}

bool Parser::Checker::IsUseless() const
{
    size_t pos = 0;

    while (pos < _line.size() && std::isspace(_line[pos]))
        pos++;
    return _line[pos] == '#' || pos == _line.size();
}