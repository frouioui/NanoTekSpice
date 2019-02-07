/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Component methods
*/

#include "Component.hpp"

Component::MyComponent::MyComponent(const nts::Type &type) : _type(type)
{
}

Component::MyComponent::~MyComponent()
{
}

const std::string &Component::MyComponent::getName() const noexcept
{
    return _name;
}

void Component::MyComponent::setName(const std::string &name) noexcept
{
    _name = name;
}

const nts::Type &Component::MyComponent::getType() const noexcept
{
    return _type;
}

void Component::MyComponent::setState(const std::string &)
{
}
