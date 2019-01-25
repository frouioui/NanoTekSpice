/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Declaration of the Paser class
*/

#if !defined(_PASER_HPP)
#define _PASER_HPP

#include <string>
#include <map>
#include <exception>
#include "Component.hpp"

namespace Parser
{
    class Parser
    {
    public:
        Parser();
        ~Parser();

        std::map<std::string, Circuit::Component::ComponentSetting> ParseFile(const std::string &filepath);

    private:
    
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


#endif // _PASER_HPP
