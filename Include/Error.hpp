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

	namespace Parser {
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
		class ComputeError : public Error
		{
			public:
				ComputeError(std::string const &message, std::string const &where = "Unknown") : Error(message, where) {};
				virtual ~ComputeError() throw() {};
		};
		class CreationError : public Error
		{
			public:
				CreationError(std::string const &message, std::string const &where = "Unknown") : Error(message, where) {};
				virtual ~CreationError() throw() {};
		};
		class LinkError : public Error
		{
			public:
				LinkError(std::string const &message, std::string const &where = "Unknown") : Error(message, where) {};
				virtual ~LinkError() throw() {};
		};
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
