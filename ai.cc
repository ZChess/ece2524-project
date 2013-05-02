#include "ai.hpp"
#include "global.hpp"

AI::AI()
{}

void AI::ai_move()
{
	cout << "test2" << endl;
	int done = 0;
	done = check_king();
	cout << "test3" << endl;
	if(done == 0)
	{
		done = check_attack();
		cout << "test4" << endl;
	}
	if(done == 0)
	{
		done = check_defend();
		cout << "test5" << endl;
	}
	if(done == 0)
	{
		random_move();
		cout << "test6" << endl;
	}
	return;
}

int AI::check_king()
{
	int done = 0;
	int i = 2;
	while(i<10 && done==0)
	{
		if(board[2][i] == "o")
		{
			if(board[1][i-1] == "_")
			{
				board[1][i-1] = "O";
				board[2][i] = "_";
				done = 1;
			}
			else if(board[1][i+1] == "_")
			{
				board[1][i+1] = "O";
				board[2][i] = "_";
				done = 1;
			}
		}
		i = i+2;
	}
	return done;
}

int AI::check_attack()
{
	int done = 0;
	int i = 1;
	int j;
	while(i<9 && done==0)
	{
		j = 2;
		while(j<10 && done == 0)
		{
			if(board[i][j] == "O")
			{
				if(board[i-1][j-1] == "x" or board[i-1][j-1] == "X")
				{
					if(board[i-2][j-2] == "_")
					{
						board[i-2][j-2] = "O";
						board[i][j] = "_";
						board[i-1][j-1] = "_";
						done = 1;
					}
				}
				if((j)!=8&&done==0)
				{
					if(board[i-1][j+1] == "x" or board[i-1][j+1] == "X")
					{
						if(board[i-2][j+2] == "_"&&(j+2)!=9)
						{
							board[i-2][j+2] = "O";
							board[i][j] = "_";
							board[i-1][j+1] = "_";
							done = 1;
						}
					}
				}
				if(i!=7&&j!=8&&done==0)
				{
					if(board[i+1][j+1] == "x" or board[i+1][j+1] == "X")
					{
						if(board[i+2][j+2] == "_"&&(j+2)!=9&&(i+2)!=9)
						{
							board[i+2][j+2] = "O";
							board[i][j] = "_";
							board[i+1][j+1] = "_";
							done = 1;
						}
					}
				}	
				if(i!=7&&done==0)
				{
					if(board[i+1][j-1] == "x" or board[i+1][j-1] == "X")
					{
						if(board[i+2][j-2] == "_")
						{
							board[i+2][j-2] = "O";
							board[i][j] = "_";
							board[i+1][j-1] = "_";
							done = 1;
						}
					}
				}
			}
			else if(board[i][j] == "o")
			{
				if(board[i-1][j-1] == "x" or board[i-1][j-1] == "X")
				{
					if(board[i-2][j-2] == "_")
					{
						if((i-2)==1)
							board[i-2][j-2] = "O";
						else
							board[i-2][j-2] = "o";
						board[i][j] = "_";
						board[i-1][j-1] = "_";
						done = 1;
					}
				}
				if(j!=8&&done==0)
				{
					if(board[i-1][j+1] == "x" or board[i-1][j+1] == "X")
					{
						if(board[i-2][j+2] == "_")
						{
							if((i-2)==1)
								board[i-2][j+2] = "O";
							else
								board[i-2][j+2] = "o";
							board[i][j] = "_";
							board[i-1][j+1] = "_";
							done = 1;
						}
					}
				}
			}
			j++;
		}
		i++;
	}
	return done;
}
int AI::check_defend()
{
	int done = 0;
	int i = 1;
	int j = 2;
	while(i<8 && done==0)
	{
		j = 2;
		while(j<9 && done == 0)
		{
			if(board[i][j] == "O")
			{
				if(board[i-1][j-1] == "x" || board[i-1][j-1] == "X")
				{
					if(board[i+1][j+1] == "_")
					{
						board[i+1][j+1] = "O";
						board[i][j] = "_";
						done = 1;
						return done;
					}
				}
				else if(board[i-1][j+1] == "x" || board[i-1][j+1] == "X")
				{
					if(board[i+1][j-1] == "_")
					{
						board[i+1][j-1] = "O";
						board[i][j] = "_";
						done = 1;
						return done;
					}
				}
				else if(board[i+1][j+1] == "X")
				{
					if(board[i-1][j-1] == "_")
					{
						board[i-1][j-1] = "O";
						board[i][j] = "_";
						done = 1;
						return done;
					}
				}
				else if(board[i+1][j-1] == "X")
				{
					if(board[i-1][j+1] == "_" && j !=8)
					{
						board[i-1][j+1] = "O";
						board[i][j] = "_";
						done = 1;
						return done;
					}
				}
			}
			else if(board[i][j] == "o")
			{
				if(board[i-1][j-1] == "x" or board[i-1][j-1] == "X")
				{
					if(board[i+1][j+1] == "_")
					{
						if(board[i-1][j+1] == "_")
						{
							board[i-1][j+1] = "o";
							board[i][j] = "_";
							done = 1;
							return done;
						}
					}
				}
				else if(board[i-1][j+1] == "x" or board[i-1][j+1] == "X")
				{
					if(board[i+1][j-1] == "_")
					{
						if(board[i-1][j-1] == "_")
						{
							board[i-1][j-1] = "o";
							board[i][j] = "_";
							done = 1;
							return done;
						}
					}
				}
				else if(board[i+1][j+1] == "X" && i != 8 && j != 8)
				{
					if(board[i-1][j-1] == "_")
					{
						board[i-1][j-1] = "o";
						board[i][j] = "_";
						done = 1;
						return done;
					}
				}
				else if(board[i+1][j-1] == "X" && i != 8)
				{
					if(board[i-1][j+1] == "_" && j !=8)
					{
						board[i-1][j+1] = "o";
						board[i][j] = "_";
						done = 1;
						return done;
					}
				}
			}
			j++;
		}
		i++;
	}
	return done;
}

void AI::random_move()
{
	int done = 0;
	int i,j,k;
	while(done==0)
	{
		i=rand() % 8 + 1;
		j = rand() % 8 + 2;
		if(board[i][j] == "O")
		{
			k = rand() % 4;
			if(k == 0)
			{
				if(board[i-1][j-1] == "_")
				{
					board[i-1][j-1] = "O";
					board[i][j] = "_";
					done = 1;
				}
			}
			else if(k == 1)
			{
				if(j!=9)
				{
					if(board[i-1][j+1] == "_")
					{
						board[i-1][j+1] = "O";
						board[i][j] = "_";
						done = 1;
					}
				}
			}
			else if(k == 2)
			{
				if(j!=9&&i!=8)
				{
					if(board[i+1][j+1] == "_")
					{
						board[i+1][j+1] = "O";
						board[i][j] = "_";
						done = 1;
					}
				}
			}
			else
			{
				if(i!=8)
				{
					if(board[i+1][j-1] == "_")
					{
						board[i+1][j-1] = "O";
						board[i][j] = "_";
						done = 1;
					}
				}
			}
		}
		if(board[i][j] == "o")
		{
			k = rand() % 4;
			if(k == 0)
			{
				if(board[i-1][j-1] == "_")
				{
					board[i-1][j-1] = "o";
					board[i][j] = "_";
					done = 1;
				}
			}
			else
			{
				if(j!=9)
				{
					if(board[i-1][j+1] == "_")
					{
						board[i-1][j+1] = "o";
						board[i][j] = "_";
						done = 1;
					}
				}
			}
		}
	}
	return;
}
