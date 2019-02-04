/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Header file of the argument parser class
*/

#if !defined(_ARGUMENT_PARSER_HPP)
#define _ARGUMENT_PARSER_HPP

#include <map>
#include <string>

namespace Argument
{

    struct Argument {
        std::string filename;
        std::map<std::string, std::string> intputValues;
    };

    class ArgumentParser
    {
    public:
        ArgumentParser(int argc, char **argv);
        ~ArgumentParser();

        const Argument GetArgument() const;
        const std::string GetFilename() const;
        const std::map<std::string, std::string> GetInputValue() const;

    private:
        int _argc;
        char **_argv;
    };

} // Argument


#endif // _ARGUMENT_PARSER_HPP
