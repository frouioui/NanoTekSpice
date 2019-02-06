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

Test(Circuit, simpleConstruction)
{
	Circuit circuit;

	circuit.createAllComponents("/home/cecile/Projects/Semestre_4/OOP/NanoTekSpice/tests/assets/exemple/public/basics/nor.nts");
	circuit.dump();
}