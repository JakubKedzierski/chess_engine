#include <gtest/gtest.h>
#include "SimpleArrayChess.hpp"

TEST(ArrayChessMoveTests, TestCasualPawnMoves)
{
    SimpleArrayChess chess;
    ASSERT_EQ(chess.getFigure(4,1), Figure::WPawn);
    ASSERT_EQ(chess.getFigure("e2"), Figure::WPawn);
    std::string move = "e4";
    chess.move(move);
    ASSERT_EQ(chess.getFigure("e4"), Figure::WPawn);
    ASSERT_EQ(chess.getFigure("e2"), Figure::Empty);
    
    ASSERT_EQ(chess.getFigure(4,6), Figure::BPawn);
    ASSERT_EQ(chess.getFigure("e7"), Figure::BPawn);
    move = "e5";
    chess.move(move);
    ASSERT_EQ(chess.getFigure("e5"), Figure::BPawn);
    ASSERT_EQ(chess.getFigure("e7"), Figure::Empty);
}