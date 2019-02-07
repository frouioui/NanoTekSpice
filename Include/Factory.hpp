/*
** EPITECH PROJECT, 2019
** OPP_NANOTEKSPICE_2018
** File description:
** Factory class
*/

#ifndef FACTORY_HPP_
    #define FACTORY_HPP_

#include <functional>
#include <map>
#include <memory>
#include "IComponent.hpp"
#include "Component.hpp"

class Factory {
    public:
        Factory();
        ~Factory();

        std::unique_ptr<nts::IComponent> createComponent(const nts::Type type,
        const std::string &value);

        void linkAllComponents(std::map<std::string, nts::ptrIComponent_t> &components,
        const std::vector<Component::ComponentSetting> &settings);


    private:
        using func_t = std::function<nts::ptrIComponent_t(const std::string&)>;
        std::map<nts::Type, func_t> _componentsCreator;

        // void setLinks(std::map<std::string, nts::ptrIComponent_t> &components,
        // <std::string, nts::ptrIComponent_t> component, const std::vector<Component::Link> &links);

        void linkComponents(std::map<std::string, nts::ptrIComponent_t> &components,
        const Component::ComponentSetting &setting);

        std::unique_ptr<nts::IComponent> createInput(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createOutput(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createTrue(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createFalse(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createClock(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4001(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4008(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4011(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4013(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4017(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4030(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4040(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4069(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4071(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4081(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4094(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4514(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4801(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create2716(const std::string &value) const noexcept;
};

#endif /* !FACTORY_HPP_ */
