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

namespace Parser
{

    class Parser
    {
    public:
        ~Parser();

        static std::map<std::string, Component::ComponentSetting> ParseFile(const std::string &filepath);
        static std::ifstream openFile(const std::string &filepath);
    };

    class Error : public std::exception
    {
        public:
            Error(std::string const &message, std::string const &component = "Unknown");
            virtual ~Error() throw() {};

            std::string const &getComponent() const;
            const char* what() const noexcept override;

        protected:
            std::string _component;
        private:
            std::string _message;
    };

} // Parser


#endif // _PARSER_HPP
