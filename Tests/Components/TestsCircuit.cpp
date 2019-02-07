/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Unit tests on Circuit initialisation
*/

#include <criterion/criterion.h>
#include <string>
#include <iostream>
#include "Circuit.hpp"
#include "Parser.hpp"
#include "ArgumentParser.hpp"

Test(Circuit, simpleConstruction)
{
	Circuit circuit;
	// Argument::ArgumentParser argParser(2, "./Tests/assets/exemple/public/basics/nor.nts",);
	// Argument::Argument args;
	Parser::container_setting_t settings;
	settings = Parser::Parser("./Tests/assets/exemple/public/basics/nor.nts").Parse();

	circuit.createAllComponents(settings);
	circuit.dump();
}