#include "SimpleArrayChess.hpp"
#include "Utils.hpp"
#include <iomanip>
#include <io.h>
#include <fcntl.h>


void printBoardToConsole(Board board)
{
    for (int i = BOARD_SIZE - 1; i >= 0; i--)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            std::wcout << std::setw(4) <<figureToString(board[i][j]); 
        }
        std::wcout << std::endl;
    }
}

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::unique_ptr<Chess> chess = std::make_unique<SimpleArrayChess>();
    printBoardToConsole(chess->getBoard());
}