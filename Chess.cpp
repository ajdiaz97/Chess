#include <iostream>
#include <string>
using namespace std;

//---------------
//Player 1 Pieces
string P1King = "K1 ";
string P1Queen = "Q1 ";
string P1Rook = "R1 ";
string P1Bishop = "B1 ";
string P1Knights = "KN1";
string P1Pawns = "P1 ";
//Player 2 Pieces
string P2King = "K2 ";
string P2Queen = "Q2 ";
string P2Rook = "R2 ";
string P2Bishop = "B1 ";
string P2Knights = "KN2";
string P2Pawns = "P2 ";
//-----------------
string Blank = "   ";



//--- Since the X axis is a letter it will convert it into a integer for the array ---
int getlocationx(char value)
	{
	if(value == 'A' || value == 'a')
		return 0;
	if(value == 'B' || value == 'b')
		return 1;
	if(value == 'C' || value == 'c')
		return 2;
	if(value == 'D' || value == 'd')
		return 3;
	if(value == 'E' || value == 'e')
		return 4;
	if(value == 'F' || value == 'f')
		return 5;
	if(value == 'G' || value == 'g')
		return 6;
	if(value == 'H' || value == 'h')
		return 7;
	}





class Chess
	{
	private:
		string Gameboard[8][8];
		char rowletter;
		int endy;
	public:

		//--- Places the Pieces for player 1 ---
		Chess()
			{
			for(int yy = 0; yy < 8; yy++)
			{
			for(int xx = 0; xx < 8; xx++)
				{
				Gameboard[yy][xx] = Blank;
				}
			}
			
			Gameboard[3][7] = P2King, Gameboard[4][7] = P2Queen, Gameboard[0][7] = P2Rook, Gameboard[7][7] = P2Rook, Gameboard[1][7] = P2Knights, Gameboard[6][7] = P2Knights, Gameboard[2][7] = P2Bishop, Gameboard[5][7] = P2Bishop;
			for(int xx = 0; xx < 8; xx++)
				Gameboard[xx][6] = P2Pawns;

			Gameboard[3][0] = P1King, Gameboard[4][0] = P1Queen, Gameboard[0][0] = P1Rook, Gameboard[7][0] = P1Rook, Gameboard[1][0] = P1Knights, Gameboard[6][0] = P1Knights, Gameboard[2][0] = P1Bishop, Gameboard[5][0] = P1Bishop;
			for(int xx = 0; xx < 8; xx++)
				Gameboard[xx][1] = P1Pawns;
			}

		void moveKing(int beginningx, int beginningy);
		void moveQueen(int beginningx, int beginningy);
		void moveRook(int beginningx, int beginningy);
		void moveKnights(int beginningx, int beginningy);


		void moveBishop(int beginningx, int beginningy)
			{
			cout << "Please enter the place you want to move your Bishop" << endl;
			cout << "ROW [Enter Letter]: ";
			cin >> rowletter;
			cout << "COLUMN [Enter Number] ";
			cin >> endy;
			int endx = getlocationx(rowletter);


			}


		void movePawn(int beginningx, int beginningy)
			{
			cout << "Please enter the place you want to move your Pawn" << endl;
			cout << "ROW [Enter Letter]: ";
			cin >> rowletter;
			cout << "COLUMN [Enter Number] ";
			cin >> endy;
			int endx = getlocationx(rowletter);
			if(((endy - beginningy == 1) || (beginningy == 1 && endy - beginningy == 2)) && (endx - beginningx == 0))
				{
				Gameboard[endx][endy] = P1Pawns;
				Gameboard[beginningx][beginningy] = Blank;
				}
			}

		void display()
			{
			int counter = 0;
			cout << "\t" << "   A    B    C    D    E    F    G    H" << endl;
			for(int xx = 0; xx < 8; xx++)
				{
				cout << "\t"<< counter < " ";
				for(int yy = 0; yy < 8; yy++)
					{
					cout << "[" << Gameboard[yy][xx] << "]";
					}
				cout << endl;
				counter++;
				}
			}
		
		//------ Fix --------------
		void checkpiece(int beginningx, int beginningy)
			{
			if(Gameboard[beginningx][beginningy] == P1Pawns)
				{
				movePawn(beginningx, beginningy);
				}
			
			if(Gameboard[beginningx][beginningy] == P1Bishop)
				{
				moveBishop(beginningx, beginningy);
				}


			}




	};


void main()
	{
	int beginx, beginy;
	char letterx;
	Chess Game;
	Game.display();
	cout << "Please " << endl;
	cout << "ROW [Enter Letter]: ";
	cin >> letterx;
	cout << "COLUMN [Enter Number] ";
	cin >> beginy;
	beginx = getlocationx(letterx);
	Game.checkpiece(beginx, beginy);
	
	Game.display();

	}


