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

		// void createAllComponents(const std::vector<Component::ComponentSetting> &components);
		std::unique_ptr<nts::IComponent> createComponent(const Component::Type type,
		const std::string &value);

	private:
		using ptr_component_t = std::unique_ptr<nts::IComponent>;
		using func_t = std::function<ptr_component_t(const std::string&)>;
		std::map<Component::Type, func_t> _componentsCreator;

		std::vector<Component::ComponentSetting> _components;

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
