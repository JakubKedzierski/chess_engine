#include "Commons.hpp"

std::wstring figureToString(Figure figure)
{

    const std::map<Figure, std::wstring> stringRepresentation{
        {Figure::WPawn,  L"\u2659"},
        {Figure::WRook, L"\u2656"},
        {Figure::WKnight, L"\u2658"},
        {Figure::WBishop, L"\u2657"},
        {Figure::WQueen, L"\u2655"},
        {Figure::WKing, L"\u2654"},
        {Figure::BPawn, L"\u265F"},
        {Figure::BRook, L"\u265C"},
        {Figure::BKnight, L"\u265E"},
        {Figure::BBishop, L"\u265D"},
        {Figure::BQueen, L"\u265B"},
        {Figure::BKing, L"\u265A"},
        {Figure::Empty, L"\u2610"}

    };

    auto it = stringRepresentation.find(figure);
    return it == stringRepresentation.end() ? L"0" : it->second;
}