/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Test file of the argument parser function (GetFileName)
*/

#include <criterion/criterion.h>
#include <iostream>
#include "ArgumentParser.hpp"

Test(Argument, get_filename_correct)
{
    int argc = 2;
    char **argv = (char **)malloc(sizeof(char *) * 3);

    argv[0] = strdup("./nano");
    argv[1] = strdup("filename");
    argv[2] = NULL;
    Argument::ArgumentParser argParser(argc, (char **)argv);
    std::string filename = argParser.GetFilename();

    cr_assert_eq(filename.compare("filename"), 0);
}

Test(Argument, get_filename_correct_complex)
{
    int argc = 4;
    char **argv = (char **)malloc(sizeof(char *) * 5);

    argv[0] = strdup("./nano");
    argv[1] = strdup("t=4");
    argv[2] = strdup("filename");
    argv[3] = strdup("in=7");
    argv[4] = NULL;
    Argument::ArgumentParser argParser(argc, (char **)argv);
    std::string filename = argParser.GetFilename();

    cr_assert_eq(filename.compare("filename"), 0);
}