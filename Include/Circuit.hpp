/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Circuit class
*/

#ifndef CIRCUIT_HPP_
    #define CIRCUIT_HPP_

#include "IComponent.hpp"
#include "Setting.hpp"
#include "Parser.hpp"
#include <map>

class Circuit : public Component::MyComponent
{
    public:
        Circuit();
        ~Circuit();

        void setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin) {}

        void setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {}
        void setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {}

        void createAllComponents(const Parser::container_setting_t &settings) final;

        void setState(const std::string &name, const std::string &state) final;

        nts::Tristate compute(std::size_t) override;

        void dump() const noexcept override;
        void displayState(std::size_t) const noexcept final;

    private:
        void linkAllComponents(const std::vector<Component::ComponentSetting> &settings);

        std::map<std::string, nts::ptrIComponent_t> _allComponents;
};

#endif /* !CIRCUIT_HPP_ */