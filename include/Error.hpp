/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Error classes
*/

#ifndef ERROR_HPP_
	#define ERROR_HPP_

#include <exception>
#include <iostream>

namespace Error {
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

    namespace Paser {
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
    }

    namespace Component {

    }

    namespace Argument
    {

        class KeyValueIncomplete : public Error
        {
            public:
                KeyValueIncomplete(std::string const &message, std::string const &where = "Unknown") : Error(message, where) {};
                virtual ~KeyValueIncomplete() throw() {};
        };

    } // Argument
    
}

#endif /* !ERROR_HPP_ */
