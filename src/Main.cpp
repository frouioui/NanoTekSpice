/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Main file of the nanotekspice project
*/

#include <iostream>
#include "Parser.hpp"
#include "ArgumentParser.hpp"

int main(int argc, char **argv)
{
    Argument::ArgumentParser argParser(argc, argv);
    const Argument::Argument args = argParser.GetArgument();

    return 0;
}