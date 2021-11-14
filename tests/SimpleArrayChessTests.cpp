#include <gtest/gtest.h>
#include "SimpleArrayChess.hpp"

TEST(AlgebricNotationMoves, TestCasualPawnMoves)
{
    SimpleArrayChess chess;
    ASSERT_EQ(chess.getFigure(4, 1), Figure::WPawn);
    ASSERT_EQ(chess.getFigure("e2"), Figure::WPawn);
    std::string move = "e4";
    chess.move(move);
    ASSERT_EQ(chess.getFigure("e4"), Figure::WPawn);
    ASSERT_EQ(chess.getFigure("e2"), Figure::Empty);

    ASSERT_EQ(chess.getFigure(4, 6), Figure::BPawn);
    ASSERT_EQ(chess.getFigure("e7"), Figure::BPawn);
    move = "e5";
    chess.move(move);
    ASSERT_EQ(chess.getFigure("e5"), Figure::BPawn);
    ASSERT_EQ(chess.getFigure("e7"), Figure::Empty);

    move = "h3";
    chess.move(move);
    ASSERT_EQ(chess.getFigure("h3"), Figure::WPawn);

    move = "h5";
    chess.move(move);
    ASSERT_EQ(chess.getFigure("h5"), Figure::BPawn);

    move = "h4";
    chess.move(move);
    ASSERT_EQ(chess.getFigure("h4"), Figure::WPawn);
}

TEST(AlgebricNotationMoves, TestCasualKnightMoves)
{
    SimpleArrayChess chess;
    ASSERT_EQ(chess.getFigure("b1"), Figure::WKnight);
    std::string move = "Sc3";
    chess.move(move);
    ASSERT_EQ(chess.getFigure("c3"), Figure::WKnight);

    move = "Sc6";
    chess.move(move);
    ASSERT_EQ(chess.getFigure("c6"), Figure::BKnight);

    move = "Sf3";
    chess.move(move);
    ASSERT_EQ(chess.getFigure("f3"), Figure::WKnight);

    move = "Se5";
    chess.move(move);
    ASSERT_EQ(chess.getFigure("e5"), Figure::BKnight);

    move = "Se4";
    chess.move(move);
    ASSERT_EQ(chess.getFigure("e4"), Figure::WKnight);

    move = "Sh6";
    chess.move(move);
    ASSERT_EQ(chess.getFigure("h6"), Figure::BKnight);

    move = "Seg5";
    chess.move(move);
    ASSERT_EQ(chess.getFigure("g5"), Figure::WKnight);

    move = "Seg4";
    chess.move(move);
    ASSERT_EQ(chess.getFigure("g4"), Figure::BKnight);

    ASSERT_EQ(chess.getFigure("c3"), Figure::Empty);
    ASSERT_EQ(chess.getFigure("e5"), Figure::Empty);
    ASSERT_EQ(chess.getFigure("e4"), Figure::Empty);
}