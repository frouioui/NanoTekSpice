/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** C4001 class
*/

#ifndef C4001_HPP_
	#define C4001_HPP_

#include "IComponent.hpp"
#include <iostream>
#include <string>
#include <map>

class C4001 : public nts::IComponent
{
	public:
		C4001();
		~C4001();

		nts::Tristate compute(std::size_t pin = 1) override;
		void setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin) override;
		void dump() const override;

		void setName(const std::string &name);

		void setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
		void setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

	private:
		void checkSelfLink(std::size_t pin1, std::size_t pin2);

		std::string _name;
		std::map<size_t, nts::Door> _doors;
};

#endif /* !C4001_HPP_ */