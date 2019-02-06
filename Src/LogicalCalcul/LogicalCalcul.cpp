/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Source file of the LogicalCalcul class
*/

#include "LogicalCalcul.hpp"
#include "IComponent.hpp"

LogicalCalcul::LogicalCalcul(const nts::Tristate &inputA, const nts::Tristate &inputB) : _inputA(inputA), _inputB(inputB)
{
}

LogicalCalcul::~LogicalCalcul()
{
}

nts::Tristate LogicalCalcul::CalculAnd() const
{
    return (_inputA == nts::TRUE && _inputB == nts::TRUE ? nts::TRUE : nts::FALSE);
}

nts::Tristate LogicalCalcul::CalculOr() const
{
    return (_inputA == nts::TRUE || _inputB == nts::TRUE ? nts::TRUE : nts::FALSE);
}

nts::Tristate LogicalCalcul::CalculNon() const
{
    return (_inputA == nts::TRUE ? nts::FALSE : nts::TRUE);
}

nts::Tristate LogicalCalcul::CalculNand() const
{
    if (_inputA == nts::TRUE && _inputB == nts::FALSE)
        return nts::TRUE;
    else if (_inputA == nts::FALSE && _inputB == nts::TRUE)
        return nts::TRUE;
    else if (_inputA == nts::FALSE && _inputB == nts::FALSE)
        return nts::TRUE;
    return (nts::FALSE);
}

nts::Tristate LogicalCalcul::CalculNor() const
{
    return (_inputA == nts::FALSE && _inputB == nts::FALSE ? nts::TRUE : nts::FALSE);
}

nts::Tristate LogicalCalcul::CalculXor() const
{
    if (_inputA == nts::TRUE && _inputB == nts::FALSE)
        return nts::TRUE;
    else if (_inputA == nts::FALSE && _inputB == nts::TRUE)
        return nts::TRUE;
    return (nts::FALSE);
}

nts::Tristate LogicalCalcul::CalculXnor() const
{
    if (_inputA == nts::FALSE && _inputB == nts::FALSE)
        return nts::TRUE;
    else if (_inputA == nts::TRUE && _inputB == nts::TRUE)
        return nts::TRUE;
    return (nts::FALSE);
}