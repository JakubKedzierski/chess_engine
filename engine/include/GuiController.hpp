#pragma once
#include "Commons.hpp"
#include "SimpleArrayChess.hpp"
#include <iomanip>
#include <io.h>
#include <fcntl.h>

class GuiController
{
private:
    SimpleArrayChess chess;

public:
    GuiController() = default;
    void printBoardToConsole(Board board);
    void gameLoop();
};