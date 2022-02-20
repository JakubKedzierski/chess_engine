#include <gtest/gtest.h>
#include "SimpleArrayChess.hpp"
#include "ChessNotation.hpp"

// AlgebricNotationMoves should not test moves that are on board but moves translated to numeric notation
// one test for game, more tests for notation

TEST(AlgebricNotationMoves, TestCasualPawnMoves)
{
    ChessNotation notation;
    std::shared_ptr<SimpleArrayChess> chess = std::make_shared<SimpleArrayChess>();
    notation.setChessState(chess);

    std::string move = "e4";
    Move lhs = notation.decodeMove(move);
    Move rhs{.column1 = 4, .row1 = 1, .column2 = 4, .row2 = 3};
    ASSERT_EQ(lhs, rhs);
    chess->move(lhs);

    move = "e5";
    lhs = notation.decodeMove(move);
    rhs = Move{.column1 = 4, .row1 = 6, .column2 = 4, .row2 = 4};
    ASSERT_EQ(lhs, rhs);
    chess->move(lhs);

    move = "f4";
    lhs = notation.decodeMove(move);
    rhs = Move{.column1 = 5, .row1 = 1, .column2 = 5, .row2 = 3};
    ASSERT_EQ(lhs, rhs);
    chess->move(lhs);

    move = "exf4";
    lhs = notation.decodeMove(move);
    rhs = Move{.column1 = 4, .row1 = 4, .column2 = 5, .row2 = 3};
    ASSERT_EQ(lhs, rhs);
}

TEST(SimpleChessTestsSuite, TestCasualPawnMoves)
{
    ChessNotation notation;
    std::shared_ptr<SimpleArrayChess> chess = std::make_shared<SimpleArrayChess>();
    notation.setChessState(chess);

    std::string move = "e4";
    chess->move(notation.decodeMove(move));

    ASSERT_EQ(chess->getFigure("e4"), Figure::WPawn);
    ASSERT_EQ(chess->getFigure("e2"), Figure::Empty);

    ASSERT_EQ(chess->getFigure(4, 6), Figure::BPawn);
    ASSERT_EQ(chess->getFigure("e7"), Figure::BPawn);
    move = "e5";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("e5"), Figure::BPawn);
    ASSERT_EQ(chess->getFigure("e7"), Figure::Empty);

    move = "h3";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("h3"), Figure::WPawn);

    move = "h5";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("h5"), Figure::BPawn);

    move = "h4";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("h4"), Figure::WPawn);

    move = "g5";
    chess->move(notation.decodeMove(move));
    move = "hxg5";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("g5"), Figure::WPawn);
}

TEST(AlgebricNotationMoves, TestCasualKnightMoves)
{
    ChessNotation notation;
    std::shared_ptr<SimpleArrayChess> chess = std::make_shared<SimpleArrayChess>();
    notation.setChessState(chess);

    ASSERT_EQ(chess->getFigure("b1"), Figure::WKnight);
    std::string move = "Sc3";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("c3"), Figure::WKnight);

    move = "Sc6";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("c6"), Figure::BKnight);

    move = "Sf3";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("f3"), Figure::WKnight);

    move = "Se5";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("e5"), Figure::BKnight);

    move = "Se4";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("e4"), Figure::WKnight);

    move = "Sh6";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("h6"), Figure::BKnight);

    move = "Seg5";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("g5"), Figure::WKnight);

    move = "Seg4";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("g4"), Figure::BKnight);

    ASSERT_EQ(chess->getFigure("c3"), Figure::Empty);
    ASSERT_EQ(chess->getFigure("e5"), Figure::Empty);
    ASSERT_EQ(chess->getFigure("e4"), Figure::Empty);
}

TEST(AlgebricNotationMoves, TestQueenMoves)
{
    ChessNotation notation;
    std::shared_ptr<SimpleArrayChess> chess = std::make_shared<SimpleArrayChess>();
    notation.setChessState(chess);

    std::string move = "e4";
    chess->move(notation.decodeMove(move));
    move = "e6";
    chess->move(notation.decodeMove(move));
    move = "Hg4";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("g4"), Figure::WQueen);
    ASSERT_EQ(chess->getFigure("d1"), Figure::Empty);

    move = "Hg5";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("g5"), Figure::BQueen);

    move = "Hxg5";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("g5"), Figure::WQueen);
    ASSERT_EQ(chess->getFigure("g4"), Figure::Empty);

    // double queen uncertanity
}

TEST(AlgebricNotationMoves, TestBishopMoves)
{
    ChessNotation notation;
    std::shared_ptr<SimpleArrayChess> chess = std::make_shared<SimpleArrayChess>();
    notation.setChessState(chess);

    std::string move = "e4";
    chess->move(notation.decodeMove(move));
    move = "e5";
    chess->move(notation.decodeMove(move));

    move = "Gc4";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("c4"), Figure::WBishop);
    ASSERT_EQ(chess->getFigure("f1"), Figure::Empty);

    move = "Gc5";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("c5"), Figure::BBishop);
    ASSERT_EQ(chess->getFigure("f8"), Figure::Empty);

    move = "d4";
    chess->move(notation.decodeMove(move));

    move = "Gxd4";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("d4"), Figure::BBishop);
    ASSERT_EQ(chess->getFigure("c5"), Figure::Empty);

    move = "Ge3";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("e3"), Figure::WBishop);
    ASSERT_EQ(chess->getFigure("c1"), Figure::Empty);

    move = "Gxe3";
    chess->move(notation.decodeMove(move));
    ASSERT_EQ(chess->getFigure("e3"), Figure::BBishop);
}
