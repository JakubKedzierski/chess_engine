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

enum class NotationType
{
    English,
    Polish
};

enum class Turn
{
    White,
    Black
};

struct Move
{
    int column1 = -1; // a,b,c,d
    int row1 = -1;    // 1,2,3,4,5

    int column2 = -1;
    int row2 = -1;

    bool operator==(const Move &rhs) const
    {
        return row1 == rhs.row1 && column1 == rhs.column1 && row2 == rhs.row2 && column2 == rhs.column2;
    }
};

constexpr int BOARD_SIZE = 8;
using Board = std::array<std::array<Figure, BOARD_SIZE>, BOARD_SIZE>;

std::wstring figureToString(Figure figure);
