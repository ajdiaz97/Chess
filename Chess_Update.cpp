#include "Chess_Update.h"
#include <sstream>


//--- Turns the letter into a number for the piece selector ---
int getLetterLocation(char let)
	{
	if (let == 'A' || let == 'a')
		return 0;
	else if (let == 'B' || let == 'b')
		return 1;
	else if (let == 'C' || let == 'c')
		return 2;
	else if (let == 'D' || let == 'd')
		return 3;
	else if (let == 'E' || let == 'e')
		return 4;
	else if (let == 'F' || let == 'f')
		return 5;
	else if (let == 'G' || let == 'g')
		return 6;
	else if (let == 'H' || let == 'h')
		return 7;
	else
		return -1;
	}


Chess::Chess()
	{
	//- Player 1 Pieces -
	P1King = "K1 ";
	P1Queen = "Q1 ";
	P1Rook = "R1 ";
	P1Bishop = "B1 ";
	P1Knights = "KN1";
	P1Pawns = "P1 ";
	//- Player 2 Pieces -
	P2King = "K2 ";
	P2Queen = "Q2 ";
	P2Rook = "R2 ";
	P2Bishop = "B2 ";
	P2Knights = "KN2";
	P2Pawns = "P2 ";
	//- No Piece - 
	Blank = "   ";

	//--- Player 1 name ---
	cout << "Hello Player 1! Before we start what is your name?" << endl;
	cin >> name1;
	cout << "Thank you " + name1 + "!" << endl;

	//--- Player 2 name ---
	cout << "Hello Player 2! Before we start what is your name?" << endl;
	cin >> name2;
	cout << "Thank you " + name2 + "!" << endl;

	


	//--- Initializes the Board ---
	for (int yy = 0; yy < 8; yy++)
		{
		for (int xx = 0; xx < 8; xx++)
			{
			gameBoard[yy][xx] = Blank;
			}
		}



	//--- Places the Player 2 pieces ---
	gameBoard[3][7] = P2King,
		gameBoard[4][7] = P2Queen,
			gameBoard[0][7] = P2Rook,
				gameBoard[7][7] = P2Rook, 
					gameBoard[1][7] = P2Knights,
						gameBoard[6][7] = P2Knights, 
							gameBoard[2][7] = P2Bishop, 
								gameBoard[5][7] = P2Bishop;
	
	for (int xx = 0; xx < 8; xx++)
		gameBoard[xx][6] = P2Pawns;

	//--- Places the Player 1 pieces ---
	gameBoard[3][0] = P1King, 
		gameBoard[4][0] = P1Queen, 
			gameBoard[0][0] = P1Rook, 
				gameBoard[7][0] = P1Rook, 
					gameBoard[1][0] = P1Knights, 
						gameBoard[6][0] = P1Knights, 
							gameBoard[2][0] = P1Bishop, 
								gameBoard[5][0] = P1Bishop;

	for (int xx = 0; xx < 8; xx++)
		gameBoard[xx][1] = P1Pawns;
	}
/////////////////////////////////////////////
//--- Remember to make a check to make sure that the user isnt trying to choose the other players piece ---
/////////////////////////////////////////////



//--- Makes sure the user doesnt choose a blank piece ---
bool Chess::youCanS(string input)
	{
	int conv = input[1] - '0'; //- Converts char to int - 
	if (gameBoard[getLetterLocation(input[0])][conv] == Blank)
		return false;
	else
		return true;
	}


bool Chess::youCanE(string input, int player)
	{
	
	int conv = input[1] - '0'; //- Converts char to int -

	//--- If Player 1 makes sure he doesn't place a piece in his own piece ---
	if(player == 1)
		{
		//--- If the piece is blank it is okay to put the piece ---
		if (gameBoard[getLetterLocation(input[0])][conv] == Blank)
			{
			return true;
			}

		//--- False if it's its own piece
		else if (gameBoard[getLetterLocation(input[0])][conv] == P1King ||
					gameBoard[getLetterLocation(input[0])][conv] == P1Queen ||
						gameBoard[getLetterLocation(input[0])][conv] == P1Rook ||
							gameBoard[getLetterLocation(input[0])][conv] == P1Knights ||
								gameBoard[getLetterLocation(input[0])][conv] == P1Bishop ||
									gameBoard[getLetterLocation(input[0])][conv] == P1Pawns)
										{
										return false;
										}
		//--- True if it is not ---
		else if (gameBoard[getLetterLocation(input[0])][conv] == P2King ||
					gameBoard[getLetterLocation(input[0])][conv] == P2Queen ||
						gameBoard[getLetterLocation(input[0])][conv] == P2Rook ||
							gameBoard[getLetterLocation(input[0])][conv] == P2Knights ||
								gameBoard[getLetterLocation(input[0])][conv] == P2Bishop ||
									gameBoard[getLetterLocation(input[0])][conv] == P2Pawns)
										{
										return true;
										}
		}

	//--- Checks and sees if player 2 is not hitting his own piece ---
	else if (player == 2)
		{
		//--- If the piece is blank it will be true //Checks this first ---
		if (gameBoard[getLetterLocation(input[0])][conv] == Blank)
			{
			return true;
			}

		//--- True if it is not its own piece ---
		else if (gameBoard[getLetterLocation(input[0])][conv] == P1King ||
					gameBoard[getLetterLocation(input[0])][conv] == P1Queen ||
						gameBoard[getLetterLocation(input[0])][conv] == P1Rook ||
							gameBoard[getLetterLocation(input[0])][conv] == P1Knights ||
								gameBoard[getLetterLocation(input[0])][conv] == P1Bishop ||
									gameBoard[getLetterLocation(input[0])][conv] == P1Pawns)
										{
										return true;
										}

		//--- False if it is ---
		else if (gameBoard[getLetterLocation(input[0])][conv] == P2King ||
					gameBoard[getLetterLocation(input[0])][conv] == P2Queen ||
						gameBoard[getLetterLocation(input[0])][conv] == P2Rook ||
							gameBoard[getLetterLocation(input[0])][conv] == P2Knights ||
								gameBoard[getLetterLocation(input[0])][conv] == P2Bishop ||
									gameBoard[getLetterLocation(input[0])][conv] == P2Pawns)
										{
										return false;
										}
		}

	return false;
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


//--- Gets the piece, starting location, ending location
vector<string> Chess::getInfo(string input, string input2, int player)
	{
	vector<string> info; //- A vector that will store the information -
	
	int conv = input[1] - '0'; //- Converts char to int - 
	
	//--- Pushes Game Piece name ---
	info.push_back(gameBoard[getLetterLocation(input[0])][conv]); 

	//--- Pushes startX coordinate ---
	info.push_back(std::to_string(getLetterLocation(input[0]))); 

	//--- Converts char to string
	stringstream i1,i2; 
	string e1,e2;
	char c = input[1], d = input2[1];
	i1 << c;
	i1 >> e1;
	i2 << d;
	i2 >> e2;

	//--- Pushes startY coordinate ---
	info.push_back(e1);
	//--- Pushes endX coordinate ---
	info.push_back(std::to_string(getLetterLocation(input2[0])));
	//--- Pushes endY coordinate --- 
	info.push_back(e2);
	info.push_back(std::to_string(player));
	return info;
	}


void Chess::makeMove(int player)
	{
	string input;
	
			if(player == 1)
				cout << name1 + " it is your turn! " << endl;
			else
				cout << name2 + " it is your turn! " << endl;

			cout << "Please choose a starting point [The Input Should Look Like: A4]. If you win ";
			
			if (player == 1)
				cout << name1;
			else
				cout << name2;
			cout << " then type in [WIN]" << endl;
			cin >> input;

			if(input == "WIN" || input == "win")
				gameover(name1);

		if (youCanS(input))
				{
				string input2;
				cout << "Please choose an ending point [The Input Should Look Like: A4]" << endl; 

				cin >> input2;

				if (youCanE(input2, player))
					{
					vector<string> listOfInformation = getInfo(input, input2, player);
					
					if (checksValidity(listOfInformation[0], atoi(listOfInformation[1].c_str()),
						atoi(listOfInformation[2].c_str()), atoi(listOfInformation[3].c_str()), atoi(listOfInformation[4].c_str()), atoi(listOfInformation[5].c_str())))
							{
							cout << "~~~ COMPLETE ~~~" << endl;
							gameBoard[atoi(listOfInformation[3].c_str())][atoi(listOfInformation[4].c_str())] = listOfInformation[0];
							gameBoard[atoi(listOfInformation[1].c_str())][atoi(listOfInformation[2].c_str())] = Blank;
							}
					else
						{
						
						cerr << "Not a valid Move" << endl;
						makeMove(player);
						}
					}
				else
					{
					cerr << "You're Ending point in not valid" << endl;
					makeMove(player);
					}
					
				}
	}


//--- After finding the piece it checks to make sure the piece is making a valid move ---
bool Chess::checksValidity(string piece, int startX, int startY, int endX, int endY, int player)
	{
	if (piece == P1Pawns || piece == P2Pawns)
		return pawnValid(startX, startY, endX, endY, player);
	else if (piece == P1Rook || piece == P2Rook)
		return rookValid(startX, startY, endX, endY, player);
	else if (piece == P1Knights || piece == P2Knights)
		return knightValid(startX, startY, endX, endY, player);
	else if (piece == P1King || piece == P2King)
		return kingValid(startX, startY, endX, endY, player);
	else if (piece == P1Queen || piece == P2Queen)
		return queenValid(startX, startY, endX, endY, player);
	else if (piece == P1Bishop || piece == P2Bishop)
		return bishopValid(startX, startY, endX, endY, player);
	else
		return false;
	}

//----------------------------------

//--- Pawns ---
bool Chess::pawnValid(int startX, int startY, int endX, int endY, int player)
	{
	//--- Checks to see if the piece is in its first turn where it can jump two places ---
	if ((startY == 6 && endY == 4 && player == 2 && endX == startX && gameBoard[endX][endY] == Blank) ||
			(startY == 1 && endY == 3 && player == 1 && endX == startX && gameBoard[endX][endY] == Blank))
				{
				return true;
				}

	//--- Checks to see if the piece is trying to 'take out' the other players piece and it can only attack diagonally ---
	else if ((player == 1 && gameBoard[endX][endY] != Blank && endX == startX - 1 && startX != 0 && endY == startY + 1) 
				|| (player == 1 && gameBoard[endX][endY] != Blank && endX == startX + 1 && startX != 7 && endY == startY + 1)
					|| (player == 2 && gameBoard[endX][endY] != Blank && endX == startX - 1 && startX != 0 && endY == startY - 1) 
						|| (player == 2 && gameBoard[endX][endY] != Blank && endX == startX + 1 && startX != 7 && endY == startY - 1))
							{
							return true;
							}

	//--- Checks to see if the piece just wants to move forward one ---
	else if ((player == 1 && endY == startY + 1 && endX == startX && gameBoard[endX][endY] == Blank) ||
				(player == 2 && endY == startY - 1 && endX == startX && gameBoard[endX][endY] == Blank))
					{
					return true;
					}

	//--- If none of these conditions are met the piece cannot move ---
	else
		{
		return false;
		}
	}

//-------------------------------------------


//--- Rooks --- 
bool Chess::rookValid(int startX, int startY, int endX, int endY, int player)
	{
	int checkUD = startY; //Check UP or DOWN
	int checkLR = startX; //Check LEFT or RIGHT

	
	//--- Checks Up ---
	if (endY < startY)
		{
		for (int ii = startY; ii > endY; ii--)
			{
			//--- Once a Piece is hit then it will remember where ---
			if (gameBoard[startX][ii - 1] != Blank)
				{
				break;
				}
			checkUD--;
			}

		//--- Makes sure that the Rook will not go over a piece, but can attack the enemy if it goes on top of it --- [Same for all]
		if (endX == startX && (endY >= checkUD || (endY >= checkUD - 1 && gameBoard[endX][endY] != Blank)))
			return true;
		else
			return false;

		}
	//--- Checks Down ---
	else if (endY > startY)
		{
		for (int ii = startY; ii < endY; ii++)
			{
			if (gameBoard[startX][ii + 1] != Blank)
				{
				break;
				}
			checkUD++;
			}

		if (endX == startX && (endY <= checkUD || (endY <= checkUD + 1 && gameBoard[endX][endY] != Blank)))
			return true;
		else
			return false;
		}

	//--- Checks right --- 
	else if (endX > startX)
		{
		for (int ii = startX; ii < endX; ii++)
			{
			if (gameBoard[ii + 1][startY] != Blank)
				{
				break;
				}
			checkLR++;
			}
		if (endY == startY && (endX <= checkLR || (endX <= checkLR + 1 && gameBoard[endX][endY] != Blank)))
			return true;
	
		else
			return false;
		}
	
	//--- Checks left --- 
	else if (endX < startX)
		{
		for (int ii = startX; ii > endX; ii--)
			{
			if (gameBoard[ii - 1][startY] != Blank)
				{
				break;
				}
			checkLR--;
			}
		if (endY == startY && (endX >= checkLR || (endX >= checkLR - 1 && gameBoard[endX][endY] != Blank && startX == endX)))
			return true;
		else
			return false;
		}
	return false; //If nothing is brought up assume it will be false 
	}

//----------------------------

//--- Knight ---
bool Chess :: knightValid(int startX, int startY, int endX, int endY, int player)
	{
	if ((endY == startY + 2 && endX == startX + 1) || 
			(endY == startY + 2 && endX == startX - 1) || 
				(endY == startY - 2 && endX == startX + 1) ||
					(endY == startY - 2 && endX == startX - 1) ||
						(endX == startX + 2 && endY == startY + 1) ||
							(endX == startX + 2 && endY == startY - 1) ||
								(endX == startX - 2 && endY == startY + 1) ||
									(endX == startX - 2 && endY == startY - 1))
										return true;
	else
		return false;
	}

//-----------------------------


//--- Bishop --- 
bool Chess :: bishopValid(int startX, int startY, int endX, int endY, int player)
	{
	int checkUD = startY; //Check UP or DOWN
	int checkLR = startX; //Check LEFT or RIGHT
	bool flag = false; //Makes sure the nested loop will be left 

	//--- If down-left ---
	if (endY > startY && endX < startX)
		{
		for (int xx = startX; xx > endX; xx--)
			{
			if (flag == true)
				break;

			for (int yy = startY; yy < endY; yy++)
				{
				//--- Once a Piece is hit then it will remember where ---
				if (gameBoard[xx - 1][yy + 1] != Blank)
					{
					flag = true;
					break;
					}
				checkUD++;
				checkLR--;
				}
			}
		//--- Makes sure that the Bishop will not go over a piece, but can attack the enemy if it goes on top of it --- [Same for all]
		if (endY <= checkUD && endX >= checkLR || (endY <= checkUD + 1 && endX >= checkLR - 1 && gameBoard[endX][endY] != Blank))
			return true;
		else
			return false;

		}

	//--- Checks down-right --- 
	else if (endY > startY && endX > startX)
		{
		for (int xx = startX; xx < endX; xx++)
			{
			if (flag == true)
				break;

			for (int yy = startY; yy < endY; yy++)
				{
				//--- Once a Piece is hit then it will remember where ---
				if (gameBoard[xx + 1][yy + 1] != Blank)
					{
					flag = true;
					break;
					}
				checkUD++;
				checkLR++;
				}
			}

		//--- Makes sure that the Bishop will not go over a piece, but can attack the enemy if it goes on top of it --- [Same for all]
		if (endY <= checkUD && endX <= checkLR || (endY <= checkUD + 1 && endX <= checkLR + 1 && gameBoard[endX][endY] != Blank))
			return true;
		else
			return false;

		}
	
	//--- If up-left ---
	else if (endY < startY && endX < startX)
		{
		for (int xx = startX; xx > endX; xx--)
			{
			if (flag == true)
				break;
			
			for (int yy = startY; yy > endY; yy--)
					{
					//--- Once a Piece is hit then it will remember where ---
					if (gameBoard[xx - 1][yy - 1] != Blank)
						{
						flag = true;
						break;
						}
				checkUD--;
				checkLR--;
				}
			}
		//--- Makes sure that the Bishop will not go over a piece, but can attack the enemy if it goes on top of it --- [Same for all]
		if (endY >= checkUD && endX >= checkLR || (endY >= checkUD - 1 && endX >= checkLR - 1 && gameBoard[endX][endY] != Blank))
			return true;
		else
			return false;
		}

	//--- Checks up-right --- 
	else if (endY < startY && endX > startX)
		{
		for (int xx = startX; xx < endX; xx++)
			{
			if (flag == true)
				break;
			for (int yy = startY; yy > endY; yy--)
				{
				//--- Once a Piece is hit then it will remember where ---
				if (gameBoard[xx + 1][yy - 1] != Blank)
					{
					flag = true;
					break;
					}
				checkUD--;
				checkLR++;
				}
			}
		//--- Makes sure that the Bishop will not go over a piece, but can attack the enemy if it goes on top of it --- [Same for all]
		if (endY >= checkUD && endX <= checkLR || (endY >= checkUD - 1 && endX <= checkLR + 1 && gameBoard[endX][endY] != Blank))
			return true;
		else
			return false;
		}

	return false; //If nothing is brought up assume it will be false 
	}

//--- King ---
bool Chess :: kingValid(int startX, int startY, int endX, int endY, int player)
	{
	if (((endX == startX + 1 || endX == startX - 1) && (endY == startY)) || 
			((endY == startY + 1 || endY == startY - 1) && (endX == startX)) || 
				(endX == startX + 1 && endY == startY + 1) ||
					(endX == startX + 1 && endY == startY - 1) || 
						(endX == startX - 1 && endY == startY + 1) || 
							(endX == startX - 1 && endY == startY - 1))
								return true;
	else
		return false;
	}

//------------------------------

//--- Queen ---
bool Chess::queenValid(int startX, int startY, int endX, int endY, int player)
	{
	if (pawnValid(startX, startY, endX, endY, player))
		return true;
	else if (rookValid(startX, startY, endX, endY, player))
		return true;
	else if (knightValid(startX, startY, endX, endY, player))
		return true;
	else if (kingValid(startX, startY, endX, endY, player))
		return true;
	else if (bishopValid(startX, startY, endX, endY, player))
		return true; 
		
	return false;
	}


//--- Game where you type in win if you win and it switches between people automatically ---
void Chess::game()
	{
	bool end = false;
	int player = 1;
	cout << "~ Welcome to Chess! ~" << endl;

	while (!end)
		{
		display();
		if (player == 1)
			{
			player = 2;
			makeMove(1);
			}
		else
			{
			player = 1;
			makeMove(2);
			}
		}
	}

void Chess::gameover(string winner)
	{
	cout << "CONGRATS " + winner + " YOU WIN!!!!" << endl;
	system("PAUSE");
	exit(0);
	}