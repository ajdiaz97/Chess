#include <iostream>
#include <string>
#include <vector>
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
	bool pawnValid(int startX, int startY, int endX, int endY, int player);

	//--- For Rooks
	bool rookValid(int startX, int startY, int endX, int endY, int player);

	//--- For Knights
	bool knightValid(int startX, int startY, int endX, int endY, int player);

	//--- For Bishops ---
	bool bishopValid(int startX, int startY, int endX, int endY, int player);

	//--- For King ---
	bool kingValid(int startX, int startY, int endX, int endY, int player);

	//--- For Queen ---
	bool queenValid(int startX, int startY, int endX, int endY, int player);

	//--- Prints the Board ---
	void display();

	//--- Makes sure that the input isnt an empty spot for the start point ---
	bool youCanS(string input);

	//--- Makes sure that the input isnt an putting pieces in his own spot ---
	bool youCanE(string input, int player);

	//--- Gets the information for the checksValidity function ---
	vector<string> getInfo(string input, string input2, int player);
};


