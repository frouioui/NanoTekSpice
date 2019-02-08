/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Type header
*/

#ifndef TYPE_HPP
    #define TYPE_HPP

#include <cstddef>
#include <memory>

namespace nts
{
    constexpr int NUMBER_OF_TYPE = 20;

    enum Type {
        NOT_SET,
        CIRCUIT,
        INPUT,
        OUTPUT,
        CLOCK,
        CFALSE,
        CTRUE,
        C4001,
        C4008,
        C4011,
        C4013,
        C4017,
        C4030,
        C4040,
        C4069,
        C4071,
        C4081,
        C4094,
        C4514,
        C4801,
        C2716
    }; // TODO: add all the other components...

    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true ,
        FALSE = false
    }; // !Type
} // !nts

#endif /* !TYPE_HPP */