/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** C4001 class
*/

#ifndef C4001_HPP_
	#define C4001_HPP_

#include "IComponent.hpp"
#include "Component.hpp"
#include <iostream>
#include <string>
#include <map>

class C4001 : public Component::MyComponent
{
	public:
		C4001();
		~C4001();

		nts::Tristate compute(std::size_t pin = 1) override;
		void setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin) final;
		void dump() const override;

		void setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
		void setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;

	private:
		void checkSelfLink(std::size_t pin1, std::size_t pin2);
		nts::Tristate computeInput(nts::Pin &pin);
		nts::Tristate computeOutput(nts::Door &door);

		std::map<size_t, nts::Door> _doors;
};

#endif /* !C4001_HPP_ */