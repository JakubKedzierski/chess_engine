#pragma once
#include "Chess.hpp"

class SimpleArrayChess : public Chess
{
private:
    Board board;
    void move(int x, int y);
public:
    Board getBoard() override;
    Figure getFigure(int x, int y);
    void move(std::string & moveEncoding) override;
    bool isPossibleMove(std::string &) override;
    SimpleArrayChess();
};