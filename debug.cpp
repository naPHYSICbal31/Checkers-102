#include<igraphics.h>
#include<stdio.h>
int board[8][8];
int main()
{
	// black pieces
	for (int r = 0, c = 1; c < 8; c += 2)
	{
		board[r][c] = -1;
	}
	for (int r = 1, c = 0; c < 8; c += 2)
	{
		board[r][c] = -1;
	}
	for (int r = 2, c = 1; c < 8; c += 2)
	{
		board[r][c] = -1;
	}
	// red pieces
	for (int r = 7, c = 0; c < 8; c += 2)
	{
		board[r][c] = 1;
	}
	for (int r = 6, c = 1; c < 8; c += 2)
	{
		board[r][c] = 1;
	}
	for (int r = 5, c = 0; c < 8; c += 2)
	{
		board[r][c] = 1;
	}
}
