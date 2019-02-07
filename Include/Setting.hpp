/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Declaration of the Component class and its functions
*/

#if !defined(_SETTING_HPP)
#define _SETTING_HPP

#include <vector>
#include <memory>
#include <string>
#include "Type.hpp"

namespace Component
{
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
        std::string value;
        nts::Type type;
        std::vector<Link> links;
    };
} // Component


#endif // _SETTING_HPP
