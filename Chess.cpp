#include "Chess_Update.h"


//
//	//--- To check the rules of the King piece ---
//	void moveKing(int beginningx, int beginningy)
//	{
//		cout << "Please enter the place you want to move your King" << endl;
//		cout << "ROW [Enter Letter]: ";
//		cin >> rowletter;
//		cout << "COLUMN [Enter Number] ";
//		cin >> endy;
//		int endx = getlocationx(rowletter);
//
//
//	}
//
//	//--- To check the rules of the Queen piece ---
//	void moveQueen(int beginningx, int beginningy)
//	{
//		cout << "Please enter the place you want to move your Queen" << endl;
//		cout << "ROW [Enter Letter]: ";
//		cin >> rowletter;
//		cout << "COLUMN [Enter Number] ";
//		cin >> endy;
//		int endx = getlocationx(rowletter);
//
//
//	}
//
//	//--- To check the rules of the Rook piece ---
//	void moveRook(int beginningx, int beginningy)
//	{
//		cout << "Please enter the place you want to move your Rook" << endl;
//		cout << "ROW [Enter Letter]: ";
//		cin >> rowletter;
//		cout << "COLUMN [Enter Number] ";
//		cin >> endy;
//		int endx = getlocationx(rowletter);
//
//
//	}
//
//	//--- To check the rules of the Knight piece ---
//	void moveKnights(int beginningx, int beginningy)
//	{
//		cout << "Please enter the place you want to move your Knights" << endl;
//		cout << "ROW [Enter Letter]: ";
//		cin >> rowletter;
//		cout << "COLUMN [Enter Number] ";
//		cin >> endy;
//		int endx = getlocationx(rowletter);
//
//
//	}
//
//	//--- To check the rules of the Bishop piece ---
//	void moveBishop(int beginningx, int beginningy)
//	{
//		cout << "Please enter the place you want to move your Bishop" << endl;
//		cout << "ROW [Enter Letter]: ";
//		cin >> rowletter;
//		cout << "COLUMN [Enter Number] ";
//		cin >> endy;
//		int endx = getlocationx(rowletter);
//
//
//	}
//
//	//--- To check the rules of the Pawn piece ---
//	void movePawn(int beginningx, int beginningy)
//	{
//		cout << "Please enter the place you want to move your Pawn" << endl;
//		cout << "ROW [Enter Letter]: ";
//		cin >> rowletter;
//		cout << "COLUMN [Enter Number] ";
//		cin >> endy;
//		int endx = getlocationx(rowletter);
//		if (((endy - beginningy == 1) || (beginningy == 1 && endy - beginningy == 2)) && (endx - beginningx == 0))
//		{
//			Gameboard[endx][endy] = P1Pawns;
//			Gameboard[beginningx][beginningy] = Blank;
//		}
//	}
//

//
//	//--- Figures out what Piece the user entered to check the rules ---
//	void checkpiece(int beginningx, int beginningy) //--- Future: make it for two players 
//	{
//		if (Gameboard[beginningx][beginningy] == P1Pawns)
//		{
//			movePawn(beginningx, beginningy);
//		}
//
//		if (Gameboard[beginningx][beginningy] == P1Bishop)
//		{
//			moveBishop(beginningx, beginningy);
//		}
//
//		if (Gameboard[beginningx][beginningy] == P1King)
//		{
//			moveKing(beginningx, beginningy);
//		}
//
//		if (Gameboard[beginningx][beginningy] == P1Queen)
//		{
//			moveQueen(beginningx, beginningy);
//		}
//
//		if (Gameboard[beginningx][beginningy] == P1Knights)
//		{
//			moveKnights(beginningx, beginningy);
//		}
//
//		if (Gameboard[beginningx][beginningy] == P1Rook)
//		{
//			moveRook(beginningx, beginningy);
//		}
//
//
//		else
//		{
//			cout << "Sorry there is no piece in this spot!" << endl;
//		}
//	}
//
//
//
//};
//
//

void main()
	{
	Chess ch;
	ch.display();
	system("PAUSE");
	}