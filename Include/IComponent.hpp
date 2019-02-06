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
	const int NUMBER_OF_TYPE = 19;

	enum Type {
		NOT_SET,
		INPUT,
		OUTPUT,
		CLOCK,
		CFALSE,
		CTRUE,
		C4001,
		C4008,
		C4011,
		C4013,
		C4017,
		C4030,
		C4040,
		C4069,
		C4071,
		C4081,
		C4094,
		C4514,
		C4801,
		C2716
	}; // TODO: add all the other components...

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

		virtual void setName(const std::string &name) noexcept = 0;
		virtual const std::string &getName() const noexcept = 0;

		virtual const Type &getType() const noexcept = 0;
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
