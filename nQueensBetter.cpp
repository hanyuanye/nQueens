#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

void printBoard(int n, int* board)
{
	cout << endl;
	cout << "New board: " << endl;
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
	fp.open("nqueensBetter.txt");
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

void setNewBoard(int n, int *board)
{
	for (int i = 0; i < n; i ++)
	{
		board[i] = rand() % n;
	}
}

int threatenQueens(int n, int *board, vector<int> & threatened)
{
	bool done;
	for (int i = 0; i < n-1; i ++)
	{
		done = false;
		for (int j = i+1; j < n && !done; j ++)
		{
			if (board[i] == board[j])
			{
				done = true;
			}
			if (abs(board[i] - board[j]) == abs(i - j))
			{
				done = true;
			}			
		}
		if (done)
		{
			threatened.push_back(i);
		}
	}
	return threatened.size();
}

int evaluateSpot(int n, int col, int row, int *board)
{
	int score = 0;
	for (int i = 0; i < n; i ++)
	{
		if (board[i] == col)
		{
			score ++;
			continue;
		}
		if (abs(board[i] - col) == abs(i - row))
		{
			score ++;
			continue;
		}
	}
	return score;
}
	
void minimize(int n, int row, int *board)
{
	int score = 0;
	int spot = 0;
	int minScore = evaluateSpot(n, 0, row, board);
	for (int i = 0; i < n; i ++)
	{
		score = evaluateSpot(n, i, row, board);
		if (score < minScore)
		{
			minScore = score;
			spot = i;
		}
	}
	board[row] = spot;
}

void SolvenQueens(int n)
{
	int *board = new int[n];
	int counter = 0;
	int prev;
	setNewBoard(n, board);
	vector <int> threatened;
	while (threatenQueens(n, board, threatened) > 0)
	{
		int rowToChange = threatened[rand()%threatened.size()];
		minimize(n, rowToChange, board);
		if (prev = threatened.size())
		{
			setNewBoard(n, board);
		}
		prev = threatened.size();
		threatened.clear();
		counter ++;
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