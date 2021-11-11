#pragma once

#include <iostream>
#include <array>
#include <map>
#include <memory>

enum class Figure
{
    WPawn,
    WRook,
    WKnight,
    WBishop,
    WQueen,
    WKing,
    BPawn,
    BRook,
    BKnight,
    BBishop,
    BQueen,
    BKing,
    Empty
};

constexpr int BOARD_SIZE = 8;
using Board = std::array<std::array<Figure, BOARD_SIZE>, BOARD_SIZE>;

std::wstring figureToString(Figure figure);
