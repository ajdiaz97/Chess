#include <iostream>
using namespace std;
#define RESTARTGAME 0
#define PLAYER1 1
#define PLAYER2 2
//---------------
//Player 1 Pieces
int P1King = 1000;
int P1Queen = 999;
int P1Rook = 998;
int P1Bishop = 997;
int P1Knights = 996;
int P1Pawns = 995;
//Player 2 Pieces
int P2King = 2000;
int P2Queen = 1999;
int P2Rook = 1998;
int P2Bishop = 1997;
int P2Knights = 1996;
int P2Pawns = 1995;
//-----------------

//--- Makes the whole board 0 to show that there is no piece there --- 
void initialize_board(int arr[8][8])
	{
	for(int xx = 0; xx < 8; xx++)
		{
		for(int yy = 0; yy < 8; yy++)
			{
			arr[xx][yy] = 0;
			}
		}
	//--- Beginning places for the pieces ---
	/* Player 1 */ 
	arr[3][0] = P1King, arr[4][0] = P1Queen, arr[0][0] = P1Rook, arr[7][0] = P1Rook, arr[1][0] = P1Knights, arr[6][0] = P1Knights, arr[2][0] = P1Bishop, arr[5][0] = P1Bishop;
	for(int xx = 0; xx < 8; xx++)
		arr[xx][1] = P1Pawns;
	
	/* Player 2 */
	arr[3][7] = P2King, arr[4][7] = P2Queen, arr[0][7] = P2Rook, arr[7][7] = P2Rook, arr[1][7] = P2Knights, arr[6][7] = P2Knights, arr[2][7] = P2Bishop, arr[5][7] = P2Bishop;
	for(int xx = 0; xx < 8; xx++)
		arr[xx][6] = P2Pawns;
	}

//--- Prints the board ---
void print_board(int arr[8][8])
	{
	int counter = 1;
	cout << "\t" << "   A    B    C    D    E    F    G    H" << endl;
	for(int xx = 0; xx < 8; xx++)
		{
		cout << "\t"<< counter < " ";
		for(int yy = 0; yy < 8; yy++)
			{
			if(arr[yy][xx] == 0)
				cout << "[" << "   " << "]";

			if(arr[yy][xx] == P1King) 
				cout << "[" << "K1 " << "]";

			if(arr[yy][xx] == P1Queen) 
				cout << "[" << "Q1 " << "]";

			if(arr[yy][xx] == P1Rook) 
				cout << "[" << "R1 " << "]";

			if(arr[yy][xx] == P1Bishop) 
				cout << "[" << "B1 " << "]";

			if(arr[yy][xx] == P1Knights) 
				cout << "[" << "Kn1" << "]";

			if(arr[yy][xx] == P1Pawns) 
				cout << "[" << "P1 " << "]";

			if(arr[yy][xx] == P2King) 
				cout << "[" << "K2 " << "]";
			
			if(arr[yy][xx] == P2Queen) 
				cout << "[" << "Q2 " << "]";
			
			if(arr[yy][xx] == P2Rook) 
				cout << "[" << "R2 " << "]";

			if(arr[yy][xx] == P2Bishop) 
				cout << "[" << "B2 " << "]";

			if(arr[yy][xx] == P2Knights) 
				cout << "[" << "Kn2" << "]";

			if(arr[yy][xx] == P2Pawns) 
				cout << "[" << "P2 " << "]";
			}
		cout << endl;
		counter++;
		}
	
	}	

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

//Gets the piece that is the user puts the locations
int getchesspiece(int arr[8][8] ,int locationx, int locationy)
	{
	int value = arr[locationx][locationy];
	return value;
	}


bool moveAllowed(int arr[8][8], int beginninglocationx, int beginninglocationy, int endlocationx, int endlocationy, int chesspiece, int turn)
	{
	cout << endlocationx - beginninglocationx << endl;
	cout << endlocationy - beginninglocationy << endl;

	if((turn == PLAYER1) && (chesspiece <= 1000))
		{

		//--- If its a Rook ---
		if(chesspiece == 998)
			{
			//--- Makes sure that the Rook moves in a straight line ---
			if((endlocationx - beginninglocationx == 0) || (endlocationy - beginninglocationy == 0))
				{
				arr[beginninglocationx][beginninglocationy] = 0;
				arr[endlocationx][endlocationy] = 998;
				}

			}

		return true;
		}
	
	if((turn == PLAYER2) && (chesspiece > 1000 && chesspiece <=2000))
		{
		return true;
		}

	return false;
	}



void main()
	{
	//--- Variables to be used for player 1 ---
	char xvalue, xvalue2; /*For the row letter || Will be converted into */ 	int xxvalue, xxvalue2;
	int yvalue, yvalue2; /* For the column number */

	//--- Variables to be used for player 2 ---
	char x2value, x2value2; /*For the row letter || Will be converted into */ 	int x2xvalue, x2xvalue2;
	int y2value, y2value2; /* For the column number */
	//---------------------------------------------------------

	//--- Universal Variables ---
	int piece; 
	int Gameboard[8][8]; //Creates the board 
	int turn = PLAYER1;
	bool flag; 

	//---Creates the board pieces and places them ---
	initialize_board(Gameboard);

	//--- Prints the board ---
	print_board(Gameboard);
	for(;;)
		{

		//--- For player 1
		if(turn == PLAYER1)
			{
			cout << "Player 1" << endl;
			//--- Asks the user what piece they want to move ---
			cout << "What piece would you like to move?" << endl;
			cout << "Row [Insert Letter]: ";
			cin >> xvalue;
			cout << "Column [Insert Number]: ";
			cin >> yvalue;
			yvalue--;
			xxvalue = getlocationx(xvalue);

			cout << xxvalue << yvalue << endl;

			piece = getchesspiece(Gameboard, xxvalue, yvalue);

			cout << piece << endl;
			//----
			cout << "Where would you like to move the ";
			cout << "Row [Insert Letter: ";
			cin >> xvalue2;
			cout << "Column [Insert Number]: ";
			cin >> yvalue2;
			xxvalue2 = getlocationx(xvalue2);
			yvalue2--;
			cout << xxvalue2 << yvalue2 << endl;
			flag = moveAllowed(Gameboard,xxvalue,yvalue,xvalue2,yvalue2,piece,turn);
			print_board(Gameboard);
			}

		break;
		//--- For player 2
		if(turn == PLAYER2)
			{
			cout << "Player 2" << endl;
			//--- Asks the user what piece they want to move ---
			cout << "What piece would you like to move?" << endl;
			cout << "Row [Insert Letter]: ";
			cin >> x2value;
			cout << "Column [Insert Number]: ";
			cin >> y2value;
			y2value--;
			x2xvalue = getlocationx(x2value);

			cout << x2xvalue << y2value << endl;

			piece = getchesspiece(Gameboard, x2xvalue, y2value);

			cout << piece << endl;
			//----
			cout << "Where would you like to move the ";
			cout << "Row [Insert Letter: ";
			cin >> x2value2;
			cout << "Column [Insert Number]: ";
			cin >> y2value2;
			x2xvalue2 = getlocationx(x2value2);
			y2value2--;
			cout << x2xvalue2 << y2value2 << endl;
			turn = PLAYER1;
			}
		}
	}
