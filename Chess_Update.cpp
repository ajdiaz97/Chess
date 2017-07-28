#include "Chess_Update.h"



Chess::Chess()
	{
	P1King = "K1 ";
	P1Queen = "Q1 ";
	P1Rook = "R1 ";
	P1Bishop = "B1 ";
	P1Knights = "KN1";
	P1Pawns = "P1 ";
	//Player 2 Pieces
	P2King = "K2 ";
	P2Queen = "Q2 ";
	P2Rook = "R2 ";
	P2Bishop = "B2 ";
	P2Knights = "KN2";
	P2Pawns = "P2 ";
	//-----------------
	Blank = "   ";


	//--- Initializes the Board ---
	for (int yy = 0; yy < 8; yy++)
		{
		for (int xx = 0; xx < 8; xx++)
			{
			gameBoard[yy][xx] = Blank;
			}
		}

	//--- Places the Player 2 pieces ---
	gameBoard[3][7] = P2King, gameBoard[4][7] = P2Queen, gameBoard[0][7] = P2Rook, gameBoard[7][7] = P2Rook, gameBoard[1][7] = P2Knights, gameBoard[6][7] = P2Knights, gameBoard[2][7] = P2Bishop, gameBoard[5][7] = P2Bishop;
	for (int xx = 0; xx < 8; xx++)
		gameBoard[xx][6] = P2Pawns;
	//--- Places the Player 1 pieces ---
	gameBoard[3][0] = P1King, gameBoard[4][0] = P1Queen, gameBoard[0][0] = P1Rook, gameBoard[7][0] = P1Rook, gameBoard[1][0] = P1Knights, gameBoard[6][0] = P1Knights, gameBoard[2][0] = P1Bishop, gameBoard[5][0] = P1Bishop;
	for (int xx = 0; xx < 8; xx++)
		gameBoard[xx][1] = P1Pawns;
	}

//--- Prints the board ---
void Chess :: display()
	{
		int counter = 0;
		cout << "\t" << "   A    B    C    D    E    F    G    H" << endl;
		for (int xx = 0; xx < 8; xx++)
			{
			cout << "\t" << counter << " ";
			
			for (int yy = 0; yy < 8; yy++)
				{
				cout << "[" << gameBoard[yy][xx] << "]";
				}
			cout << endl;
			counter++;
			}
	}

void Chess::makeMove(int player)
	{

	}

bool Chess::checksValidity(string piece, int startX, int startY, int endX, int endY, int player)
	{
	if (piece == P1Pawns)
		return pawnValid(1, startX, startY, endX, endY);
	else if (piece == P2Pawns)
		return pawnValid(2, startX, startY, endX, endY);
	else if (piece == P1Rook)
		return rookValid(1, startX, startY, endX, endY);
	else if (piece == P2Bishop)
		return rookValid(2, startX, startY, endX, endY);
	else if (piece == P1Knights)
		return knightValid(1, startX, startY, endX, endY);
	else if (piece == P2Knights)
		return knightValid(2, startX, startY, endX, endY);
	else if (piece == P1King)
		return kingValid(1, startX, startY, endX, endY);
	else if (piece == P2King)
		return kingValid(2, startX, startY, endX, endY);
	else if (piece == P1Queen)
		return queenValid(1, startX, startY, endX, endY);
	else if (piece == P2Queen)
		return queenValid(2, startX, startY, endX, endY);
	else if (piece == P1Bishop)
		return bishopValid(1, startX, startY, endX, endY);
	else if (piece == P2Bishop)
		return bishopValid(2, startX, startY, endX, endY);
	else
		return false;
	}

bool Chess::pawnValid(int player, int startX, int startY, int endX, int endY)
	{
	if (player == 1)
		{

		}
	else
		{

		}
	}
bool Chess::rookValid(int player, int startX, int startY, int endX, int endY)
	{
	if (player == 1)
		{

		}
	else
		{

		}
	}

bool Chess :: knightValid(int player, int startX, int startY, int endX, int endY)
	{
	if (player == 1)
		{

		}
	else
		{

		}
	}
bool Chess :: bishopValid(int player, int startX, int startY, int endX, int endY)
	{
	if (player == 1)
		{

		}
	else
		{

		}
	}
bool Chess :: kingValid(int player, int startX, int startY, int endX, int endY)
	{
	if (player == 1)
		{

		}
	else
		{

		}
	}
bool Chess::queenValid(int player, int startX, int startY, int endX, int endY)
	{
	if (player == 1)
		{

		}
	else
		{

		}
	}
