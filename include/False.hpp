/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** False class
*/

#ifndef FALSE_HPP_
	#define FALSE_HPP_

#include "IComponent.hpp"
#include <iostream>
#include <map>

class False : public nts::IComponent
{
	public:
		False();
		~False();

		nts::Tristate compute(std::size_t pin = 1) override;
		void setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin) override;
		void dump() const override;

		void setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
		void setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

		const std::string &getName() const noexcept override;
		void setName(const std::string &name) noexcept override;

	private:
		std::string _name;
		std::map<size_t, nts::Pin> _output;
};

#endif /* !FALSE_HPP_ */
