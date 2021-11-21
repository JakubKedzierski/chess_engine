#pragma once
#include <vector>
#include <utility>
#include <sstream>
#include "Commons.hpp"

class SimpleArrayChess
{
private:
    Board board;
    Turn turn;
    inline void turnChange();

public:
    Board getBoard();
    Figure getFigure(const int x, const int y) const;
    Figure getFigure(const std::string &) const;
    Turn getTurn();
    bool isInBoundries(int row, int column);
    void move(int x1, int y1, int x2, int y2);
    void move(const Move &move);
    SimpleArrayChess();
};