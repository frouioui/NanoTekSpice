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

#define SPACE(c) (c == ' ')
#define TAB(c) (c == '\t')
#define SPACE_OR_TAB(c) (SPACE(c) || TAB(c))

namespace Parser
{

    class Parser
    {
    public:
        static std::vector<Component::ComponentSetting> ParseFile(const std::string &filepath);
        static std::vector<Component::ComponentSetting> BeginParsing(std::ifstream &file);
        static std::ifstream OpenFile(const std::string &filepath);
        static const std::string ClearLine(std::string &line);
        static bool IsLineUseless(const std::string &line);
        static const std::string RemoveComment(std::string &line);
        static Component::Type GetType(const std::string &type);
        static const std::vector<Component::Link> GetLinks(std::ifstream &file);
        static std::map<std::string, std::string> SplitLineInTwo(const std::string &line);
        static const Component::ComponentSetting CreateNewChipsetInfo(const std::string &name, const std::string &type);
        static void AddLinksToChipsetInfo(const std::vector<Component::Link> &allLinks, std::vector<Component::ComponentSetting> &components);
    };

    // TODO: Put the error class in an other file and make it its own class.
    class Error : public std::exception
    {
        public:
            Error(const std::string &message, const std::string &where = "Unknown");
            virtual ~Error() throw() {};

            const std::string &where() const;
            const char* what() const noexcept override;

        protected:
            std::string _where;
        private:
            std::string _message;
    };

    class FileError : public Error
    {
        public:
            FileError(std::string const &message, std::string const &where = "Unknown") : Error(message, where) {};
            virtual ~FileError() throw() {};
    };

    class FormatError : public Error
    {
        public:
            FormatError(std::string const &message, std::string const &where = "Unknown") : Error(message, where) {};
            virtual ~FormatError() throw() {};
    };

} // Parser


#endif // _PARSER_HPP
