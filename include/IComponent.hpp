/*
** EPITECH PROJECT, 2019
** OOP_NANOTEKSPICE
** File description:
** ICoponent header
*/

#ifndef ICOMPONENT_HPP_
	#define ICOMPONENT_HPP_

#include <cstddef>
#include <memory>

namespace nts
{
	enum Tristate {
		UNDEFINED = (-true),
		TRUE = true ,
		FALSE = false
	};

	class IComponent
	{
	public:
		virtual ~IComponent() = default;
	public:
		virtual nts::Tristate compute(std::size_t pin = 1) = 0;
		virtual void setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin) = 0;
		virtual void dump() const = 0;

		virtual void setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
		virtual void setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
	};

	using ptrIComponent_t = std::unique_ptr<nts::IComponent>;

	struct Pin {
		size_t pin;
		nts::Tristate state;
		nts::IComponent *destinationName;
		int destinationPin;
	};

	struct Door {
		nts::Pin input1;
		nts::Pin input2;
		nts::Pin output;
	};
}

#endif /* !ICOMPONENT_HPP_ */
