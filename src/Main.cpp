/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Main file of the nanotekspice project
*/

#include "Parser.hpp"

int main(int argc, char **argv)
{
    Parser::Parser::ParseFile("./conf_files/primitives/5input_and.nts");
    return 0;
}