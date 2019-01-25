/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Declaration of the Component class and its functions
*/

#if !defined(_COMPONENT_HPP)
#define _COMPONENT_HPP

#include <vector>
#include <string>

namespace Circuit
{

    namespace Component
    {

        enum Type {
            NOT_SET,
            INPUT,
            OUTPUT,
            CLOCK
        }; // TODO: add all the other components...

        class Component
        {
        public:
            Component();
            ~Component();

        private:
            
        };

        struct Link
        {
            std::string OriginName;
            int OriginPin;
            std::string DestinationName;
            int DestinationPin;
        };

        struct ComponentSetting
        {
            Type type;
            std::vector<Link> links;
        };

    } // Component

} // Circuit






#endif // _COMPONENT_HPP
