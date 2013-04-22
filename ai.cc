#include "ai.hpp"
#include "global.hpp"

void ai::ai_move()
{
	int done = 0;
	done = check_king();
	if(done == 0)
		done = check_attack();
	if(done == 0)
		done = check_defend();
	if(done == 0)
		random_move();
	return;
}

int ai::check_king()
{
	int done = 0;
	int i = 2;
	while(i<9 && done==0)
	{
		if(board[2][i] == 'o')
		{
			if(board[1][i-1] == '_')
			{
				board[1][i-1] = 'O';
				board[2][i] = '_';
				done = 1;
			}
			else if(board[1][i+1] == '_')
			{
				board[1][i+1] = 'O';
				board[2][i] = '_';
				done = 1;
			}
		}
		i = i+2;
	}
	return done;
}

int ai::check_attack()
{
	int done = 0;
	int i = 1;
	int j;
	while(i<9 && done==0)
	{
		j = 2;
		while(j<10 && done == 0)
		{
			if(board[i][j] == 'O')
			{
				if(board[i-1][j-1] == 'x' or board[i-1][j-1] == 'X')
				{
					if(board[i-2][j-2] == '_')
					{
						board[i-2][j-2] = 'O';
						board[i][j] = '_';
						board[i-1][j-1] = '_';
						done = 1;
					}
				}
				else if(board[i-1][j+1] == 'x' or board[i-1][j+1] == 'X')
				{
					if(board[i-2][j+2] == '_')
					{
						board[i-2][j+2] = 'O';
						board[i][j] = '_';
						board[i-1][j+1] = '_';
						done = 1;
					}
				}
				else if(board[i+1][j+1] == 'x' or board[i+1][j+1] == 'X')
				{
					if(board[i+2][j+2] == '_')
					{
						board[i+2][j+2] = 'O';
						board[i][j] = '_';
						board[i+1][j+1] = '_';
						done = 1;
					}
				}
				else if(board[i+1][j-1] == 'x' or board[i+1][j+1] == 'X')
				{
					if(board[i+2][j-2] == '_')
					{
						board[i+2][j-2] = 'O';
						board[i][j] = '_';
						board[i+1][j-1] = '_';
						done = 1;
					}
				}
			}
			else if(board[i][j] == 'o')
			{
				if(board[i-1][j-1] == 'x' or board[i-1][j-1] == 'X')
				{
					if(board[i-2][j-2] == '_')
					{
						if((i-2)==1)
							board[i-2][j-2] = 'O';
						else
							board[i-2][j-2] = 'o';
						board[i][j] = '_';
						board[i-1][j-1] = '_';
						done = 1;
					}
				}
				else if(board[i-1][j+1] == 'x' or board[i-1][j+1] == 'X')
				{
					if(board[i-2][j+2] == '_')
					{
						if((i-2)==1)
							board[i-2][j+2] = 'O';
						else
							board[i-2][j+2] = 'o';
						board[i][j] = '_';
						board[i-1][j+1] = '_';
						done = 1;
					}
				}
			}
			j++;
		}
		i++;
	}
	return done;
}

int ai::check_defend()
{
	int done = 0;
	int i = 1;
	int j;
	while(i<9 && done==0)
	{
		j = 2;
		while(j<10 && done == 0)
		{
			if(board[i][j] == 'O')
			{
				if(board[i-1][j-1] == 'x' or board[i-1][j-1] == 'X')
				{
					if(board[i+1][j+1] == '_')
					{
						board[i+1][j+1] = 'O';
						board[i][j] = '_';
						done = 1;
					}
				}
				else if(board[i-1][j+1] == 'x' or board[i-1][j+1] == 'X')
				{
					if(board[i+1][j-1] == '_')
					{
						board[i+1][j-1] = 'O';
						board[i][j] = '_';
						done = 1;
					}
				}
				else if(board[i+1][j+1] == 'X')
				{
					if(board[i-1][j-1] == '_')
					{
						board[i-1][j-1] = 'O';
						board[i][j] = '_';
						done = 1;
					}
				}
				else if(board[i+1][j-1] == 'X')
				{
					if(board[i-1][j+1] == '_')
					{
						board[i-1][j+1] = 'O';
						board[i][j] = '_';
						done = 1;
					}
				}
			}
			else if(board[i][j] == 'o')
			{
				if(board[i-1][j-1] == 'x' or board[i-1][j-1] == 'X')
				{
					if(board[i+1][j+1] == '_')
					{
						if(board[i-1][j+1] == '_')
						{
							board[i-1][j+1] = 'o';
							board[i][j] = '_';
							done = 1;
						}
					}
				}
				else if(board[i-1][j+1] == 'x' or board[i-1][j+1] == 'X')
				{
					if(board[i+1][j+1] == '_')
					{
						if(board[i-1][j-1] == '_')
						{
							board[i-1][j+1] = 'o';
							board[i][j] = '_';
							done = 1;
						}
					}
				}
				else if(board[i+1][j-1] == 'X')
				{
					if(board[i-1][j+1] == '_')
					{
						board[i-1][j+1] = 'o';
						board[i][j] = '_';
						done = 1;
					}
				}
				else if(board[i+1][j+1] == 'X')
				{
					if(board[i-1][j+1] == '_')
					{
						board[i-1][j+1] = 'o';
						board[i][j] = '_';
						done = 1;
					}
				}
			}
			j++;
		}
		i++;
	}
	return done;
}

void ai::random_move()
{
	int done = 0;
	int i = 1;
	int j;
	while(i<9 && done==0)
	{
		j = 2;
		while(j<10 && done == 0)
		{
			if(board[i][j] == 'o')
			{
				if(board[i-1][j-1] == '_')
				{
					board[i-1][j-1] = 'o';
					board[i][j] = '_';
					done = 1;
				}
				else if(board[i-1][j+1] == '_')
				{
					board[i-1][j+1] = 'o';
					board[i][j] = '_';
					done = 1;
				}
			}
			j++;
		}
		i++;
	}
	return;
}
