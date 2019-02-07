/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Declaration of the Component class and its functions
*/

#if !defined(_COMPONENT_HPP)
#define _COMPONENT_HPP

#include <vector>
#include <memory>
#include <string>
#include "IComponent.hpp"

namespace Component
{
    class MyComponent : public nts::IComponent
    {
        public:
            MyComponent(const nts::Type &type);
            ~MyComponent();

            virtual void setState(const std::string &state);

            const std::string &getName() const noexcept final;
            void setName(const std::string &name) noexcept final;

            const nts::Type &getType() const noexcept final;

        protected:
            std::string _name;
            nts::Type _type;
    };

    struct Link
    {
        std::string originName;
        int originPin;
        std::string destinationName;
        int destinationPin;
    };

    struct ComponentSetting
    {
        std::string name;
        std::string value;
        nts::Type type;
        std::vector<Link> links;
    };
} // Component


#endif // _COMPONENT_HPP
