/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Source file of the argument parser functions and class
*/

#include <string>
#include "ArgumentParser.hpp"
#include "Error.hpp"

Argument::ArgumentParser::ArgumentParser(int argc, char **argv) : _argc(argc), _argv(argv)
{
}

Argument::ArgumentParser::~ArgumentParser()
{
}

const Argument::Argument Argument::ArgumentParser::GetArgument() const
{
    Argument args;

    args.filename = GetFilename();
    args.intputValues = GetInputValue();
    return args;
}

const std::string Argument::ArgumentParser::GetFilename() const
{
    if (_argc < 2) {
        return "";
    }
    for (int i = 1; i < _argc; i++) {
        std::string arg(_argv[i]);
        if (arg.find('=', 0) == std::string::npos) {
            return arg;
        }
    }
    return "";
}

const std::map<std::string, std::string> Argument::ArgumentParser::GetInputValue() const
{
    std::map<std::string, std::string> ret;

    if (_argc < 2) {
        return ret;
    }
    for (int i = 1; i < _argc; i++) {
        std::string arg(_argv[i]);
        size_t pos = arg.find('=', 0);
        if (pos == std::string::npos)
            continue;
        std::string key = arg.substr(0, pos);
        if (key == "") {
            throw Error::Argument::KeyValueIncomplete("Key is missing for the given value", "GetInputValue");
        }
        std::string value = arg.substr(pos + 1);
        if (value == "") {
            throw Error::Argument::KeyValueIncomplete("Value is missing for the given key", "GetInputValue");
        }
        ret[key] = value;
    }
    return ret;
}