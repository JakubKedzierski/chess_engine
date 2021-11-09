#include "SimpleArrayChess.hpp"
#include "Utils.hpp"

void printBoardToConsole(Board board)
{
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            std::cout << figureToString(board[i][j]);
        }
    }
}

int main()
{
    std::unique_ptr<Chess> chess = std::make_unique<SimpleArrayChess>(); 
    chess->

}