/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} 
		virtual ~TicTacToeBoardTest(){} 
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, smoke_test)
{
    ASSERT_TRUE(true);
}

/*   Testing getPiece(int, int)   */

TEST(TicTacToeBoardTest, simpletest)
{
	TicTacToeBoard board;
	Piece boardPiece = board.getPiece(0, 0); 
	ASSERT_EQ(boardPiece, Blank);
}

TEST(TicTacToeBoardTest, anothersimpletest)
{
	TicTacToeBoard board;
	Piece boardPiece = board.getPiece(2,2); 
	ASSERT_EQ(boardPiece, Blank); 
}

TEST(TicTacToeBoardTest, outOfBoundtest)
{
	TicTacToeBoard board; 
	Piece boardPiece = board.getPiece(3,4);
	ASSERT_EQ(boardPiece, Invalid);
}

TEST(TicTacToeBoardTest, middleplacetest)
{
	TicTacToeBoard board; 
	Piece boardPiece = board.getPiece(1,1);
	ASSERT_EQ(boardPiece, Blank);
}

TEST(TicTacToeBoardTest, toprighttest)
{
	TicTacToeBoard board; 
	Piece boardPiece = board.getPiece(0, 2);
	ASSERT_EQ(boardPiece, Blank);
}

TEST(TicTacToeBoardTest, SuperoutofBound)
{
	TicTacToeBoard board; 
	Piece boardPiece = board.getPiece(3213,4324);
	ASSERT_EQ(boardPiece, Invalid);
}

/*   Testing toggleTurn()   */

TEST(TicTacToeBoardTest, simpleTurnSwitch)
{
	TicTacToeBoard board; 
	Piece boardTurn = board.toggleTurn(); 
	ASSERT_EQ(boardTurn, O); 
}

TEST(TicTacToeBoardTest, twicesimpleTurnSwitch)
{
	TicTacToeBoard board; 
	Piece boardTurn = board.toggleTurn(); 
	boardTurn = board.toggleTurn(); 
	ASSERT_EQ(boardTurn, X); 
}