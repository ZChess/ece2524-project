#ifndef AI_H
#define AI_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "global.hpp"

using namespace std;

class AI
{
private:
	int check_king();
	int check_attack();
	int check_defend();
	void random_move();
public:
	AI();
	void ai_move();
};

#endif
