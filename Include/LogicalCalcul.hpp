/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Header file of the logical calcul class
*/

#if !defined(_LOGICAL_CALCUL_HPP)
#define _LOGICAL_CALCUL_HPP

#include "IComponent.hpp"

class LogicalCalcul
{
public:
    LogicalCalcul(const nts::Tristate &inputA, const nts::Tristate &inputB);
    LogicalCalcul(const nts::Tristate &inputA);
    ~LogicalCalcul();

    nts::Tristate CalculAnd() const;
    nts::Tristate CalculOr() const;
    nts::Tristate CalculNon() const;
    nts::Tristate CalculNand() const;
    nts::Tristate CalculNor() const;
    nts::Tristate CalculXor() const;
    nts::Tristate CalculXnor() const;

private:
    nts::Tristate _inputA;
    nts::Tristate _inputB;
};

#endif // _LOGICAL_CALCUL_HPP
