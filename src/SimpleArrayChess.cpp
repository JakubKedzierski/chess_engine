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
}

Board SimpleArrayChess::getBoard()
{
    return this->board;
}

void SimpleArrayChess::move(int x, int y)
{
}

void SimpleArrayChess::move(std::string &moveEncoding)
{
    //King, Queen, Rook, Bishop, kNight
    const auto moveEncodingSize = moveEncoding.size();
    if (moveEncodingSize == 2)
    {
        const auto column = static_cast<int>(moveEncoding[0]) - 96;
        const auto row = static_cast<int>(moveEncoding[1]) - 48;
    }
}

bool SimpleArrayChess::isPossibleMove(std::string &)
{
    return true;
}