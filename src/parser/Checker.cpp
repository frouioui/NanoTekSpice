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

Parser::Checker::Checker()
{
}

Parser::Checker::~Checker()
{
}

void Parser::Checker::Check(const std::vector<Component::ComponentSetting> &chipsetInfo)
{
    _chipsetInfo = chipsetInfo;

    CheckLinks();
    CheckNames();
    CheckType();
}

void Parser::Checker::CheckLinks() const
{
}

void Parser::Checker::CheckNames() const
{
    for (unsigned int i = 0; i < _chipsetInfo.size(); i++) {
        for (unsigned int j = 0; j < _chipsetInfo.size(); j++) {
            if (j == i)
                continue;
            if (_chipsetInfo.at(i).value == _chipsetInfo.at(j).value)
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