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

	//--- Gameboard ---
	string gameBoard[8][8];
public:
	Chess();
	void display();
};


