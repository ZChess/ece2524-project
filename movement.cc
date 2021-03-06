#include "movement.hpp"

/*
this is the constructer for the movement class. It sets the value of valid to true as defult
*/
Movement::Movement()
{
	/*board = {"\n"," ","1","2","3","4","5","6","7","8",
		 "\n","A","x"," ","x"," ","x"," ","x"," ",
		 "\n","B"," ","x"," ","x"," ","x"," ","x",
		 "\n","C","_"," ","_"," ","_"," ","_"," ",
		 "\n","D"," ","_"," ","_"," ","_"," ","_",
		 "\n","E","_"," ","_"," ","_"," ","_"," ",
		 "\n","F"," "," "," "," "," "," "," "," ",
		 "\n","G","o"," ","o"," ","o"," ","o"," ",
		 "\n","H"," ","o"," ","o"," ","o"," ","o"};*/
	valid = true;
	jumped = false;
}
/*
this function will check to see if the peice has reached the end of the board and became king. It will take place inside of movePiece and should not becalled outside of class. the parameters that it will take are the gameboard itself and what peice was moved
*/
void Movement::checkKing()
{
	//check to see if an o peice made it to the top
	for(int i = 2; i < 10; i++)
	{
		
		if(board[1][i] == "o")
			board[1][i] = "O";
		
	}
	//check to see if an x made it to the bottom
	for(int i = 2; i < 10; i++)
	{
		if(board[8][i] == "x")
			board[8][i] = "X";
	}
	return;
}
/*This function sets the value of valid. should only be called inside the movement class.
*/
void Movement::setValid(bool value)
{
	valid = value;
}
/*
/*This function sets the value of jumped. 
*/
void Movement::setJumped(bool value)
{
	jumped = value;
}
/*
This function returns the status of the jumped. if the move was valid it will return true, otherwise false
*/
bool Movement::hasJumped()
{
	return jumped;
}
/*
This function returns the status of the move. if the move was valid it will return true, otherwise false
*/
bool Movement::isValid()
{
	return valid;
}
void Movement::movePiece(string prevMove, string newMove,int player)
{
	
	int prevRow = prevMove[0] - 64;//take the move(A,B,C..etc) and put it into an int A = 1 B = 2, etc
	int prevCol = (prevMove[1]-'0') + 1;//to move the numbers in the row 1 = 2
	int newRow = newMove[0] - 64;
	int newCol = (newMove[1] - '0') + 1;
	//this is a check to see if the input is invalid(may have to change 
	if(prevRow > 9 || prevRow < 1)
	{
		cout << "Please select a peice that is on the board"<< endl;
		valid = false;
		return;
	}
	if(prevCol > 10 || prevCol < 2)
	{
		cout << "Please select a peice that is on the board"<< endl;
		valid = false;
		return;
	}
	if(newRow > 9 || newRow < 1)
	{
		cout << "Please enter a move that is on the board"<< endl;
		valid = false;
		return;
	}
	if(newCol > 10 || newCol < 2)
	{
		cout << "Please enter a move that is on the board"<< endl;
		valid = false;
		return;
	}
	if((board[prevRow][prevCol] == "x" || board[prevRow][prevCol] == "X") && player == 2)
	{
		cout << "Please select an o piece to move" << endl;
		valid = false;
		return;
	}
	else if((board[prevRow][prevCol] == "o" || board[prevRow][prevCol] == "O") && player == 1)
	{
		cout << "Please select an x piece to move" << endl;
		valid = false;
		return;
	}
	int movement = -1;//an int used to switch the enum cases
	enum move{x,X,o,O};//an enum to keep track of all the possible moves
	if(board[prevRow][prevCol] == "x")
		movement = 0;
	else if(board[prevRow][prevCol] == "X")
		movement = 1;
	else if(board[prevRow][prevCol] == "o")
		movement = 2;
	else if(board[prevRow][prevCol] == "O")
		movement = 3;
	//check to see if the player tried to move a peice on an existing peice
	if(board[newRow][newCol] == "x" || board[newRow][newCol] == "X" || board[newRow][newCol] == "o"|| board[newRow][newCol]== "O" 		|| board[newRow][newCol] == " " || board[prevRow][prevCol] == " " || board[prevRow][prevCol] == "_")
	{
		cout << "Please enter a valid Move" << endl;
		valid = false;
		return;
	}
	int xdistance = newCol - prevCol;//have an int to see how far in the x direction
	int ydistance = newRow - prevRow;//have an int to see how far in the y direction
	//see if the move is vaid(1 diagonaly or two diagonally)
	if(abs(xdistance) != abs(ydistance))
	{
		cout << "This move is not valid" << endl;
		valid = false;
		return;
	}
	switch(movement)
	{
		cout << "hlks" << endl;
		//work out moves with x
		case x:
			//if the player tries to move up with this peice
			if(ydistance <=0 || xdistance == 0)
			{
				cout << "you can't move up with this piece please try again" << endl; 
				valid = false;
				return;
			}
			else if(jumped == false && (xdistance == 1 || xdistance == -1))//a standard move to an empty space
			{
				board[newRow][newCol] = "x";
				board[prevRow][prevCol] = "_";
			}
			else if(xdistance == 2 || xdistance == -2)//a move that takes out another peice
			{
				//if the move was to the down - right
				if(xdistance > 0 && (board[prevRow + 1][prevCol +1] == "o" || board[prevRow + 1][prevCol +1] == "O"))
				{
					board[newRow][newCol] = "x";
					board[prevRow][prevCol] = "_";
					board[prevRow +1][prevCol + 1] = "_";
					
				}
				//else if the move was to the down - left
				else if(board[prevRow + 1][prevCol -1] == "o" || board[prevRow + 1][prevCol -1] == "O")
				{
					board[newRow][newCol] = "x";
					board[prevRow][prevCol] = "_";
					board[prevRow +1][prevCol - 1] = "_";
				}
				//if the jump was invalid
				else
				{
					cout << "please enter a valid move" << endl;
					valid = false;
					return;
				}
			}
			else
			{
				cout << "please enter a valid move" << endl;
				valid = false;
				return;
			}
			//else if(xdistance == 2 && spot one away from peice == "o" or "O"
			break;
		//work out moves with X
		case X:
			if(jumped == false && (xdistance == 1 || xdistance == -1))
			{
				board[newRow][newCol] = "X";
				board[prevRow][prevCol] = "_";
			}
			else if(xdistance == 2 || xdistance == -2)
			{
				//move to the up - right
				if(xdistance > 0 && ydistance < 0 && 
				(board[prevRow -1][prevCol + 1] == "o" || board[prevRow -1][prevCol +1] == "O"))
				{
					board[newRow][newCol] = "X";
					board[prevRow - 1][prevCol +1] = "_";
					board[prevRow][prevCol] = "_";
				}
				//move to the up - left
				else if(xdistance < 0 && ydistance < 0 && 
				(board[prevRow -1][prevCol - 1] == "o" || board[prevRow -1][prevCol -1] == "O"))
				{
					board[newRow][newCol] = "X";
					board[prevRow - 1][prevCol -1] = "_";
					board[prevRow][prevCol] = "_";
				}
				//move to the down - right
				else if(xdistance > 0 && ydistance > 0 && 
				(board[prevRow +1][prevCol + 1] == "o" || board[prevRow +1][prevCol +1] == "O"))
				{
					board[newRow][newCol] = "X";
					board[prevRow + 1][prevCol +1] = "_";
					board[prevRow][prevCol] = "_";
				}
				//move to the down - left
				else if(xdistance < 0 && ydistance > 0 && 
				(board[prevRow +1][prevCol - 1] == "o" || board[prevRow +1][prevCol -1] == "O"))
				{
					board[newRow][newCol] = "X";
					board[prevRow + 1][prevCol -1] = "_";
					board[prevRow][prevCol] = "_";
				}
				//if the jump was invalid
				else
				{
					cout << "please enter a valid move" << endl;
					valid = false;
					return;
				}
			}
			//if the move
			else
			{
				cout << "please enter a valid move" << endl;
				valid = false;
				return;
			}
			break;
		//work out moves with o
		case o:
			//if the player tries to move down with this peice
			if(ydistance >=0 || xdistance == 0)
			{
				cout << "you can't move down with that peice, please pick again" << endl;
				valid = false;
				return;
			}
			else if(jumped == false && (xdistance == 1 || xdistance == -1))//a standard move to an empty space
			{
				board[newRow][newCol] = "o";
				board[prevRow][prevCol] = "_";
			}
			else if(xdistance == 2 || xdistance == -2)//a move that takes out another peice
			{
				//if the move was to the up - right
				if(xdistance > 0 && (board[prevRow - 1][prevCol +1] == "x" || board[prevRow - 1][prevCol +1] == "X"))
				{
					board[newRow][newCol] = "o";
					board[prevRow][prevCol] = "_";
					board[prevRow -1][prevCol + 1] = "_";
				}
				//else if the move was to the up - left
				else if(board[prevRow - 1][prevCol -1] == "x" || board[prevRow - 1][prevCol -1] == "X")
				{
					board[newRow][newCol] = "o";
					board[prevRow][prevCol] = "_";
					board[prevRow -1][prevCol - 1] = "_";
				}
				//if the jump was invalid
				else
				{
					cout << "please enter a valid move" << endl;
					valid = false;
					return;
				}
			}
			else
			{
				cout << "please enter a valid move" << endl;
				valid = false;
				return;
			}
			break;
		//work out moves with O
		case O:
			if(jumped == false && (xdistance == 1 || xdistance == -1))
			{
				board[newRow][newCol] = "O";
				board[prevRow][prevCol] = "_";
			}
			else if(xdistance == 2 || xdistance == -2)
			{
				//move to the up - right
				if(xdistance > 0 && ydistance < 0 && 
				(board[prevRow -1][prevCol + 1] == "x" || board[prevRow -1][prevCol +1] == "X"))
				{
					board[newRow][newCol] = "O";
					board[prevRow - 1][prevCol +1] = "_";
					board[prevRow][prevCol] = "_";
				}
				//move to the up - left
				else if(xdistance < 0 && ydistance < 0 && 
				(board[prevRow -1][prevCol - 1] == "x" || board[prevRow -1][prevCol -1] == "x"))
				{
					board[newRow][newCol] = "O";
					board[prevRow - 1][prevCol -1] = "_";
					board[prevRow][prevCol] = "_";
				}
				//move to the down - right
				else if(xdistance > 0 && ydistance > 0 && 
				(board[prevRow +1][prevCol + 1] == "x" || board[prevRow +1][prevCol +1] == "X"))
				{
					board[newRow][newCol] = "O";
					board[prevRow + 1][prevCol +1] = "_";
					board[prevRow][prevCol] = "_";
				}
				//move to the down - left
				else if(xdistance < 0 && ydistance > 0 && 
				(board[prevRow +1][prevCol - 1] == "x" || board[prevRow +1][prevCol -1] == "X"))
				{
					board[newRow][newCol] = "O";
					board[prevRow + 1][prevCol -1] = "_";
					board[prevRow][prevCol] = "_";
				}
				//if the jump was invalid
				else
				{
					cout << "please enter a valid move" << endl;
					valid = false;
					return;
				}
			}
			//if the move
			else
			{
				cout << "please enter a valid move" << endl;
				valid = false;
				return;
			}
			break;
		//the move was a space and an invalid move;
		default:
			
			valid = false;
			return;
			break;
	}
	//check to see if the peice moved was is kinged
	jumped = true;
	checkKing();
	valid = true;
	return;
}
			
