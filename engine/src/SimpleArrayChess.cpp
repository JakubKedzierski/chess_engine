#include "SimpleArrayChess.hpp"

SimpleArrayChess::SimpleArrayChess()
{
    board = {Figure::WRook, Figure::WKnight, Figure::WBishop, Figure::WQueen, Figure::WKing, Figure::WBishop, Figure::WKnight, Figure::WRook,
             Figure::WPawn, Figure::WPawn, Figure::WPawn, Figure::WPawn, Figure::WPawn, Figure::WPawn, Figure::WPawn, Figure::WPawn,
             Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty,
             Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty,
             Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty,
             Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty,
             Figure::BPawn, Figure::BPawn, Figure::BPawn, Figure::BPawn, Figure::BPawn, Figure::BPawn, Figure::BPawn, Figure::BPawn,
             Figure::BRook, Figure::BKnight, Figure::BBishop, Figure::BQueen, Figure::BKing, Figure::BBishop, Figure::BKnight, Figure::BRook};
    turn = Turn::White;
}

Board SimpleArrayChess::getBoard()
{
    return this->board;
}

Figure SimpleArrayChess::getFigure(const int column, const int row) const
{
    // row - 1,2,3 column - a,b,c
    return this->board[row][column];
}

Figure SimpleArrayChess::getFigure(const std::string &moveEncoding) const
{
    const auto column = static_cast<int>(moveEncoding[0]) - 96 - 1;
    const auto row = static_cast<int>(moveEncoding[1]) - 48 - 1;
    return this->getFigure(column, row);
}

inline void SimpleArrayChess::turnChange()
{
    turn = (turn == Turn::White ? Turn::Black : Turn::White);
}

void SimpleArrayChess::move(int column1, int row1, int column2, int row2)
{
    board[row2][column2] = board[row1][column1];
    board[row1][column1] = Figure::Empty;
    this->turnChange();
}

void SimpleArrayChess::move(std::string &moveEncoding) // should throw invalid argument when wrogn move
{
    //King, Queen, Rook, Bishop, kNight
    const auto moveEncodingSize = moveEncoding.size();

    int row1 = 0, row2 = 0, column1 = 0, column2 = 0;

    if (moveEncodingSize == 2)
    {
        column2 = static_cast<int>(moveEncoding[0]) - 96 - 1;
        row2 = static_cast<int>(moveEncoding[1]) - 48 - 1;
        column1 = column2;
        if (turn == Turn::White && board[row2 - 1][column2] == Figure::WPawn)
        {
            row1 = row2 - 1;
        }
        else if (turn == Turn::White && board[row2 - 2][column2] == Figure::WPawn)
        {
            row1 = row2 - 2;
        }
        else if (turn == Turn::Black && board[row2 + 1][column2] == Figure::BPawn)
        {
            row1 = row2 + 1;
        }
        else if (turn == Turn::Black && board[row2 + 2][column2] == Figure::BPawn)
        {
            row1 = row2 + 2;
        }
    }

    move(column1, row1, column2, row2);
}

bool SimpleArrayChess::isPossibleMove(std::string &)
{
    return true;
}