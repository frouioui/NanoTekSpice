/*
** EPITECH PROJECT, 2019
** OOP_NANOTEKSPICE_2018
** File description:
** Component header
*/

#ifndef COMPONENT4001_HPP_
	#define COMPONENT4001_HPP_

#include "IComponent.hpp"
#include <iostream>

class Component4001 : public nts::IComponent
{
	public:
		Component4001();
		~Component4001();

		nts::Tristate compute(std::size_t pin = 1) override;
		void setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin) override;
		void dump() const override;

	private:
		std::size_t _pin;
		nts::Tristate _state;
};

#endif /* !COMPONENT_HPP_ */