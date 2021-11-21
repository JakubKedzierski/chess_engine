#pragma once
#include "Commons.hpp"

class Chess
{
public:
    virtual ~Chess() = default;
    virtual void move(std::string &) = 0;
    virtual Board getBoard() = 0;
};