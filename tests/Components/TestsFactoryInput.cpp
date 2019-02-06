/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Unit tests for Inputs construction
*/

#include <criterion/criterion.h>
#include <string>
#include <iostream>
#include "Factory.hpp"
#include "Input.hpp"

Test(Factory, simpleInput)
{
	Factory fact;
	std::unique_ptr<nts::IComponent> inA = fact.createComponent(Component::INPUT, "");

	cr_assert_eq(inA->compute(1), nts::UNDEFINED);
}

Test(Factory, True)
{
	Factory fact;
	std::unique_ptr<nts::IComponent> inTrue = fact.createComponent(Component::TRUE, "");

	cr_assert_eq(inTrue->compute(1), nts::TRUE);
}

Test(Factory, False)
{
	Factory fact;
	std::unique_ptr<nts::IComponent> inFalse = fact.createComponent(Component::FALSE, "");

	cr_assert_eq(inFalse->compute(1), nts::FALSE);
}