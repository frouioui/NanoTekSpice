/*
** EPITECH PROJECT, 2019
** OPP_NANOTEKSPICE_2018
** File description:
** Factory methods
*/

#include "Factory.hpp"
#include "Error.hpp"
#include "Circuit.hpp"
#include "C4001.hpp"
#include "C4011.hpp"
#include "C4030.hpp"
#include "C4069.hpp"
#include "C4071.hpp"
#include "C4081.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "True.hpp"
#include "False.hpp"

Factory::Factory()
{
    _componentsCreator[nts::CIRCUIT] = [this] (const std::string& value) {
        return this->createCircuit(value);
    };
    _componentsCreator[nts::INPUT] = [this] (const std::string& value) {
        return this->createInput(value);
    };
    _componentsCreator[nts::OUTPUT] = [this] (const std::string& value) {
        return this->createOutput(value);
    };
    _componentsCreator[nts::CTRUE] = [this] (const std::string& value) {
        return this->createTrue(value);
    };
    _componentsCreator[nts::CFALSE] = [this] (const std::string& value) {
        return this->createFalse(value);
    };
    _componentsCreator[nts::C4001] = [this] (const std::string& value) {
        return this->create4001(value);
    };
    _componentsCreator[nts::C4011] = [this] (const std::string& value) {
        return this->create4011(value);
    };
    _componentsCreator[nts::C4030] = [this] (const std::string& value) {
        return this->create4030(value);
    };
    _componentsCreator[nts::C4069] = [this] (const std::string& value) {
        return this->create4069(value);
    };
    _componentsCreator[nts::C4071] = [this] (const std::string& value) {
        return this->create4071(value);
    };
    _componentsCreator[nts::C4081] = [this] (const std::string& value) {
        return this->create4081(value);
    };
}

Factory::~Factory()
{
}

void Factory::linkComponents(std::map<std::string, nts::ptrIComponent_t> &components,
const Component::ComponentSetting &setting)
{
    std::map<std::string, nts::ptrIComponent_t>::iterator find;

    for (auto it_c = components.begin(); it_c != components.end(); ++it_c) {
        if (setting.name == it_c->first) {
            for (auto it_l = setting.links.begin(); it_l != setting.links.end(); ++it_l) {
                find = components.find(it_l->destinationName);
                it_c->second->setLink(it_l->originPin, *find->second, it_l->destinationPin);
            }
        }
    }
}

void Factory::linkAllComponents(std::map<std::string, std::unique_ptr<nts::IComponent>> &components,
const std::vector<Component::ComponentSetting> &settings)
{
    for (auto it = settings.begin(); it != settings.end(); ++it) {
        linkComponents(components, *it);
    }
}

std::unique_ptr<nts::IComponent> Factory::createComponent(const nts::Type type,
const std::string &value)
{
    auto it = _componentsCreator.find(type);

    if (it == _componentsCreator.end())
        throw Error::Component::CreationError("No corresponding type", "Factory::createComponent");
    return it->second(value);
}

std::unique_ptr<nts::IComponent> Factory::createCircuit(const std::string &) const noexcept
{
    std::unique_ptr<Circuit> newCircuit = std::make_unique<Circuit>();

    return newCircuit;
}

std::unique_ptr<nts::IComponent> Factory::createInput(const std::string &) const noexcept
{
    std::unique_ptr<Input> newInput = std::make_unique<Input>();

    return newInput;
}

std::unique_ptr<nts::IComponent> Factory::createOutput(const std::string &) const noexcept
{
    std::unique_ptr<Output> newOutput = std::make_unique<Output>();

    return newOutput;
}

std::unique_ptr<nts::IComponent> Factory::createTrue(const std::string &value) const noexcept
{
    std::unique_ptr<True> newTrue = std::make_unique<True>();

    return newTrue;
}

std::unique_ptr<nts::IComponent> Factory::createFalse(const std::string &value) const noexcept
{
    std::unique_ptr<False> newFalse = std::make_unique<False>();

    return newFalse;
}

// std::unique_ptr<nts::IComponent> Factory::createClock(const std::string &value) const noexcept
// {

// }

std::unique_ptr<nts::IComponent> Factory::create4001(const std::string &) const noexcept
{
    std::unique_ptr<C4001> newC4001 = std::make_unique<C4001>();

    return newC4001;
}

// std::unique_ptr<nts::IComponent> Factory::create4008(const std::string &value) const noexcept
// {

// }

std::unique_ptr<nts::IComponent> Factory::create4011(const std::string &value) const noexcept
{
    std::unique_ptr<C4011> newC4011 = std::make_unique<C4011>();

    return newC4011;
}

// std::unique_ptr<nts::IComponent> Factory::create4013(const std::string &value) const noexcept
// {

// }

// std::unique_ptr<nts::IComponent> Factory::create4017(const std::string &value) const noexcept
// {

// }

std::unique_ptr<nts::IComponent> Factory::create4030(const std::string &value) const noexcept
{
    std::unique_ptr<C4030> newC4030 = std::make_unique<C4030>();

    return newC4030;
}

// std::unique_ptr<nts::IComponent> Factory::create4040(const std::string &value) const noexcept
// {

// }

std::unique_ptr<nts::IComponent> Factory::create4069(const std::string &value) const noexcept
{
    std::unique_ptr<C4069> newC4069 = std::make_unique<C4069>();

    return newC4069;
}

std::unique_ptr<nts::IComponent> Factory::create4071(const std::string &value) const noexcept
{
    std::unique_ptr<C4071> newC4071 = std::make_unique<C4071>();

    return newC4071;
}

std::unique_ptr<nts::IComponent> Factory::create4081(const std::string &value) const noexcept
{
    std::unique_ptr<C4081> newC4081 = std::make_unique<C4081>();

    return newC4081;
}

// std::unique_ptr<nts::IComponent> Factory::create4094(const std::string &value) const noexcept
// {

// }

// std::unique_ptr<nts::IComponent> Factory::create4514(const std::string &value) const noexcept
// {

// }

// std::unique_ptr<nts::IComponent> Factory::create4801(const std::string &value) const noexcept
// {

// }

// std::unique_ptr<nts::IComponent> Factory::create2716(const std::string &value) const noexcept
// {

// }