#include "iGraphics.h"
#include <bits/stdc++.h>
/* to do list:
   1.Game Implementation along with proper grids
	a.Show moveable pieces
	b.Show where to move(including multiple piece captures)
	c.Moving animation
	d.Show how many pieces won
   2.UI within game screen
	a. who won+time taken+moves taken(sort by both options)
   3.Opening Screen
   4.Sounds
*/
/*
	function iDraw() is called again and again by the system.

*/
void setup();

int px = 161, py = 148;
int incr = 69;
int board[8][8] = {0}; // stores info about where is which piece
int tap_board[8][8] = {0};
int tapped = 0, c_tapped = 0,c2_tapped = 0;
int tap_c = 0, tap_r = 0;
int l_valid = 0, r_valid = 0, lc_valid = 0, rc_valid = 0,llc_valid = 0,lrc_valid = 0,rlc_valid = 0,rrc_valid = 0;
int turn = 1;
void setup() // declaring initial setup of the checker_board
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
void iDraw()
{
	// place your drawing codes here
	iClear();
	iShowBMP(0, 0, "checker_board.bmp");
	for (int i = 0; i < 8; i += 1)
	{
		for (int j = 0; j < 8; j += 1)
		{
			if (board[i][j] == 1)
			{
				iShowBMP2(px + incr * j, py + incr * (7 - i), "checker_red.bmp", 0);
			}
			else if (board[i][j] == -1)
			{
				iShowBMP2(px + incr * j, py + incr * (7 - i), "checker_black.bmp", 0);
			}
		}
	}
	iSetColor(255, 0, 0);
	if (tapped == 1)
	{
		if (l_valid == 1)
		{
			iFilledCircle((tap_c - 1) * incr + px + 34, (7 - (tap_r - 1)) * incr + py + 34, 10, 1000);
		}
		if (r_valid == 1)
		{
			iFilledCircle((tap_c + 1) * incr + px + 34, (7 - (tap_r - 1)) * incr + py + 34, 10, 1000);
		}
	}
	if (tapped == 2)
	{
		if (l_valid == 1)
		{
			iFilledCircle((tap_c - 1) * incr + px + 34, (7 - (tap_r + 1)) * incr + py + 34, 10, 1000);
		}
		if (r_valid == 1)
		{
			iFilledCircle((tap_c + 1) * incr + px + 34, (7 - (tap_r + 1)) * incr + py + 34, 10, 1000);
		}
	}
	if (c_tapped == 1)
	{
		if (lc_valid == 1)
		{
			iFilledCircle((tap_c - 2) * incr + px + 34, (7 - (tap_r - 2)) * incr + py + 34, 10, 1000);
		}
		if (rc_valid == 1)
		{
			iFilledCircle((tap_c + 2) * incr + px + 34, (7 - (tap_r - 2)) * incr + py + 34, 10, 1000);
		}
	}
	if (c_tapped == 2)
	{
		if (lc_valid == 1)
		{
			iFilledCircle((tap_c - 2) * incr + px + 34, (7 - (tap_r + 2)) * incr + py + 34, 10, 1000);
		}
		if (rc_valid == 1)
		{
			iFilledCircle((tap_c + 2) * incr + px + 34, (7 - (tap_r + 2)) * incr + py + 34, 10, 1000);
		}
	}
	if(c2_tapped == 1)
	{
		if (llc_valid == 1)
		{
			iFilledCircle((tap_c - 4) * incr + px + 34, (7 - (tap_r - 4)) * incr + py + 34, 10, 1000);
		}
		if (lrc_valid == 1)
		{
			iFilledCircle((tap_c) * incr + px + 34, (7 - (tap_r - 4)) * incr + py + 34, 10, 1000);
		}
		if (rlc_valid == 1)
		{
			iFilledCircle((tap_c) * incr + px + 34, (7 - (tap_r - 4)) * incr + py + 34, 10, 1000);
		}
		if (rrc_valid == 1)
		{
			iFilledCircle((tap_c + 4) * incr + px + 34, (7 - (tap_r - 4)) * incr + py + 34, 10, 1000);
		}
	}
	if(c2_tapped == 2)
	{
		if (llc_valid == 1)
		{
			iFilledCircle((tap_c - 4) * incr + px + 34, (7 - (tap_r + 4)) * incr + py + 34, 10, 1000);
		}
		if (lrc_valid == 1)
		{
			iFilledCircle((tap_c) * incr + px + 34, (7 - (tap_r + 4)) * incr + py + 34, 10, 1000);
		}
		if (rlc_valid == 1)
		{
			iFilledCircle((tap_c) * incr + px + 34, (7 - (tap_r + 4)) * incr + py + 34, 10, 1000);
		}
		if (rrc_valid == 1)
		{
			iFilledCircle((tap_c + 4) * incr + px + 34, (7 - (tap_r + 4)) * incr + py + 34, 10, 1000);
		}
	}
	iSetColor(0,0,0);
	if(turn == 1)
	{
       iText(125,745,"Red to Move",GLUT_BITMAP_HELVETICA_18);
	}
	if(turn == 2)
	{
       iText(125,745,"Black to Move",GLUT_BITMAP_HELVETICA_18);
	}
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
	// place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
	//printf("x = %d y = %d",mx,my);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (tapped == 0 && c_tapped == 0) // FIRST TAP FOR A PIECE//
		{
			tap_c = (mx - px) / incr;
			tap_r = 7 - ((my - py) / incr);
			if (turn == 1)
			{
				if (tap_r - 1 >= 0 && tap_r - 1 < 8 && tap_c - 1 >= 0 && tap_c < 8 && board[tap_r][tap_c] == 1 && board[tap_r - 1][tap_c - 1] == 0)    // SIMPLE MOVE FOR REDS//
				{
					tapped = 1;
					l_valid = 1;
				}
				if (tap_r - 1 >= 0 && tap_r - 1 < 8 && tap_c >= 0 && tap_c + 1 < 8 && board[tap_r][tap_c] == 1 && board[tap_r - 1][tap_c + 1] == 0)
				{
					tapped = 1;
					r_valid = 1;
				}
				if (tap_r - 2 >= 0 && tap_r - 1 < 8 && tap_c - 2 >= 0 && tap_c < 8 && board[tap_r][tap_c] == 1 && board[tap_r - 1][tap_c - 1] == -1 && board[tap_r - 2][tap_c - 2] == 0) // RED CAPTURTES BLACK//
				{
					c_tapped = 1;
					lc_valid = 1;
					if(tap_r - 4 >= 0 && board[tap_r-3][tap_c-3] == -1 && board[tap_r-4][tap_c-4] == 0) //DOUBLE CAPTURES//
					{
                       c2_tapped = 1;
					   llc_valid = 1;
					}
					if(tap_r - 4 >= 0 && board[tap_r-3][tap_c-1] == -1 && board[tap_r-4][tap_c] == 0)
					{
						c2_tapped = 1;
						lrc_valid = 1;
					}
				}
				if (tap_r - 2 >= 0 && tap_r - 1 < 8 && tap_c >= 0 && tap_c + 2 < 8 && board[tap_r][tap_c] == 1 && board[tap_r - 1][tap_c + 1] == -1 && board[tap_r - 2][tap_c + 2] == 0)
				{
					c_tapped = 1;
					rc_valid = 1;
					if(tap_r - 4 >= 0 && board[tap_r-3][tap_c+1] == -1 && board[tap_r-4][tap_c] == 0)
					{
                       c2_tapped = 1;
					   rlc_valid = 1;
					}
					if(tap_r - 4 >= 0 && board[tap_r-3][tap_c+3] == -1 && board[tap_r-4][tap_c+4] == 0)
					{
                       c2_tapped = 1;
					   rrc_valid = 1;
					}
				}
			}
			if (turn == 2)
			{
				if (tap_r >= 0 && tap_r + 1 < 8 && tap_c - 1 >= 0 && tap_c < 8 && board[tap_r][tap_c] == -1 && board[tap_r + 1][tap_c - 1] == 0) // SIMPLE MOVE FOR BLACKS//
				{
					tapped = 2;
					l_valid = 1;
				}
				if (tap_r >= 0 && tap_r + 1 < 8 && tap_c >= 0 && tap_c + 1 < 8 && board[tap_r][tap_c] == -1 && board[tap_r + 1][tap_c + 1] == 0)
				{
					tapped = 2;
					r_valid = 1;
				}
				if (tap_r >= 0 && tap_r + 2 < 8 && tap_c - 2 >= 0 && tap_c < 8 && board[tap_r][tap_c] == -1 && board[tap_r + 1][tap_c - 1] == 1 && board[tap_r + 2][tap_c - 2] == 0)
				{
					c_tapped = 2;
					lc_valid = 1;
					if(tap_r + 4 < 8 && board[tap_r+3][tap_c-3] == 1 && board[tap_r+4][tap_c-4] == 0)
					{
                       c2_tapped = 2;
					   llc_valid = 1;
					}
					if(tap_r + 4 < 8 && board[tap_r+3][tap_c-1] == 1 && board[tap_r+4][tap_c] == 0)
					{
						c2_tapped = 2;
						lrc_valid = 1;
					}
				}
				if (tap_r >= 0 && tap_r + 2 < 8 && tap_c >= 0 && tap_c + 2 < 8 && board[tap_r][tap_c] == -1 && board[tap_r + 1][tap_c + 1] == 1 && board[tap_r + 2][tap_c + 2] == 0)
				{
					c_tapped = 2;
					rc_valid = 1;
					if(tap_r + 4 < 8 && board[tap_r+3][tap_c+1] == 1 && board[tap_r+4][tap_c] == 0)
					{
                       c2_tapped = 2;
					   rlc_valid = 1;
					}
					if(tap_r + 4 < 8 && board[tap_r+3][tap_c+3] == 1 && board[tap_r+4][tap_c+4] == 0)
					{
                       c2_tapped = 2;
					   rrc_valid = 1;
					}
				}
			}

			// printf("ypos = %d xpos = %d\n",tap_r,tap_c);
			/* for(int i = 0; i <8 ; i += 1) //shows current board situation(where is which piece) // notice how the loop is reversed
			{
			for(int j = 0; j < 8; j += 1)
			{
				printf("%d ",board[i][j]);
			}
			printf("\n");
			}
			printf("done\n"); */
		}
		else // SECOND TAP FOR THE PIECE//
		{
			int tap_c2 = (mx - px) / incr;
			int tap_r2 = 7 - ((my - py) / incr); // COULD THINK ABOUT USING L_VALID AND R_VALID INSTEAD OF THE CONDITIONS//
			if (tap_r - 1 >= 0 && tap_r - 1 < 8 && tap_c - 1 >= 0 && tap_c < 8 && board[tap_r][tap_c] == 1 && board[tap_r - 1][tap_c - 1] == 0 && tap_c2 == tap_c - 1 && tap_r2 == tap_r - 1)
			{
				board[tap_r - 1][tap_c - 1] = 1;
				board[tap_r][tap_c] = 0;
				turn = 2;
			}
			if (tap_r - 1 >= 0 && tap_r - 1 < 8 && tap_c >= 0 && tap_c + 1 < 8 && board[tap_r][tap_c] == 1 && board[tap_r - 1][tap_c + 1] == 0 && tap_c2 == tap_c + 1 && tap_r2 == tap_r - 1)
			{
				board[tap_r - 1][tap_c + 1] = 1;
				board[tap_r][tap_c] = 0;
				turn = 2;
			}
			if (tap_r - 2 >= 0 && tap_r - 1 < 8 && tap_c - 2 >= 0 && tap_c < 8 && board[tap_r][tap_c] == 1 && board[tap_r - 1][tap_c - 1] == -1 && board[tap_r - 2][tap_c - 2] == 0 && tap_c2 == tap_c - 2 && tap_r2 == tap_r - 2)
			{
				board[tap_r - 2][tap_c - 2] = 1;
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c - 1] = 0;
				turn = 2;
			}
			if (tap_r - 2 >= 0 && tap_r - 1 < 8 && tap_c >= 0 && tap_c + 2 < 8 && board[tap_r][tap_c] == 1 && board[tap_r - 1][tap_c + 1] == -1 && board[tap_r - 2][tap_c + 2] == 0 && tap_c2 == tap_c + 2 && tap_r2 == tap_r - 2)
			{
				board[tap_r - 2][tap_c + 2] = 1;
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c + 1] = 0;
				turn = 2;
			}
			if (tap_r >= 0 && tap_r + 1 < 8 && tap_c - 1 >= 0 && tap_c < 8 && board[tap_r][tap_c] == -1 && board[tap_r + 1][tap_c - 1] == 0 && tap_c2 == tap_c - 1 && tap_r2 == tap_r + 1)
			{
				board[tap_r + 1][tap_c - 1] = -1;
				board[tap_r][tap_c] = 0;
				turn = 1;
			}
			if (tap_r >= 0 && tap_r + 1 < 8 && tap_c >= 0 && tap_c + 1 < 8 && board[tap_r][tap_c] == -1 && board[tap_r + 1][tap_c + 1] == 0 && tap_c2 == tap_c + 1 && tap_r2 == tap_r + 1)
			{
				board[tap_r + 1][tap_c + 1] = -1;
				board[tap_r][tap_c] = 0;
				turn = 1;
			}
			// UPDATING CAPTURES//
			if (tap_r >= 0 && tap_r + 2 < 8 && tap_c - 2 >= 0 && tap_c < 8 && board[tap_r][tap_c] == -1 && board[tap_r + 1][tap_c - 1] == 1 && board[tap_r + 2][tap_c - 2] == 0 && tap_c2 == tap_c - 2 && tap_r2 == tap_r + 2)
			{
				board[tap_r + 2][tap_c - 2] = -1;
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c - 1] = 0;
				turn = 1;
			}
			if (tap_r >= 0 && tap_r + 2 < 8 && tap_c >= 0 && tap_c + 2 < 8 && board[tap_r][tap_c] == -1 && board[tap_r + 1][tap_c + 1] == 1 && board[tap_r + 2][tap_c + 2] == 0 && tap_c2 == tap_c + 2 && tap_r2 == tap_r + 2)
			{
				board[tap_r + 2][tap_c + 2] = -1;
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c + 1] = 0;
				turn = 1;
			}
			if(c2_tapped == 1 && llc_valid == 1 && tap_c2 == tap_c - 4 && tap_r2 == tap_r - 4)
			{
				board[tap_r - 4][tap_c - 4] = 1;
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c - 1] = 0;
				board[tap_r - 3][tap_c - 3] = 0;
				turn = 2;		
			}
			if(c2_tapped == 1 && lrc_valid == 1 && tap_c2 == tap_c && tap_r2 == tap_r - 4)
			{
				board[tap_r - 4][tap_c] = 1;
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c - 1] = 0;
				board[tap_r - 3][tap_c - 1] = 0;
				turn = 2;
			}
			if(c2_tapped == 1 && rlc_valid == 1 && tap_c2 == tap_c && tap_r2 == tap_r - 4)
			{
				board[tap_r - 4][tap_c] = 1;
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c + 1] = 0;
				board[tap_r - 3][tap_c + 1] = 0;
				turn = 2;
			}
			if(c2_tapped == 1 && rrc_valid == 1 && tap_c2 == tap_c+4 && tap_r2 == tap_r - 4)
			{
				board[tap_r - 4][tap_c+4] = 1;
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c + 1] = 0;
				board[tap_r - 3][tap_c + 3] = 0;
				turn = 2;
			}
			if(c2_tapped == 2 && llc_valid == 1 && tap_c2 == tap_c - 4 && tap_r2 == tap_r + 4)
			{
				board[tap_r + 4][tap_c - 4] = -1;
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c - 1] = 0;
				board[tap_r + 3][tap_c - 3] = 0;
				turn = 1;		
			}
			if(c2_tapped == 2 && lrc_valid == 1 && tap_c2 == tap_c && tap_r2 == tap_r + 4)
			{
				board[tap_r + 4][tap_c] = -1;
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c - 1] = 0;
				board[tap_r + 3][tap_c - 1] = 0;
				turn = 1;
			}
			if(c2_tapped == 2 && rlc_valid == 1 && tap_c2 == tap_c && tap_r2 == tap_r + 4)
			{
				board[tap_r + 4][tap_c] = -1;
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c + 1] = 0;
				board[tap_r + 3][tap_c + 1] = 0;
				turn = 1;
			}
			if(c2_tapped == 2 && rrc_valid == 1 && tap_c2 == tap_c + 4 && tap_r2 == tap_r + 4)
			{
				board[tap_r + 4][tap_c+4] = -1;
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c + 1] = 0;
				board[tap_r + 3][tap_c + 3] = 0;
				turn = 1;
			}
			tapped = 0, c_tapped = 0,c2_tapped = 0, l_valid = 0, r_valid = 0, lc_valid = 0, rc_valid = 0,llc_valid = 0,lrc_valid = 0,rlc_valid = 0,rrc_valid = 0;
		}
		//printf("%d %d\n", tap_r, tap_c);
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}
	// place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	// place your codes for other keys here
}

int main()
{
	// place your own initialization codes here.
	setup();
	iInitialize(1200, 800, "Checkers");
	// codes written here after initialization doesnt get executed until the end of the program
	return 0;
}