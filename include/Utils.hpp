#pragma once
#include "Commons.hpp"

std::string figureToString (Figure figure)
{
    const std::map<Figure, std::string> stringRepresentation {
        { Figure::WPawn, "♙" },
        { Figure::WRook, "♖" },
        { Figure::WKnight, "♘" },
        { Figure::WBishop, "♗" },
        { Figure::WQueen, "♕" },
        { Figure::WKing, "♔" },
        { Figure::BPawn, "♟" },
        { Figure::BRook, "♜" },
        { Figure::BKnight, "♞" },
        { Figure::BBishop, "♝" },
        { Figure::BQueen, "♛" },
        { Figure::BKing, "♚" }

    };
    auto   it  = stringRepresentation.find(figure);
    return it == stringRepresentation.end() ? "Out of range exception" : it->second;
}