#ifndef AI_H
#define AI_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class AI
{

private:
	int check_king();
	int check_attack();
	int check_defend();
	void random_move();
public:
	void ai_move();
};
#endif
