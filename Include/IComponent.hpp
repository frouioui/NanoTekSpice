/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** IComponent header
*/

#ifndef ICOMPONENT_HPP_
    #define ICOMPONENT_HPP_

#include "Type.hpp"
#include "Setting.hpp"
#include <cstddef>
#include <memory>

namespace nts
{
    class IComponent
    {
    public:
        virtual ~IComponent() = default;

    public:
        virtual void createAllComponents(const std::vector<Component::ComponentSetting> &settings) = 0;

        virtual nts::Tristate compute(std::size_t pin = 1) = 0;
        virtual void setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin) = 0;
        virtual void dump() const noexcept = 0;

        virtual void setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        virtual void setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;

        virtual void setState(const std::string &name, const std::string &state) = 0;
        virtual void setState(const std::string &state) = 0;

        virtual void setName(const std::string &name) noexcept = 0;
        virtual const std::string &getName() const noexcept = 0;

        virtual const Type &getType() const noexcept = 0;
    }; // !IComponent

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
} // !nts

#endif /* !ICOMPONENT_HPP_ */
