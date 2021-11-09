#pragma once
#include "Commons.hpp"

class Chess
{
public:
    void move(std::string &);
    bool isPossibleMove(std::string &);
    Board getBoard();
};