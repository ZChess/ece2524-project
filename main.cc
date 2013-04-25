#include <iostream>
#include <string>
#include <sstream>
#include "movement.hpp"
#include "global.hpp"

using namespace std;

Movement mv;
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
	cout << "goodbye" << endl;
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
