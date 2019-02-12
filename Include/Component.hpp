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
#include "Type.hpp"

namespace Component
{
    class MyComponent : public nts::IComponent
    {
        public:
            MyComponent(const nts::Type &type);
            ~MyComponent();

            void createAllComponents(const std::vector<Component::ComponentSetting> &settings);
            virtual void setState(const std::string &state);
            virtual void setState(const std::string &name, const std::string &state);

            const std::string &getName() const noexcept final;
            void setName(const std::string &name) noexcept final;

            const nts::Type &getType() const noexcept final;

            void displayState(std::size_t) const noexcept override;

        protected:
            std::string _name;
            nts::Type _type;
    }; //!MyComponent
} // !Component


#endif // _COMPONENT_HPP
