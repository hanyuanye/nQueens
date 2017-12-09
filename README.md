# nQueens

nQueens randomly creates a state with 1 Queen per row and then improves the state by using an implementation of the Hill climbing row. 
It assigns each state a total score and then places the queen until the evaluation is minimized. nQueens can run a board size of 100x100 
in about 10 seconds making it extremely slow for large board sizes.

nQueensBetter aims to increase the maximum size which it can process in a given amount of time by using a minimum conflicts algorithm
which repairs each state by assigning. It assigns each square in a row a score based on the number of queens threateneing it and 
moves the queen to the lowest score. 
