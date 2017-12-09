#include "Board.h"

struct AiMove {
	AiMove() {};
	AiMove(int Score) : score(Score) {}
	int x;
	int y;
	int score;
};

class Game
{
public:
	void gameInit(int firstPlayer);
	void getAiMove(Board& board, int player);
	AiMove getBestMove(Board& board, int player, int depth);
	void move(Board& board, int player);
	void recieveMove(Board& board, int player);
	void switchPlayer(int& currplayer);
	void gamePlay(int firstPlayer);
	void displayWinner(int victor, Board board);
private:
	int humanPlayer;
	int AiPlayer;
};