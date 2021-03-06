#include "GuiController.hpp"

GuiController::GuiController() : notation()
{
    chess = std::make_shared<SimpleArrayChess>();
    notation.setChessState(chess);
}

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

void GuiController::gameLoop(int argc, char *argv[])
{
    while (true)
    {
        printBoardToConsole(chess->getBoard());
        std::string move;
        std::cin >> move;
        chess->move(notation.decodeMove(move));
    }

}
