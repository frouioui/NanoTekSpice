/*
** EPITECH PROJECT, 2019
** OPP_NANOTEKSPICE_2018
** File description:
** Factory header
*/

#ifndef FACTORY_HPP_
	#define FACTORY_HPP_

#include <memory>
#include "IComponent.hpp"

class Factory {
	public:
		Factory();
		~Factory();

		std::unique_ptr<nts::IComponent> createComponent(const std::string &type,
									const std::string &value);

	private:
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
