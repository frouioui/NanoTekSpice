/*
** EPITECH PROJECT, 2019
** OPP_NANOTEKSPICE_2018
** File description:
** Factory methods
*/

#include "Factory.hpp"
#include "C4001.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "True.hpp"
#include "False.hpp"

Factory::Factory()
{
	_componentsCreator[Component::INPUT] = [this] (const std::string& value) {
		return this->createInput(value);
	};
	_componentsCreator[Component::OUTPUT] = [this] (const std::string& value) {
		return this->createOutput(value);
	};
	_componentsCreator[Component::TRUE] = [this] (const std::string& value) {
		return this->createTrue(value);
	};
	_componentsCreator[Component::FALSE] = [this] (const std::string& value) {
		return this->createFalse(value);
	};
	_componentsCreator[Component::C4001] = [this] (const std::string& value) {
		return this->create4001(value);
	};
}

Factory::~Factory()
{
}

std::unique_ptr<nts::IComponent> Factory::createComponent(const Component::Type type,
const std::string &value)
{
	auto it = _componentsCreator.find(type);

	if (it == _componentsCreator.end())
		return nullptr;
	return it->second(value);
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

// std::unique_ptr<nts::IComponent> Factory::create4011(const std::string &value) const noexcept
// {

// }

// std::unique_ptr<nts::IComponent> Factory::create4013(const std::string &value) const noexcept
// {

// }

// std::unique_ptr<nts::IComponent> Factory::create4017(const std::string &value) const noexcept
// {

// }

// std::unique_ptr<nts::IComponent> Factory::create4030(const std::string &value) const noexcept
// {

// }

// std::unique_ptr<nts::IComponent> Factory::create4040(const std::string &value) const noexcept
// {

// }

// std::unique_ptr<nts::IComponent> Factory::create4069(const std::string &value) const noexcept
// {

// }

// std::unique_ptr<nts::IComponent> Factory::create4071(const std::string &value) const noexcept
// {

// }

// std::unique_ptr<nts::IComponent> Factory::create4081(const std::string &value) const noexcept
// {

// }

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