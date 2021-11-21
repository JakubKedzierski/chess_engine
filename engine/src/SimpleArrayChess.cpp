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
Turn SimpleArrayChess::getTurn()
{
    return turn;
}

Board SimpleArrayChess::getBoard()
{
    return this->board;
}

Figure SimpleArrayChess::getFigure(const int column, const int row) const
{
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

bool SimpleArrayChess::isInBoundries(int row, int column)
{
    return (row >= 0 && row < BOARD_SIZE) && (column >= 0 && column < BOARD_SIZE);
}

void SimpleArrayChess::move(int column1, int row1, int column2, int row2)
{
    board[row2][column2] = board[row1][column1];
    board[row1][column1] = Figure::Empty;
    this->turnChange();
}

void SimpleArrayChess::move(const Move &move)
{
    board[move.row2][move.column2] = board[move.row1][move.column1];
    board[move.row1][move.column1] = Figure::Empty;
    this->turnChange();
}