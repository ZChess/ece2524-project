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
//void endGame();
void printBoard();

int playerTurn = 1;

int main()
{
	int players;

	cout << "How may players?" << endl;
	cin >> players;
	while(players != 1 && players != 2)
	{
		cout << "Invalid number of players" << endl;
		cin >> players;
	}
	//players = players--;
	while(1)
	{
		switch(playerTurn)
		{
			case 1:
				player1turn();
				break;
			case 2:
				if(players == 2)
					player2turn();

				else
				{
					cout << "test1" << endl;
					ai.ai_move();
					playerTurn = 1;
				}
				break;
			/*case 3:
				//endGame();

				else
					ai.ai_move();
				break;*/
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
	playerTurn = 1;
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
