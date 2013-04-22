#include <iostream>
#include <string>
#include <sstream>

#include "global.hpp"
#include "ai.hpp"
#include "movement.hpp"

using namespace std;

void player1turn();
void player2turn();
//void aiMove();
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
				//else
					//aiMove();
				break;
			/*case 3:
				//endGame();
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

	//movePiece(from, to);
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

	//movePiece(from, to);
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
