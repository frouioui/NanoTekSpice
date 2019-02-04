/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Declaration of the Component class and its functions
*/

#if !defined(_COMPONENT_HPP)
#define _COMPONENT_HPP

#include <vector>
#include <memory>
#include <string>

namespace Component
{

    const int NUMBER_OF_TYPE = 19;

    enum Type {
        NOT_SET,
        INPUT,
        OUTPUT,
        CLOCK,
        FALSE,
        TRUE,
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

    struct Link
    {
        std::string originName;
        int originPin;
        std::string destinationName;
        int destinationPin;
    };

    struct ComponentSetting
    {
        std::string name;
        Type type;
        std::vector<Link> links;
    };
} // Component


#endif // _COMPONENT_HPP
