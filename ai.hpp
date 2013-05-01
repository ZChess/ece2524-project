#ifndef AI_hpp
#define AI_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
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
