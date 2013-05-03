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
void checkEnd();
int endGame(int players);
void printBoard();
int playerTurn = 0;

int main()
{
	int players;
	int finished = 0;
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
				break;
				if(checkEnd()==1)
					playerTurn = 3;
				else
					playerTurn = 2;

			case 2:
				if(players == 2)
					player2turn();
				else
				{
					cout << "test1" << endl;
					ai.ai_move();
				}
				break;
				if(checkEnd()==1)
					playerTurn = 3;
				else
					playerTurn = 1;
			case 3:
				finished = endGame(players);
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
	playerTurn = 2;
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

void checkEnd()
{
	int end = 0;
	int i = 1;
	int j;
	while(end == 0&&i<9)
	{
		j = 2;
		while(end==0&&j<10)
		{
			if(board[i][j] == "x" or board[i][j] == "X")
				end = 1;
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
				end = 1;
			j++;
		}
		i++;
	}
	return end;
}

int endGame(int players)
{
	int finished = 0;
	string playAgain = "a";
	if(playerTurn==1)
		cout << "Player 1 wins!" << endl;
	else if(players==1)
		cout << "The computer wins!" << endl;
	else
		cout << "Player 2 wins!" << endl;
	cout << "Would you like to play again? y/n" << endl;
	cin >> playAgain;
	while(playAgain!="y" or playAgain!="n")
	{
		cout << "Would you like to play again? y/n" << endl;
		cin >> playAgain;
	}
	if(playAgiain == "y")
	{
		playerTurn = 0;
		coutn << "Good luck" << endl;
	}
	else
	{
		cout << "Thanks for playing" << endl;
		finished = 1;
	}
	return finished;
}
