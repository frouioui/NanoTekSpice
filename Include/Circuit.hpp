/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Circuit class
*/

#ifndef CIRCUIT_HPP_
	#define CIRCUIT_HPP_

#include "IComponent.hpp"
#include "Component.hpp"
#include "Parser.hpp"
#include <map>

class Circuit {
	public:
		Circuit();
		~Circuit();

		void createAllComponents(const Parser::container_setting_t &settings);

		void setState(const std::string &name, const std::string &state);

		nts::Tristate compute();

		void dump() const noexcept;

	private:
		void linkAllComponents(const std::vector<Component::ComponentSetting> &settings);

		std::map<std::string, nts::ptrIComponent_t> _allComponents;
};

#endif /* !CIRCUIT_HPP_ */