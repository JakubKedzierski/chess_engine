#pragma once
#include "Chess.hpp"

class SimpleArrayChess : public Chess
{
private:
    Board board;
    Turn turn;
    inline void turnChange();

public:
    Board getBoard() override;
    Figure getFigure(const int x, const int y) const;
    Figure getFigure(const std::string &) const;
    void move(std::string &moveEncoding) override;
    void move(int x1, int y1, int x2, int y2);
    bool isPossibleMove(std::string &) override;
    SimpleArrayChess();
};