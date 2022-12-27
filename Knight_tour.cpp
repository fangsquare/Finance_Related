#include <iostream>
#include <iomanip>
using namespace std;

// check  whether test is within the board
int inBoard(int x, int y, int **sol, int N)
{
	return(x>=0 && x<N && y>=0 && y<N &&sol[x][y]==-1);
}
void printKnight(int **sol, int N)
{
	for (int x=0; x<N; x++) {
		for (int y=0; y<N; y++)
			cout<<" "<<setw(2)<<sol[x][y]<<" ";
		cout << endl;
	}
}

int solveKTUbacktracking(int x, int y, int movei, int **sol,int xMove[8], int yMove[8], int N)
{
	int k, next_x, next_y;
	if (movei == N * N)
		return 1;

	//Try all next moves fromthe current coordinate x, y 
	for (k = 0; k < 8; k++) {
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (inBoard(next_x, next_y, sol,N)) {
			sol[next_x][next_y] = movei;
			if (solveKTUbacktracking(next_x, next_y, movei + 1, sol, xMove, yMove,N) == 1)
				return 1;
			else
				sol[next_x][next_y] = -1;
		}
	}
	return 0;
}
int solveKT(int **sol, int N)
{
	// Initialization of solution matrix 
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			sol[x][y] = -1;

	/* xMove[] and yMove[] define next move of Knight.
	xMove[] is for next value of x coordinate
	yMove[] is for next value of y coordinate */
	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	// Since the Knight is initially at the first block
	sol[0][0] = 0;

	//explore all blocks starting from (0,0)
	if (solveKTUbacktracking(0, 0, 1, sol, xMove, yMove, N) == 0) {
		cout << "Solution does not exist";
		return 0;
	}
	else
		printKnight(sol, N);

	return 1;
}
int main()
{   
    int N;
	cout << "Please enter matrix size" << endl;
    cin >> N;
    int **sol;
    sol = new int *[N];
    for (int i=0; i<N; i++){
           sol[i] = new int[N];
    }
	solveKT(sol,N);
	return 0;
}
