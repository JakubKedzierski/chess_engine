#pragma once
#include "Chess.hpp"
#include <vector>
#include <utility>
#include <sstream>

class SimpleArrayChess : public Chess
{
private:
    Board board;
    Turn turn;
    NotationType notationType;
    inline void turnChange();
    bool isInBoundries(int row, int column);
    Move decodeKnightMove(const std::string &moveEncoding);
    Move decodePawnMove(const std::string &moveEncoding);
    Move decodeRookMove(const std::string &moveEncoding);

public:
    Board getBoard() override;
    Figure getFigure(const int x, const int y) const;
    Figure getFigure(const std::string &) const;
    void move(std::string &moveEncoding) override;
    void move(int x1, int y1, int x2, int y2);
    SimpleArrayChess();
};