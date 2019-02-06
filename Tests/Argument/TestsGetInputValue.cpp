/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Test file of the get input value
*/

#include <criterion/criterion.h>
#include <string>
#include "ArgumentParser.hpp"
#include "Error.hpp"

Test(Argument, get_input_value_simple)
{
    int argc = 2;
    char **argv = (char **)malloc(sizeof(char *) * 3);

    argv[0] = strdup("./nano");
    argv[1] = strdup("i=4");
    argv[2] = NULL;
    Argument::ArgumentParser argParser(argc, (char **)argv);
    std::map<std::string, std::string> keyValue = argParser.GetInputValue();

    cr_assert_eq(keyValue["i"].compare("4"), 0);
}

Test(Argument, get_input_value_complex)
{
    int argc = 6;
    char **argv = (char **)malloc(sizeof(char *) * 7);

    argv[0] = strdup("./nano");
    argv[1] = strdup("i=4");
    argv[2] = strdup("v=75");
    argv[3] = strdup("W=0");
    argv[4] = strdup("filename");
    argv[5] = strdup("P=9");
    argv[6] = NULL;
    Argument::ArgumentParser argParser(argc, (char **)argv);
    std::map<std::string, std::string> keyValue = argParser.GetInputValue();

    cr_assert_eq(keyValue["i"].compare("4"), 0);
    cr_assert_eq(keyValue["v"].compare("75"), 0);
    cr_assert_eq(keyValue["W"].compare("0"), 0);
    cr_assert_eq(keyValue["P"].compare("9"), 0);
}

Test(Argument, get_input_value_with_simple_error)
{
    int argc = 3;
    char **argv = (char **)malloc(sizeof(char *) * 4);

    argv[0] = strdup("./nano");
    argv[1] = strdup("i=4");
    argv[2] = strdup("v=");
    argv[3] = NULL;
    Argument::ArgumentParser argParser(argc, (char **)argv);
    cr_assert_throw(argParser.GetInputValue(), Error::Argument::KeyValueIncomplete);
}

Test(Argument, get_input_value_with_simple_error_2)
{
    int argc = 3;
    char **argv = (char **)malloc(sizeof(char *) * 4);

    argv[0] = strdup("./nano");
    argv[1] = strdup("i=4");
    argv[2] = strdup("=4");
    argv[3] = NULL;
    Argument::ArgumentParser argParser(argc, (char **)argv);
    cr_assert_throw(argParser.GetInputValue(), Error::Argument::KeyValueIncomplete);
}