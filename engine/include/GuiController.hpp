#pragma once
#include "Commons.hpp"
#include "SimpleArrayChess.hpp"
#include <iomanip>
#include <io.h>
#include <fcntl.h>
#include "ChessNotation.hpp"

class GuiController
{
private:
    std::shared_ptr<SimpleArrayChess> chess;
    ChessNotation notation;

public:
    GuiController();
    void printBoardToConsole(Board board);
    void gameLoop();
};