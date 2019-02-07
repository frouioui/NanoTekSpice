/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** False class
*/

#ifndef FALSE_HPP_
	#define FALSE_HPP_

#include "Component.hpp"
#include <iostream>
#include <map>

class False : public Component::MyComponent
{
	public:
		False();
		~False();

		nts::Tristate compute(std::size_t pin = 1) override;
		void setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin) override;
		void dump() const override;

		void setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
		void setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;

	private:
		std::map<size_t, nts::Pin> _output;
};

#endif /* !FALSE_HPP_ */