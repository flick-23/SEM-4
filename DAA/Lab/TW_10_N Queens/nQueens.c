#include<stdio.h>
#include<stdlib.h>
#define N 5

int isItSafe(int board[][N], int i, int j) {

	// upper column
	for (int r = 0; r < i; ++r) 
		if(board[r][j]) return 0;

	int r = i, c = j;
	// upper left diagonal
	while(r>=0 && c>=0) {

		if(board[r][c]) return 0;
		r--; c--;
	}

	r = i, c = j; 
	// upper right diagonal
	while(r>=0 && c<N) {

		if(board[r][c]) return 0;
		r--; c++;
	}

	return 1;
} 

void display(int board[][N]) {

	for(int i = 0; i < N; i++) {

		for (int j = 0; j < N; ++j) {

			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

int nQueens(int board[][N], int r) {

	if(r == N) return 1;

	for(int c = 0; c < N; c++) {

		if(isItSafe(board, r, c)) {
			board[r][c] = 1;

			if(nQueens(board, r+1)) return 1;

			board[r][c] = 0;
		}
	}
	return 0;
}

int main() {

	int board[N][N] = {0};

	if(nQueens(board, 0)) display(board);

	return 0;
}