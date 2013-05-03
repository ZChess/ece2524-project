#include <iostream>
#include <string>
#include <sstream>
#include "movement.hpp"
#include "global.hpp"
#include "ai.hpp"

using namespace std;

AI ai;
Movement mv;
void player1turn();
void player2turn();
int checkEnd();
int endGame(int players, int turn);
void printBoard();
int playerTurn = 0;
void resetBoard();

int main()
{
	int players;
	int finished = 0;
	int turn = 0;
	while(finished == 0)
	{
		switch(playerTurn)
		{
			case 0:
				cout << "How may players?" << endl;
				cin >> players;
				while(players != 1 && players != 2)
				{
					cout << "Invalid number of players" << endl;
					cin >> players;
				}
				playerTurn = 1;
			case 1:
				player1turn();
				if(checkEnd()==1)
				{
					playerTurn = 3;
					turn = 1;
				}
				else
					playerTurn = 2;
				break;

			case 2:
				if(players == 2)
					player2turn();
				else
				{
					ai.ai_move();
				}
				if(checkEnd()==1)
				{
					printBoard();
					playerTurn = 3;
					turn = 2;
				}
				else
					playerTurn = 1;
				break;
			case 3:
				finished = endGame(players, turn);
				break;
		}
	}
	return 0;
};

void player1turn()
{
	printBoard();
	string from;
	string to;
	cout << "Player 1's turn." << endl;
	cout << "Which piece do you want to move? ";
	cin >> from;
	cout << endl << "Where do you want to move it to? ";
	cin >> to;
	cout << endl;
	mv.setValid(true);
	mv.movePiece(from, to,playerTurn);

	//if the move was invalid ask to recieve new input
	while(mv.isValid() == false)
	{
		cout << "Which piece do you want to move? ";
		cin >> from;
		cout << endl << "Where do you want to move it to? ";
		cin >> to;
		cout << endl;
		mv.movePiece(from, to,playerTurn);
		
	}
	printBoard();
	//if the peiced jumped and there is another move ask if the player wants to jump again
	while(mv.hasJumped() == true)
	{
		cout << "Do you want to end your turn? y/n" << endl;
		cin >> to;
		if(to == "n")
		{
			cout << "Which piece do you want to move? ";
			cin >> from;
			cout << endl << "Where do you want to move it to? ";
			cin >> to;
			cout << endl;
			mv.movePiece(from, to,playerTurn);
			printBoard();
		}
		else if(to == "y")
		{
			mv.setJumped(false);
		}
		else
		{
			cout << "I don't under stand." << endl;
		}
	}
	return;
}

void player2turn()
{
	printBoard();
	string from;
	string to;
	cout << "Player 2's turn." << endl << "Which piece do you want to move?";
	cin >> from;
	cout << endl << "Where do you want to move it to?";
	cin >> to;
	cout << endl;
	mv.setValid(true);
	mv.movePiece(from, to,playerTurn);

	//if the move was invalid ask to recieve new input
	while(mv.isValid() == false)
	{
		cout << "Which piece do you want to move? ";
		cin >> from;
		cout << endl << "Where do you want to move it to? ";
		cin >> to;
		cout << endl;
		mv.movePiece(from, to,playerTurn);
		
	}
	printBoard();
	//if the peiced jumped and there is another move ask if the player wants to jump again
	while(mv.hasJumped() == true)
	{
		cout << "Do you want to end your turn? y/n" << endl;
		cin >> to;
		if(to == "n")
		{
			cout << "Which piece do you want to move? ";
			cin >> from;
			cout << endl << "Where do you want to move it to? ";
			cin >> to;
			cout << endl;
			mv.movePiece(from, to,playerTurn);
			printBoard();
		}
		else if(to == "y")
		{
			mv.setJumped(false);
		}
		else
		{
			cout << "I don't under stand." << endl;
		}
	}

	return;
}

void printBoard()
{
	for(int i = 0; i < 9; i++)
	{
		for( int j = 0; j<10; j++)
			cout << board[i][j] << " ";
	}
	cout << endl;
	return;
}

int checkEnd()
{
	int end = 0;
	int i = 1;
	int j;
	int x = 0;
	int o = 0;
	while(end == 0&&i<9)
	{
		j = 2;
		while(end==0&&j<10)
		{
			if(board[i][j] == "x" or board[i][j] == "X")
				x++;
			j++;
		}
		i++;
	}
	i = 1;
	while(end == 0&&i<9)
	{
		j = 2;
		while(end==0&&j<10)
		{
			if(board[i][j] == "x" or board[i][j] == "X")
				o++;
			j++;
		}
		i++;
	}
	if(x == 0 or o == 0)
		end = 1;
	return end;
}

int endGame(int players,int turn)
{
	int finished = 0;
	string playAgain = "a";
	if(turn==1)
		cout << "Player 1 wins!" << endl;
	else if(players==1)
		cout << "The computer wins!" << endl;
	else
		cout << "Player 2 wins!" << endl;
	cout << "Would you like to play again? y/n" << endl;
	cin >> playAgain;
	while(playAgain!="y" && playAgain!="n")
	{
		cout << "Would you like to play again? y/n" << endl;
		cin >> playAgain;
	}
	if(playAgain == "y")
	{
		playerTurn = 0;
		cout << "Good luck" << endl;
	}
	else
	{
		cout << "Thanks for playing" << endl;
		finished = 1;
	}
	return finished;
}
void resetBoard()
{
	int i = 1;
	for(i; i <9; i++)
	{
		int k = 2;
		for(k;k<10;k++)
		{
			if(i == 1 && (k%2) == 1)
				board[i][k] = "x";
			else if(i == 2 && (k%2) == 0)
				board[i][k] = "x";
			else if(i == 7 && (k%2) == 1)
				board[i][k] = "o";
			else if(i == 8 && (k%2) == 0)
				board[i][k] = "o";
			else if((i%2)== 0 && (k%2) ==0)
				board[i][k] = "_";
			else if((i%2) == 1 && (k%2) == 1)
				board[i][k] = "_";
		}
	} 
}













