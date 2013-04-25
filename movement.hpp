#ifndef Movement_hpp
#define Movement_hpp

//#include <boost/program_options.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "global.hpp"

using std::endl;
using std::cout;
using std::string;

class Movement
{
private:
	//char board[10][9];
	void checkKing();
	bool valid;//a bool variable to see if the move was valid or not
public:
	Movement();
	void movePiece(string prevMove, string newMove,int player);
	bool isValid();
	void setValid(bool value);
	//char getSpot(int row, int col);
};

#endif


