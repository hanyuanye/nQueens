#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

void printBoard(int n, int* board)
{
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < n; j ++)
		{
			if (j == board[i])
			{
				cout << 1 << "  ";
			}
			else
			{
				cout << 0 << "  ";
			}
		}
		cout << endl;
	}
}
void printFile(int n, int* board)
{
	ofstream fp;
	fp.open("nqueens.txt");
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < n; j ++)
		{
			if (j == board[i])
			{
				fp << 1 << "  ";
			}
			else
			{
				fp << 0 << "  ";
			}
		}
		fp << endl;
	}
	fp.close();
}
int evaluate(int n, int *board)
{
	int score = 0;
	for (int i = 0; i < n-1; i ++)
	{
		for (int j = i+1; j < n; j ++)
		{
			if (board[i] == board[j])
			{
				score ++;
				continue;
			}
			if (abs(board[i] - board[j]) == abs(i - j))
			{
				score ++;
				continue;
			}
			
		}
	}
	return score;
}
void setNewBoard(int n, int *board)
{
	for (int i = 0; i < n; i ++)
	{
		board[i] = rand() % n;
	}
}

bool improveEval(int n, int *board)
{
	int initEval = evaluate(n, board);
	int currEval = initEval;
	int testEval;
	int curr;
	int *testBoard = new int[n];
	for (int i = 0; i < n; i ++)
	{
		testBoard[i] = board[i];
	}
	for (int i = 0; i < n; i ++)
	{
		curr = board[i];
		for (int j = 0; j < n; j ++)
		{
			testBoard[i] = j;
			testEval = evaluate(n, testBoard);
			if (testEval < currEval)
			{
				curr = j;
				currEval = testEval;
			}
		}
		testBoard[i] = curr;
	}
	if (currEval == initEval)
	{
		return false;
	}
	for (int i = 0; i < n; i ++)
	{
		board[i] = testBoard[i];
	}
	return true;
}
	
void SolvenQueens(int n)
{
	int *board = new int[n];
	setNewBoard(n, board);
//	printBoard(n, board);
	while (evaluate(n, board) > 0)
	{
		if (!improveEval(n, board))
		{
			setNewBoard(n, board);
		}
	}
	printBoard(n, board);
	printFile(n, board);
}
	

int main()
{
	cout << "Enter the size of the board" << endl;
	int n;
	cin >> n;
	SolvenQueens(n);
}
