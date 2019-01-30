/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Declaration of the Paser class
*/

#if !defined(_PARSER_HPP)
#define _PARSER_HPP

#include <string>
#include <map>
#include <exception>
#include <fstream>
#include "Component.hpp"

// TODO: remove and use the lib function
#define SPACE(c) (c == ' ')
#define TAB(c) (c == '\t')
#define SPACE_OR_TAB(c) (SPACE(c) || TAB(c))

namespace Parser
{

    class Parser
    {
    public:
        Parser(const std::string &filename);
        ~Parser();

        const std::vector<Component::ComponentSetting> &Parse();
        void ReadFile();
        std::ifstream OpenFile() const;

    private:
        std::string _filename;
        std::vector<std::string> _lines;
    };

    class LineParser
    {
    public:
        LineParser(const std::string &line);
        ~LineParser();

        const std::string &GetLine() const;

        bool IsUseless() const;
        void ClearLine();
        void RemoveComment();

        const Component::Type &GetType(const std::string &typeStr) const;
        const Component::ComponentSetting &GetInfoComponent() const;
        const Component::Link &GetLink() const;

        const std::map<std::string, std::string> &SplitLineInTwo() const;

    private:
        std::string _line;
    };

    class Checker
    {
    public:
        Checker(const std::vector<Component::ComponentSetting> &chipsetInfo);
        ~Checker();

        void Check() const;
        void CheckLinks() const;
        void CheckNames() const;
        void CheckType() const;

    private:
        std::vector<Component::ComponentSetting> _chipsetInfo;
    };

} // Parser


#endif // _PARSER_HPP
