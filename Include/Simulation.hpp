/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Header file of the simulation class
*/

#if !defined(_SIMULATION_HPP)
#define _SIMULATION_HPP

namespace Simulation
{

    enum Action {
        NOTHING,
        SET_VALUE,
        EXIT,
        SIMULATE,
        DISPLAY,
        LOOP,
        DUMP
    };

    class Simulation
    {
    public:
        Simulation();
        ~Simulation();

        const unsigned short NUMBER_OF_ACTION = 5;
        const char KEYWORD_ACTION[5][10] = {
            {"exit"}, {"simulate"}, {"display"},
            {"loop"}, {"dump"}
        };

        void Run();
        void DisplayPrompt() const;
        void GetAction();

        bool IsItKeyValue() const;
        bool IsExitProg() const;

    private:
        std::string _line;
        Action _action;
        // Circuit _circuit;
    };

} // Simulation


#endif // _SIMULATION_HPP
