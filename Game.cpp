#include "Game.h"
#include <iostream>
#include <vector>

using namespace std;

void Game::gameInit(int firstPlayer)
{
	humanPlayer = firstPlayer;
	(humanPlayer == 1) ? AiPlayer = 2 : AiPlayer = 1;
}

void Game::getAiMove(Board& board, int player)
{
	AiMove bestMove = getBestMove(board, player, 0);
	board.SetVal(player, bestMove.x, bestMove.y);
}

AiMove Game::getBestMove(Board& board, int player, int depth)
{
	if (board.CheckVictory() == 0)
	{
		return AiMove(0);
	}
	if (board.CheckVictory() == AiPlayer)
	{
		return AiMove(10 - depth);
	}
	if (board.CheckVictory() == humanPlayer)
	{
		return AiMove(-10 + depth);
	}
	vector <AiMove> possibleMoves;
	for (int i = 0; i < 3; i ++)
	{
		for (int j = 0; j < 3; j ++)
		{
			if (board.valAt(i, j) == ' ')
			{
				depth ++;
				AiMove move;
				move.x = i;
				move.y = j;
				board.SetVal(player, i, j);
				if (player == AiPlayer)
				{
					move.score = getBestMove(board, humanPlayer, depth).score;
				}
				if (player == humanPlayer)
				{
					move.score = getBestMove(board, AiPlayer, depth).score;
				}
				depth = 0;
				possibleMoves.push_back(move);
				board.SetVal(0, i, j);
			}
		}
	}
	int bestMove = 0;
	int counter = 0;
	if (player == AiPlayer)
	{
		int maxScore = -10000;
		for (int i =0; i < possibleMoves.size(); i ++)
		{
			if (possibleMoves[i].score > maxScore)
			{
				maxScore = possibleMoves[i].score;
				bestMove = i;
			}
		}
	}
	else if (player == humanPlayer)
	{
		int minScore = 10000;
		for (int i = 0; i < possibleMoves.size(); i ++)
		{
			if (possibleMoves[i].score < minScore)
			{
				minScore = possibleMoves[i].score;
				bestMove = i;
			}
		}
	}
	return possibleMoves[bestMove];
}

void Game::recieveMove(Board& board, int player)
{
	int x, y;
	board.PrintBoard();
	cout << "Enter the row number: " << endl;
	cin >> x;
	cout << "Enter the column number: " << endl;
	cin >> y;
	board.SetVal(player, x-1, y-1);
}

void Game::switchPlayer(int& player)
{
	if (player == humanPlayer)
	{
		player = AiPlayer;
	}
	else if (player == AiPlayer)
	{
		player = humanPlayer;
	}
}

void Game::displayWinner(int victor, Board board)
{
	board.PrintBoard();
	if (victor == AiPlayer)
	{
		cout << "The AI has won." << endl;
	}
	else if (victor == humanPlayer)
	{
		cout << "The player has won." << endl;
	}
	else
	{
		cout << "The game is a tie. " << endl;
	}
}

void Game::gamePlay(int firstPlayer)
{
	int counter = 1;
	Board board;
	gameInit(firstPlayer);
	int currPlayer = 1;
	while(board.CheckVictory() == 3)  //Still Ongoing
	{
		if (currPlayer == AiPlayer)
		{
			getAiMove(board, AiPlayer);
		}
		else if (currPlayer == humanPlayer)
		{
			recieveMove(board, humanPlayer);
		}
		switchPlayer(currPlayer);
		counter ++;
	}
	displayWinner(board.CheckVictory(), board);
}


			
