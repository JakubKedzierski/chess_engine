#pragma once
#include "Chess.hpp"

class SimpleArrayChess : public Chess
{
private:
    Board board;

public:
    Board getBoard() override;
    void move(std::string &) override;
    bool isPossibleMove(std::string &) override;
    SimpleArrayChess();
};