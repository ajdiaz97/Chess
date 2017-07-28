#include <iostream>
#include <string>
using namespace std;


class Chess
{
private:
	//---------------
	//Player 1 Pieces
	string P1King, P1Queen, P1Rook, P1Bishop, P1Knights, P1Pawns;
	//Player 2 Pieces
	string P2King, P2Queen, P2Rook, P2Bishop, P2Knights, P2Pawns;
	//-----------------
	//--- If No Piece is in it ---
	string Blank;

	//--- Names for the players ---
	string name1, name2;
	//--- Gameboard ---
	string gameBoard[8][8];
public:
	Chess();

	//--- Gets the Player number from the void main and then asks for the start piece and the end point. If the point is not valid it will tell the user ---
	void makeMove(int player);

	//--- After getting the start and end position it checks it and sees if it can move there. If it can it returns true and makes the move. If it can't 
	//--- it returns false and sends an error message ---
	bool checksValidity(string piece, int startX, int startY, int endX, int endY, int player);

	//--- For Pawns ---
	bool pawnValid(int player, int startX, int startY, int endX, int endY);

	//--- For Rooks
	bool rookValid(int player, int startX, int startY, int endX, int endY);

	//--- For Knights
	bool knightValid(int player, int startX, int startY, int endX, int endY);

	//--- For Bishops ---
	bool bishopValid(int player, int startX, int startY, int endX, int endY);

	//--- For King ---
	bool kingValid(int player, int startX, int startY, int endX, int endY);

	//--- For Queen ---
	bool queenValid(int player, int startX, int startY, int endX, int endY);

	//--- Prints the Board ---
	void display();
};


