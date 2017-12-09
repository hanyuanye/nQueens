class Board 
{
public:
	char valAt(int x, int y);
	int intAt(int x, int y);
	int getSize();
	void SetVal(int player, int x, int y);
	void PrintBoard();
	int CheckVictory();
	void clear();
	//Constructor
	Board();
private:
	int board[3][3];
	int size;
	int Tie_val = 0;
	int No_val = 0;
	int X_val = 1;
	int O_val = 2;
	int Incomplete_val = 3;
};