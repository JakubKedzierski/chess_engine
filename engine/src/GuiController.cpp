#include "GuiController.hpp"

void GuiController::printBoardToConsole(Board board)
{
    for (int i = BOARD_SIZE - 1; i >= 0; i--)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            std::wcout << std::setw(4) << figureToString(board[i][j]);
        }
        std::wcout << std::endl;
    }
}
