/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Output class
*/

#ifndef OUTPUT_HPP_
	#define OUTPUT_HPP_

#include "IComponent.hpp"
#include <iostream>
#include <map>

class Output : public nts::IComponent
{
	public:
		Output(const std::string &name);
		~Output();

	nts::Tristate compute(std::size_t pin = 1) override;
	void setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin) override;
	void dump() const override;

	void setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

	private:
		const std::string &_name;
		std::map<size_t, nts::Pin> _input;
};

#endif /* !OUTPUT_HPP_ */
