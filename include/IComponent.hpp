/*
** EPITECH PROJECT, 2019
** OOP_NANOTEKSPICE
** File description:
** ICoponent header
*/

#ifndef ICOMPONENT_HPP_
	#define ICOMPONENT_HPP_

#include <cstddef>

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
    };
}

#endif /* !ICOMPONENT_HPP_ */
