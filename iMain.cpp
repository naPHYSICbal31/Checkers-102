#include "iGraphics.h"
#include <bits/stdc++.h>
#include<unistd.h>
#include <mmsystem.h>
#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
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
void show_moveable_positions(int tap_r, int tap_c);
void convert();
void reset_timer();
void update_timer_red();
void update_timer_black();
void draw_timer_red();
void draw_timer_black();
enum screen {TITLE,FORMAT,CLASSIC,END,LEADERBOARD};
screen now = FORMAT;
int px = 158, py = 148;
int incr = 69;
int board[8][8] = {0}; // stores info about where is which piece
int tap_board[8][8] = {0};
char anim1[38][100];
char anim2[26][100];
char anim3[34][100];
int tapped = 0, c_tapped = 0, c2_tapped = 0, c3_tapped = 0;
int tap_c = 0, tap_r = 0;
int lu_valid = 0,ld_valid = 0, ru_valid = 0,rd_valid = 0,lcu_valid = 0, rcu_valid = 0,lcd_valid = 0, rcd_valid = 0, llcu_valid = 0, lrcu_valid = 0,llcd_valid = 0, lrcd_valid = 0,rlcu_valid = 0, rrcu_valid = 0,rlcd_valid = 0, rrcd_valid = 0, lllcu_valid = 0, llrcu_valid = 0, lrlcu_valid = 0, lrrcu_valid = 0, rllcu_valid = 0, rlrcu_valid = 0, rrlcu_valid = 0, rrrcu_valid = 0, lllcd_valid = 0, llrcd_valid = 0, lrlcd_valid = 0, lrrcd_valid = 0, rllcd_valid = 0, rlrcd_valid = 0, rrlcd_valid = 0, rrrcd_valid = 0,tapped2 = 0,c_tapped2 = 0,c2_tapped2 = 0,c3_tapped2 = 0;
int turn = 1;
int prom_piece = 0;
int hour = 0,minute = 0, sec = 0,hour1 = 0,minute1 = 0,sec1 = 0;
int idx = 0;
int idx1 = 0;
int idx2 = 0;
int anim1_clicked = 0;
int anim2_clicked = 0;
int move_anim2 = 0;
int move_anim3 = 0;
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
void load_anim1()
{
    for (int i = 0; i < 38; i++)
    {
        sprintf(anim1[i], "scene%02d.bmp",i);
    }
}
void update_anim1()
{
	if(idx < 37)
	{
		idx++;
	}
}
void load_anim2()
{
    for (int i = 0; i < 26; i++)
    {
        sprintf(anim2[i], "anim2%02d.bmp",i);
    }
}
void update_anim2()
{
	if(idx1 < 25)
	{
		idx1++;
	}
}
void load_anim3()
{
    for (int i = 0; i < 34; i++)
    {
        sprintf(anim3[i], "anim3%02d.bmp",i);
    }
}
void update_anim3()
{
	if(idx2 < 33)
	{
		idx2++;
	}
}
void iDraw()
{
	// place your drawing codes here
	iClear();
	iPauseTimer(0);
	iPauseTimer(1);
	iPauseTimer(2);
	iPauseTimer(3);
	iPauseTimer(4);
	switch(now)
	{
	 case FORMAT:
	 if(move_anim2 == 0)
	 {
		iResumeTimer(2);
       iShowBMP(0,0,anim1[idx]);
	 }
	 if(anim1_clicked == 1 && move_anim3 == 0)
	 {
		iResumeTimer(3);
		move_anim2 = 1;
		iShowBMP(0,0,anim2[idx1]);
	 }
	 if(anim2_clicked == 1)
		{
			iResumeTimer(4);
            move_anim3 = 1;
			iShowBMP(0,0,anim3[idx2]);
			if(idx2 == 33)
			{
               now = CLASSIC;
			}
		}
	 break;
	 case CLASSIC:
	 if(turn ==1)
	{
		iResumeTimer(0);
		iPauseTimer(1);
	}
	else
	{
		iPauseTimer(0);
		iResumeTimer(1);
	}
	iShowBMP(0, 0, "checker_board2.bmp");
	iShowBMP(814,0,"sidebar.bmp");
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
			else if (board[i][j] == 2)
			{
				iShowBMP2(px + incr * j, py + incr * (7 - i), "checker_red_prom.bmp", 0);
			}
			else if (board[i][j] == -2)
			{
				iShowBMP2(px + incr * j, py + incr * (7 - i), "checker_black_prom.bmp", 0);
			}
		}
	}
	iSetColor(255, 0, 0);
	if (tapped == 1)
	{
		if (lu_valid == 1)
		{
			iFilledCircle((tap_c - 1) * incr + px + 34, (7 - (tap_r - 1)) * incr + py + 34, 10, 1000);
			
	    }
		if (ru_valid == 1)
		{
			iFilledCircle((tap_c + 1) * incr + px + 34, (7 - (tap_r - 1)) * incr + py + 34, 10, 1000);
		}
	}
	if (tapped2 == 1)
	{
		if (ld_valid == 1)
		{
			iFilledCircle((tap_c - 1) * incr + px + 34, (7 - (tap_r + 1)) * incr + py + 34, 10, 1000);
		}
		if (rd_valid == 1)
		{
			iFilledCircle((tap_c + 1) * incr + px + 34, (7 - (tap_r + 1)) * incr + py + 34, 10, 1000);
		}
	}
	if (c_tapped == 1)
	{
		if (lcu_valid == 1)
		{
			iFilledCircle((tap_c - 2) * incr + px + 34, (7 - (tap_r - 2)) * incr + py + 34, 10, 1000);
		}
		if (rcu_valid == 1)
		{
			iFilledCircle((tap_c + 2) * incr + px + 34, (7 - (tap_r - 2)) * incr + py + 34, 10, 1000);
		}
	}
	if (c_tapped2 == 1)
	{
		if (lcd_valid == 1)
		{
			iFilledCircle((tap_c - 2) * incr + px + 34, (7 - (tap_r + 2)) * incr + py + 34, 10, 1000);
		}
		if (rcd_valid == 1)
		{
			iFilledCircle((tap_c + 2) * incr + px + 34, (7 - (tap_r + 2)) * incr + py + 34, 10, 1000);
		}
	}
	if (c2_tapped == 1)
	{
		if (llcu_valid == 1)
		{
			iFilledCircle((tap_c - 4) * incr + px + 34, (7 - (tap_r - 4)) * incr + py + 34, 10, 1000);
		}
		if (lrcu_valid == 1)
		{
			iFilledCircle((tap_c)*incr + px + 34, (7 - (tap_r - 4)) * incr + py + 34, 10, 1000);
		}
		if (rlcu_valid == 1)
		{
			iFilledCircle((tap_c)*incr + px + 34, (7 - (tap_r - 4)) * incr + py + 34, 10, 1000);
		}
		if (rrcu_valid == 1)
		{
			iFilledCircle((tap_c + 4) * incr + px + 34, (7 - (tap_r - 4)) * incr + py + 34, 10, 1000);
		}
	}
	if (c2_tapped2 == 1)
	{
		if (llcd_valid == 1)
		{
			iFilledCircle((tap_c - 4) * incr + px + 34, (7 - (tap_r + 4)) * incr + py + 34, 10, 1000);
		}
		if (lrcd_valid == 1)
		{
			iFilledCircle((tap_c)*incr + px + 34, (7 - (tap_r + 4)) * incr + py + 34, 10, 1000);
		}
		if (rlcd_valid == 1)
		{
			iFilledCircle((tap_c)*incr + px + 34, (7 - (tap_r + 4)) * incr + py + 34, 10, 1000);
		}
		if (rrcd_valid == 1)
		{
			iFilledCircle((tap_c + 4) * incr + px + 34, (7 - (tap_r + 4)) * incr + py + 34, 10, 1000);
		}
	}
	if (c3_tapped == 1)
	{
		if (lllcu_valid == 1)
		{
			iFilledCircle((tap_c - 6) * incr + px + 34, (7 - (tap_r - 6)) * incr + py + 34, 10, 1000);
		}
		if (llrcu_valid == 1)
		{
			iFilledCircle((tap_c - 2) * incr + px + 34, (7 - (tap_r - 6)) * incr + py + 34, 10, 1000);
		}
		if (lrlcu_valid == 1)
		{
			iFilledCircle((tap_c - 2) * incr + px + 34, (7 - (tap_r - 6)) * incr + py + 34, 10, 1000);
		}
		if (lrrcu_valid == 1)
		{
			iFilledCircle((tap_c + 2) * incr + px + 34, (7 - (tap_r - 6)) * incr + py + 34, 10, 1000);
		}
		if (rllcu_valid == 1)
		{
			iFilledCircle((tap_c - 2) * incr + px + 34, (7 - (tap_r - 6)) * incr + py + 34, 10, 1000);
		}
		if (rlrcu_valid == 1)
		{
			iFilledCircle((tap_c + 2) * incr + px + 34, (7 - (tap_r - 6)) * incr + py + 34, 10, 1000);
		}
		if (rrlcu_valid == 1)
		{
			iFilledCircle((tap_c + 2) * incr + px + 34, (7 - (tap_r - 6)) * incr + py + 34, 10, 1000);
		}
		if (rrrcu_valid == 1)
		{
			iFilledCircle((tap_c + 6) * incr + px + 34, (7 - (tap_r - 6)) * incr + py + 34, 10, 1000);
		}
	}
	if (c3_tapped2 == 1)
	{
		if (lllcd_valid == 1)
		{
			iFilledCircle((tap_c - 6) * incr + px + 34, (7 - (tap_r + 6)) * incr + py + 34, 10, 1000);
		}
		if (llrcd_valid == 1)
		{
			iFilledCircle((tap_c - 2) * incr + px + 34, (7 - (tap_r + 6)) * incr + py + 34, 10, 1000);
		}
		if (lrlcd_valid == 1)
		{
			iFilledCircle((tap_c - 2) * incr + px + 34, (7 - (tap_r + 6)) * incr + py + 34, 10, 1000);
		}
		if (lrrcd_valid == 1)
		{
			iFilledCircle((tap_c + 2) * incr + px + 34, (7 - (tap_r + 6)) * incr + py + 34, 10, 1000);
		}
		if (rllcd_valid == 1)
		{
			iFilledCircle((tap_c - 2) * incr + px + 34, (7 - (tap_r + 6)) * incr + py + 34, 10, 1000);
		}
		if (rlrcd_valid == 1)
		{
			iFilledCircle((tap_c + 2) * incr + px + 34, (7 - (tap_r + 6)) * incr + py + 34, 10, 1000);
		}
		if (rrlcd_valid == 1)
		{
			iFilledCircle((tap_c + 2) * incr + px + 34, (7 - (tap_r + 6)) * incr + py + 34, 10, 1000);
		}
		if (rrrcd_valid == 1)
		{
			iFilledCircle((tap_c + 6) * incr + px + 34, (7 - (tap_r + 6)) * incr + py + 34, 10, 1000);
		}
	}
	iSetColor(0, 0, 0);
	if (turn == 1)
	{
		iText(125, 745, "Red to Move", GLUT_BITMAP_HELVETICA_18);
	}
	if (turn == 2)
	{
		iText(125, 745, "Black to Move", GLUT_BITMAP_HELVETICA_18);
	}
	iSetColor(255,177,64);
	draw_timer_red();
	draw_timer_black();
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
void iMousePassiveMove(int mx, int my)
{

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
		if(now == FORMAT)
		{
			if(move_anim2 == 0) anim1_clicked = 1;
			
			if(move_anim2 == 1) anim2_clicked = 1;
			
		}
		if (tapped == 0 && tapped2 == 0 && c_tapped == 0 &&  c_tapped2 == 0 && c2_tapped == 0 && c2_tapped2 == 0 && c3_tapped == 0 && c3_tapped2 == 0) // FIRST TAP FOR A PIECE//
		{
			tap_c = (mx - px) / incr;
			tap_r = 7 - ((my - py) / incr);
			show_moveable_positions(tap_r, tap_c);

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
			int tap_r2 = 7 - ((my - py) / incr);
			if (tapped == 1 && lu_valid == 1 && tap_c2 == tap_c - 1 && tap_r2 == tap_r - 1)
			{
				if(prom_piece == 1)
                {
					board[tap_r - 1][tap_c - 1] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r - 1][tap_c - 1] = -2;
				}
				else
				{
				    board[tap_r - 1][tap_c - 1] = 1;
				}
				board[tap_r][tap_c] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (tapped == 1 && ru_valid == 1 && tap_c2 == tap_c + 1 && tap_r2 == tap_r - 1)
			{
				if(prom_piece == 1)
                {
					board[tap_r - 1][tap_c + 1] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r - 1][tap_c + 1] = -2;
				}
				else
				{
				    board[tap_r - 1][tap_c + 1] = 1;
				}
				board[tap_r][tap_c] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c_tapped == 1 && lcu_valid == 1 && tap_c2 == tap_c - 2 && tap_r2 == tap_r - 2)
			{
				if(prom_piece == 1)
                {
					board[tap_r - 2][tap_c - 2] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r - 2][tap_c - 2] = -2;
				}
				else
				{
				    board[tap_r - 2][tap_c - 2] = 1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c - 1] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c_tapped == 1 && rcu_valid == 1 && tap_c2 == tap_c + 2 && tap_r2 == tap_r - 2)
			{
				if(prom_piece == 1)
                {
					board[tap_r - 2][tap_c + 2] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r - 2][tap_c + 2] = -2;
				}
				else
				{
				    board[tap_r - 2][tap_c + 2] = 1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c + 1] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (tapped2 == 1 && ld_valid == 1 && tap_c2 == tap_c - 1 && tap_r2 == tap_r + 1)
			{
				if(prom_piece == 1)
                {
					board[tap_r + 1][tap_c - 1] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r + 1][tap_c - 1] = -2;
				}
				else
				{
				    board[tap_r + 1][tap_c - 1] = -1;
				}
				board[tap_r][tap_c] = 0;
			    if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (tapped2 == 1 && rd_valid == 1 && tap_c2 == tap_c + 1 && tap_r2 == tap_r + 1)
			{
				if(prom_piece == 1)
                {
					board[tap_r + 1][tap_c + 1] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r + 1][tap_c + 1] = -2;
				}
				else
				{
				    board[tap_r + 1][tap_c + 1] = -1;
				}
				board[tap_r][tap_c] = 0;
			    if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c_tapped2 == 1 && lcd_valid == 1 && tap_c2 == tap_c - 2 && tap_r2 == tap_r + 2)
			{
				if(prom_piece == 1)
                {
					board[tap_r + 2][tap_c - 2] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r + 2][tap_c - 2] = -2;
				}
				else
				{
				    board[tap_r + 2][tap_c - 2] = -1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c - 1] = 0;
			    if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c_tapped2 == 1 && rcd_valid == 1 && tap_c2 == tap_c + 2 && tap_r2 == tap_r + 2)
			{
				if(prom_piece == 1)
                {
					board[tap_r + 2][tap_c + 2] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r + 2][tap_c + 2] = -2;
				}
				else
				{
				    board[tap_r + 2][tap_c + 2] = -1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c + 1] = 0;
			    if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c2_tapped == 1 && llcu_valid == 1 && tap_c2 == tap_c - 4 && tap_r2 == tap_r - 4)
			{
				if(prom_piece == 1)
                {
					board[tap_r - 4][tap_c - 4] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r - 4][tap_c - 4] = -2;
				}
				else
				{
				    board[tap_r - 4][tap_c - 4] = 1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c - 1] = 0;
				board[tap_r - 3][tap_c - 3] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c2_tapped == 1 && lrcu_valid == 1 && tap_c2 == tap_c && tap_r2 == tap_r - 4)
			{
				if(prom_piece == 1)
                {
					board[tap_r - 4][tap_c] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r - 4][tap_c] = -2;
				}
				else
				{
				    board[tap_r - 4][tap_c] = 1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c - 1] = 0;
				board[tap_r - 3][tap_c - 1] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c2_tapped == 1 && rlcu_valid == 1 && tap_c2 == tap_c && tap_r2 == tap_r - 4)
			{
				if(prom_piece == 1)
                {
					board[tap_r - 4][tap_c] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r - 4][tap_c] = -2;
				}
				else
				{
				    board[tap_r - 4][tap_c] = 1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c + 1] = 0;
				board[tap_r - 3][tap_c + 1] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c2_tapped == 1 && rrcu_valid == 1 && tap_c2 == tap_c + 4 && tap_r2 == tap_r - 4)
			{
				if(prom_piece == 1)
                {
					board[tap_r - 4][tap_c+4] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r - 4][tap_c+4] = -2;
				}
				else
				{
				    board[tap_r - 4][tap_c+4] = 1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c + 1] = 0;
				board[tap_r - 3][tap_c + 3] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c2_tapped2 == 1 && llcd_valid == 1 && tap_c2 == tap_c - 4 && tap_r2 == tap_r + 4)
			{
				if(prom_piece == 1)
                {
					board[tap_r + 4][tap_c - 4] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r + 4][tap_c - 4] = -2;
				}
				else
				{
				    board[tap_r + 4][tap_c - 4] = -1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c - 1] = 0;
				board[tap_r + 3][tap_c - 3] = 0;
			    if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c2_tapped2 == 1 && lrcd_valid == 1 && tap_c2 == tap_c && tap_r2 == tap_r + 4)
			{
				if(prom_piece == 1)
                {
					board[tap_r + 4][tap_c] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r + 4][tap_c] = -2;
				}
				else
				{
				    board[tap_r + 4][tap_c] = -1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c - 1] = 0;
				board[tap_r + 3][tap_c - 1] = 0;
			    if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c2_tapped2 == 1 && rlcd_valid == 1 && tap_c2 == tap_c && tap_r2 == tap_r + 4)
			{
				if(prom_piece == 1)
                {
					board[tap_r + 4][tap_c] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r + 4][tap_c] = -2;
				}
				else
				{
				    board[tap_r + 4][tap_c] = -1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c + 1] = 0;
				board[tap_r + 3][tap_c + 1] = 0;
			    if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c2_tapped2 == 1 && rrcd_valid == 1 && tap_c2 == tap_c + 4 && tap_r2 == tap_r + 4)
			{
				if(prom_piece == 1)
                {
					board[tap_r - 4][tap_c+4] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r - 4][tap_c+4] = -2;
				}
				else
				{
				    board[tap_r - 4][tap_c+4] = -1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c + 1] = 0;
				board[tap_r + 3][tap_c + 3] = 0;
			    if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c3_tapped == 1 && lllcu_valid == 1 && tap_c2 == tap_c - 6 && tap_r2 == tap_r - 6)
			{
				if(prom_piece == 1)
                {
					board[tap_r - 6][tap_c-6] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r - 6][tap_c - 6] = -2;
				}
				else
				{
				    board[tap_r - 6][tap_c - 6] = 1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c - 1] = 0;
				board[tap_r - 3][tap_c - 3] = 0;
				board[tap_r - 5][tap_c - 5] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c3_tapped == 1 && llrcu_valid == 1 && tap_c2 == tap_c - 2 && tap_r2 == tap_r - 6)
			{
				if(prom_piece == 1)
                {
					board[tap_r - 6][tap_c - 2] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r - 6][tap_c - 2] = -2;
				}
				else
				{
				    board[tap_r - 6][tap_c - 2] = 1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c - 1] = 0;
				board[tap_r - 3][tap_c - 3] = 0;
				board[tap_r - 5][tap_c - 3] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c3_tapped == 1 && lrlcu_valid == 1 && tap_c2 == tap_c - 2 && tap_r2 == tap_r - 6)
			{
				if(prom_piece == 1)
                {
					board[tap_r - 6][tap_c - 2] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r - 6][tap_c - 2] = -2;
				}
				else
				{
				    board[tap_r - 6][tap_c - 2] = 1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c - 1] = 0;
				board[tap_r - 3][tap_c - 1] = 0;
				board[tap_r - 5][tap_c - 1] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c3_tapped == 1 && lrrcu_valid == 1 && tap_c2 == tap_c + 2 && tap_r2 == tap_r - 6)
			{
				if(prom_piece == 1)
                {
					board[tap_r - 6][tap_c + 2] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r - 6][tap_c + 2] = -2;
				}
				else
				{
				    board[tap_r - 6][tap_c + 2] = 1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c - 1] = 0;
				board[tap_r - 3][tap_c - 1] = 0;
				board[tap_r - 5][tap_c + 1] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c3_tapped == 1 && rllcu_valid == 1 && tap_c2 == tap_c - 2 && tap_r2 == tap_r - 6)
			{
				if(prom_piece == 1)
                {
					board[tap_r - 6][tap_c - 2] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r - 6][tap_c - 2] = -2;
				}
				else
				{
				    board[tap_r - 6][tap_c - 2] = 1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c + 1] = 0;
				board[tap_r - 3][tap_c + 1] = 0;
				board[tap_r - 5][tap_c - 1] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c3_tapped == 1 && rlrcu_valid == 1 && tap_c2 == tap_c + 2 && tap_r2 == tap_r - 6)
			{
				if(prom_piece == 1)
                {
					board[tap_r - 6][tap_c + 2] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r - 6][tap_c + 2] = -2;
				}
				else
				{
				    board[tap_r - 6][tap_c + 2] = 1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c + 1] = 0;
				board[tap_r - 3][tap_c + 1] = 0;
				board[tap_r - 5][tap_c + 1] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c3_tapped == 1 && rrlcu_valid == 1 && tap_c2 == tap_c + 2 && tap_r2 == tap_r - 6)
			{
				if(prom_piece == 1)
                {
					board[tap_r - 6][tap_c + 2] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r - 6][tap_c + 2] = -2;
				}
				else
				{
				    board[tap_r - 6][tap_c + 2] = 1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c + 1] = 0;
				board[tap_r - 3][tap_c + 3] = 0;
				board[tap_r - 5][tap_c + 3] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c3_tapped == 1 && rrrcu_valid == 1 && tap_c2 == tap_c + 6 && tap_r2 == tap_r - 6)
			{
				if(prom_piece == 1)
                {
					board[tap_r - 6][tap_c + 6] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r - 6][tap_c + 6] = -2;
				}
				else
				{
				    board[tap_r - 6][tap_c + 6] = 1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r - 1][tap_c + 1] = 0;
				board[tap_r - 3][tap_c + 3] = 0;
				board[tap_r - 5][tap_c + 5] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			// BLACK 3RD CAPTURE//
			if (c3_tapped2 == 1 && lllcd_valid == 1 && tap_c2 == tap_c - 6 && tap_r2 == tap_r + 6)
			{
				if(prom_piece == 1)
                {
					board[tap_r + 6][tap_c - 6] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r + 6][tap_c - 6] = -2;
				}
				else
				{
				    board[tap_r + 6][tap_c - 6] = -1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c - 1] = 0;
				board[tap_r + 3][tap_c - 3] = 0;
				board[tap_r + 5][tap_c - 5] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c3_tapped2 == 1 && llrcd_valid == 1 && tap_c2 == tap_c - 2 && tap_r2 == tap_r + 6)
			{
				if(prom_piece == 1)
                {
					board[tap_r + 6][tap_c - 2] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r + 6][tap_c - 2] = -2;
				}
				else
				{
				    board[tap_r + 6][tap_c - 2] = -1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c - 1] = 0;
				board[tap_r + 3][tap_c - 3] = 0;
				board[tap_r + 5][tap_c - 3] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c3_tapped2 == 1 && lrlcd_valid == 1 && tap_c2 == tap_c - 2 && tap_r2 == tap_r + 6)
			{
				if(prom_piece == 1)
                {
					board[tap_r + 6][tap_c - 2] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r + 6][tap_c - 2] = -2;
				}
				else
				{
				    board[tap_r + 6][tap_c - 2] = -1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c - 1] = 0;
				board[tap_r + 3][tap_c - 1] = 0;
				board[tap_r + 5][tap_c - 1] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c3_tapped2 == 1 && lrrcd_valid == 1 && tap_c2 == tap_c + 2 && tap_r2 == tap_r + 6)
			{
				if(prom_piece == 1)
                {
					board[tap_r + 6][tap_c + 2] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r + 6][tap_c + 2] = -2;
				}
				else
				{
				    board[tap_r + 6][tap_c + 2] = -1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c - 1] = 0;
				board[tap_r + 3][tap_c - 1] = 0;
				board[tap_r + 5][tap_c + 1] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c3_tapped2 == 1 && rllcd_valid == 1 && tap_c2 == tap_c - 2 && tap_r2 == tap_r + 6)
			{
				if(prom_piece == 1)
                {
					board[tap_r + 6][tap_c - 2] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r + 6][tap_c - 2] = -2;
				}
				else
				{
				    board[tap_r + 6][tap_c - 2] = -1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c + 1] = 0;
				board[tap_r + 3][tap_c + 1] = 0;
				board[tap_r + 5][tap_c - 1] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c3_tapped2 == 1 && rlrcd_valid == 1 && tap_c2 == tap_c + 2 && tap_r2 == tap_r + 6)
			{
				if(prom_piece == 1)
                {
					board[tap_r + 6][tap_c + 2] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r + 6][tap_c + 2] = -2;
				}
				else
				{
				    board[tap_r + 6][tap_c + 2] = -1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c + 1] = 0;
				board[tap_r + 3][tap_c + 1] = 0;
				board[tap_r + 5][tap_c + 1] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c3_tapped2 == 1 && rrlcd_valid == 1 && tap_c2 == tap_c + 2 && tap_r2 == tap_r + 6)
			{
				if(prom_piece == 1)
                {
					board[tap_r + 6][tap_c + 2] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r + 6][tap_c + 2] = -2;
				}
				else
				{
				    board[tap_r + 6][tap_c + 2] = -1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c + 1] = 0;
				board[tap_r + 3][tap_c + 3] = 0;
				board[tap_r + 5][tap_c + 3] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			if (c3_tapped2 == 1 && rrrcd_valid == 1 && tap_c2 == tap_c + 6 && tap_r2 == tap_r + 6)
			{
				if(prom_piece == 1)
                {
					board[tap_r + 6][tap_c + 6] = 2;
				}
				else if(prom_piece == -1)
				{
					board[tap_r + 6][tap_c + 6] = -2;
				}
				else
				{
				    board[tap_r + 6][tap_c + 6] = -1;
				}
				board[tap_r][tap_c] = 0;
				board[tap_r + 1][tap_c + 1] = 0;
				board[tap_r + 3][tap_c + 3] = 0;
				board[tap_r + 5][tap_c + 5] = 0;
				if(turn == 1) turn = 2;
				else turn = 1;
			}
			for (int r = 0, c = 1; c < 8; c += 2)
	        {
		        if(board[r][c] == 1)
				{
					board[r][c] = 2;
				}
	        }
			for (int r = 7, c = 0; c < 8; c += 2)
	        {
		        if(board[r][c] == -1)
				{

					board[r][c] = -2;
				}
	        }
			tapped = 0, c_tapped = 0, c2_tapped = 0, c3_tapped = 0, lu_valid = 0,ld_valid = 0, ru_valid = 0,rd_valid = 0,lcu_valid = 0, rcu_valid = 0, llcu_valid = 0, lrcu_valid = 0, rlcu_valid = 0, rrcu_valid = 0, llrcu_valid = 0, lrlcu_valid = 0, lrrcu_valid = 0, rllcu_valid = 0, rlrcu_valid = 0, rrlcu_valid = 0, rrrcu_valid = 0,lcd_valid = 0, rcd_valid = 0, llcd_valid = 0, lrcd_valid = 0, rlcd_valid = 0, rrcd_valid = 0, llrcd_valid = 0, lrlcd_valid = 0, lrrcd_valid = 0, rllcd_valid = 0, rlrcd_valid = 0, rrlcd_valid = 0, rrrcd_valid = 0,tapped2 = 0,c_tapped2 = 0,c2_tapped2 = 0,c3_tapped2 = 0;
			prom_piece = 0;
		}
		// printf("%d %d\n", tap_r, tap_c);
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

void show_moveable_positions(int tap_r, int tap_c)
{
	if (turn == 1)
	{
		if (tap_r - 1 >= 0 && tap_r - 1 < 8 && tap_c - 1 >= 0 && tap_c < 8 && board[tap_r][tap_c] == 1 && board[tap_r - 1][tap_c - 1] == 0) // SIMPLE MOVE FOR REDS//
		{
			tapped = 1;
			lu_valid = 1;
		}
		if (tap_r - 1 >= 0 && tap_r - 1 < 8 && tap_c >= 0 && tap_c + 1 < 8 && board[tap_r][tap_c] == 1 && board[tap_r - 1][tap_c + 1] == 0)
		{
			tapped = 1;
			ru_valid = 1;
		}
		if (tap_r - 2 >= 0 && tap_r - 1 < 8 && tap_c - 2 >= 0 && tap_c < 8 && board[tap_r][tap_c] == 1 && (board[tap_r - 1][tap_c - 1] == -1 || board[tap_r - 1][tap_c - 1] == -2) && board[tap_r - 2][tap_c - 2] == 0) // RED CAPTURTES BLACK//
		{
			c_tapped = 1;
			lcu_valid = 1;
			if (tap_r - 4 >= 0 && tap_c - 4 >= 0 && (board[tap_r - 3][tap_c - 3] == -1 || board[tap_r - 3][tap_c - 3] == -2) && board[tap_r - 4][tap_c - 4] == 0) // DOUBLE CAPTURES//
			{
				c2_tapped = 1;
				llcu_valid = 1;
				if (tap_r - 6 >= 0 && tap_c - 6 >= 0 && (board[tap_r - 5][tap_c - 5] == -1 || board[tap_r - 5][tap_c - 5] == -2) && board[tap_r - 6][tap_c - 6] == 0) // TRIPLE CAPTURES//
				{
					c3_tapped = 1;
					lllcu_valid = 1;
				}
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c - 3] == -1 || board[tap_r - 5][tap_c - 3] == -2) && board[tap_r - 6][tap_c - 2] == 0)
				{
					c3_tapped = 1;
					llrcu_valid = 1;
				}
			}
			if (tap_r - 4 >= 0 && (board[tap_r - 3][tap_c - 1] == -1 || board[tap_r - 3][tap_c - 1] == -2) && board[tap_r - 4][tap_c] == 0)
			{
				c2_tapped = 1;
				lrcu_valid = 1;
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c - 1] == -1 || board[tap_r - 5][tap_c - 1] == -2) && board[tap_r - 6][tap_c - 2] == 0)
				{
					c3_tapped = 1;
					lrlcu_valid = 1;
				}
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c + 1] == -1 || board[tap_r - 5][tap_c + 1] == -2) && board[tap_r - 6][tap_c + 2] == 0)
				{
					c3_tapped = 1;
					lrrcu_valid = 1;
				}
			}
		}
		if (tap_r - 2 >= 0 && tap_r - 1 < 8 && tap_c >= 0 && tap_c + 2 < 8 && board[tap_r][tap_c] == 1 && (board[tap_r - 1][tap_c + 1] == -1 || board[tap_r - 1][tap_c + 1] == -2) && board[tap_r - 2][tap_c + 2] == 0)
		{
			c_tapped = 1;
			rcu_valid = 1;
			if (tap_r - 4 >= 0 && (board[tap_r - 3][tap_c + 1] == -1 || board[tap_r - 3][tap_c + 1] == -2) && board[tap_r - 4][tap_c] == 0)
			{
				c2_tapped = 1;
				rlcu_valid = 1;
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c - 1] == -1 || board[tap_r - 5][tap_c - 1] == -2) && board[tap_r - 6][tap_c - 2] == 0)
				{
					c3_tapped = 1;
					rllcu_valid = 1;
				}
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c + 1] == -1 || board[tap_r - 5][tap_c + 1] == -2) && board[tap_r - 6][tap_c + 2] == 0)
				{
					c3_tapped = 1;
					rlrcu_valid = 1;
				}
			}
			if (tap_r - 4 >= 0 && tap_c + 4 < 8 && (board[tap_r - 3][tap_c + 3] == -1 || board[tap_r - 3][tap_c + 3] == -2) && board[tap_r - 4][tap_c + 4] == 0)
			{
				c2_tapped = 1;
				rrcu_valid = 1;
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c + 3] == -1 || board[tap_r - 5][tap_c + 3] == -2) && board[tap_r - 6][tap_c + 2] == 0)
				{
					c3_tapped = 1;
					rrlcu_valid = 1;
				}
				if (tap_r - 6 >= 0 && tap_c + 6 < 8 && (board[tap_r - 5][tap_c + 5] == -1 || board[tap_r - 5][tap_c + 5] == -2) && board[tap_r - 6][tap_c + 6] == 0)
				{
					c3_tapped = 1;
					rrrcu_valid = 1;
				}
			}
		}
	}
	if (turn == 2)
	{
		if (tap_r >= 0 && tap_r + 1 < 8 && tap_c - 1 >= 0 && tap_c < 8 && board[tap_r][tap_c] == -1 && board[tap_r + 1][tap_c - 1] == 0) // SIMPLE MOVE FOR BLACKS//
		{
			tapped2 = 1;
			ld_valid = 1;
		}
		if (tap_r >= 0 && tap_r + 1 < 8 && tap_c >= 0 && tap_c + 1 < 8 && board[tap_r][tap_c] == -1 && board[tap_r + 1][tap_c + 1] == 0)
		{
			tapped2 = 1;
			rd_valid = 1;
		}
		if (tap_r >= 0 && tap_r + 2 < 8 && tap_c - 2 >= 0 && tap_c < 8 && board[tap_r][tap_c] == -1 && (board[tap_r + 1][tap_c - 1] == 1 || board[tap_r + 1][tap_c - 1] == 2) && board[tap_r + 2][tap_c - 2] == 0)
		{
			c_tapped2 = 1;
			lcd_valid = 1;
			if (tap_r + 4 < 8 && tap_c - 4 >= 0 && (board[tap_r + 3][tap_c - 3] == 1 || board[tap_r + 3][tap_c - 3] == 2) && board[tap_r + 4][tap_c - 4] == 0)
			{
				c2_tapped2 = 1;
				llcd_valid = 1;
				if (tap_r + 6 < 8 && tap_c - 6 >= 0 && (board[tap_r + 5][tap_c - 5] == 1 || board[tap_r + 5][tap_c - 5] == 2) && board[tap_r + 6][tap_c - 6] == 0) // TRIPLE CAPTURES//
				{
					c3_tapped2 = 1;
					lllcd_valid = 1;
				}
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c - 3] == 1 || board[tap_r + 5][tap_c - 3] == 2) && board[tap_r + 6][tap_c - 2] == 0)
				{
					c3_tapped2 = 1;
					llrcd_valid = 1;
				}
			}
			if (tap_r + 4 < 8 && (board[tap_r + 3][tap_c - 1] == 1 || board[tap_r + 3][tap_c - 1] == 2) && board[tap_r + 4][tap_c] == 0)
			{
				c2_tapped2 = 1;
				lrcd_valid = 1;
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c - 1] == 1 || board[tap_r + 5][tap_c - 1] == 2) && board[tap_r + 6][tap_c - 2] == 0)
				{
					c3_tapped2 = 1;
					lrlcd_valid = 1;
				}
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c + 1] == 1 || board[tap_r + 5][tap_c + 1] == 2) && board[tap_r + 6][tap_c + 2] == 0)
				{
					c3_tapped2 = 1;
					lrrcd_valid = 1;
				}
			}
		}
		if (tap_r >= 0 && tap_r + 2 < 8 && tap_c >= 0 && tap_c + 2 < 8 && board[tap_r][tap_c] == -1 && (board[tap_r + 1][tap_c + 1] == 1 || board[tap_r + 1][tap_c + 1] == 2) && board[tap_r + 2][tap_c + 2] == 0)
		{
			c_tapped2 = 1;
			rcd_valid = 1;
			if (tap_r + 4 < 8 && (board[tap_r + 3][tap_c + 1] == 1 || board[tap_r + 3][tap_c + 1] == 2) && board[tap_r + 4][tap_c] == 0)
			{
				c2_tapped2 = 1;
				rlcd_valid = 1;
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c - 1] == 1 || board[tap_r + 5][tap_c - 1] == 2) && board[tap_r + 6][tap_c - 2] == 0)
				{
					c3_tapped2 = 1;
					rllcd_valid = 1;
				}
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c + 1] == 1 || board[tap_r + 5][tap_c + 1] == 2) && board[tap_r + 6][tap_c + 2] == 0)
				{
					c3_tapped2 = 1;
					rlrcd_valid = 1;
				}
			}
			if (tap_r + 4 < 8 && tap_c + 4 < 8 && (board[tap_r + 3][tap_c + 3] == 1 || board[tap_r + 3][tap_c + 3] == 2) && board[tap_r + 4][tap_c + 4] == 0)
			{
				c2_tapped2 = 1;
				rrcd_valid = 1;
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c + 3] == 1 || board[tap_r + 5][tap_c + 3] == 2) && board[tap_r + 6][tap_c + 2] == 0)
				{
					c3_tapped2 = 1;
					rrlcd_valid = 1;
				}
				if (tap_r - 6 >= 0 && tap_c + 6 < 8 && (board[tap_r - 5][tap_c + 5] == 1 || board[tap_r - 5][tap_c + 5] == 2) && board[tap_r + 6][tap_c + 6] == 0)
				{
					c3_tapped2 = 1;
					rrrcd_valid = 1;
				}
			}
		}
	}
	if ((turn == 1 && ((board[tap_r][tap_c] == 2))|| ((turn == 2 && board[tap_r][tap_c] == -2)))) // RED_LIKE TURNS FOR PROMOTED PIECES
	{
		if (tap_r - 1 >= 0 && tap_r - 1 < 8 && tap_c - 1 >= 0 && tap_c < 8 && (board[tap_r][tap_c] == 2 || board[tap_r][tap_c] == -2) && board[tap_r - 1][tap_c - 1] == 0) // SIMPLE MOVE FOR RED DIRECTION//
		{
			tapped = 1;
			lu_valid = 1;
			if(turn == 1) prom_piece = 1;
			else prom_piece = -1;

		}
		if (tap_r - 1 >= 0 && tap_r - 1 < 8 && tap_c >= 0 && tap_c + 1 < 8 && (board[tap_r][tap_c] == 2 || board[tap_r][tap_c] == -2) && board[tap_r - 1][tap_c + 1] == 0)
		{
			tapped = 1;
			ru_valid = 1;
			if(turn == 1) prom_piece = 1;
			else prom_piece = -1;
		}
		if (tap_r - 2 >= 0 && tap_r - 1 < 8 && tap_c - 2 >= 0 && tap_c < 8 && board[tap_r][tap_c] == 2 && (board[tap_r - 1][tap_c - 1] == -1 || board[tap_r - 1][tap_c - 1] == -2) && board[tap_r - 2][tap_c - 2] == 0) // RED CAPTURTES BLACK//
		{
			c_tapped = 1;
			lcu_valid = 1;
			if(turn == 1) prom_piece = 1;
			else prom_piece = -1;
			if (tap_r - 4 >= 0 && tap_c - 4 >= 0 && (board[tap_r - 3][tap_c - 3] == -1 || board[tap_r - 3][tap_c - 3] == -2) && board[tap_r - 4][tap_c - 4] == 0) // DOUBLE CAPTURES//
			{
				c2_tapped = 1;
				llcu_valid = 1;
				if(turn == 1) prom_piece = 1;
			    else prom_piece = -1;
				if (tap_r - 6 >= 0 && tap_c - 6 >= 0 && (board[tap_r - 5][tap_c - 5] == -1 || board[tap_r - 5][tap_c - 5] == -2) && board[tap_r - 6][tap_c - 6] == 0) // TRIPLE CAPTURES//
				{
					c3_tapped = 1;
					lllcu_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c - 3] == -1 || board[tap_r - 5][tap_c - 3] == -2) && board[tap_r - 6][tap_c - 2] == 0)
				{
					c3_tapped = 1;
					llrcu_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
			}
			if (tap_r - 4 >= 0 && (board[tap_r - 3][tap_c - 1] == -1 || board[tap_r - 3][tap_c - 1] == -2) && board[tap_r - 4][tap_c] == 0)
			{
				c2_tapped = 1;
				lrcu_valid = 1;
				if(turn == 1) prom_piece = 1;
			    else prom_piece = -1;
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c - 1] == -1 || board[tap_r - 5][tap_c - 1] == -2) && board[tap_r - 6][tap_c - 2] == 0)
				{
					c3_tapped = 1;
					lrlcu_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c + 1] == -1 || board[tap_r - 5][tap_c + 1] == -2) && board[tap_r - 6][tap_c + 2] == 0)
				{
					c3_tapped = 1;
					lrrcu_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
			}
		}
		if (tap_r - 2 >= 0 && tap_r - 1 < 8 && tap_c - 2 >= 0 && tap_c < 8 && board[tap_r][tap_c] == -2 && (board[tap_r - 1][tap_c - 1] == 1 || board[tap_r - 1][tap_c - 1] == 2) && board[tap_r - 2][tap_c - 2] == 0) // RED CAPTURTES BLACK//
		{
			c_tapped = 1;
			lcu_valid = 1;
			if(turn == 1) prom_piece = 1;
			else prom_piece = -1;
			if (tap_r - 4 >= 0 && tap_c - 4 >= 0 && (board[tap_r - 3][tap_c - 3] == 1 || board[tap_r - 3][tap_c - 3] == 2) && board[tap_r - 4][tap_c - 4] == 0) // DOUBLE CAPTURES//
			{
				c2_tapped = 1;
				llcu_valid = 1;
				if(turn == 1) prom_piece = 1;
			    else prom_piece = -1;
				if (tap_r - 6 >= 0 && tap_c - 6 >= 0 && (board[tap_r - 5][tap_c - 5] == 1 || board[tap_r - 5][tap_c - 5] == 2) && board[tap_r - 6][tap_c - 6] == 0) // TRIPLE CAPTURES//
				{
					c3_tapped = 1;
					lllcu_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c - 3] == 1 || board[tap_r - 5][tap_c - 3] == 2) && board[tap_r - 6][tap_c - 2] == 0)
				{
					c3_tapped = 1;
					llrcu_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
			}
			if (tap_r - 4 >= 0 && (board[tap_r - 3][tap_c - 1] == 1 || board[tap_r - 3][tap_c - 1] == 2) && board[tap_r - 4][tap_c] == 0)
			{
				c2_tapped = 1;
				lrcu_valid = 1;
				if(turn == 1) prom_piece = 1;
			    else prom_piece = -1;
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c - 1] == 1 || board[tap_r - 5][tap_c - 1] == 2) && board[tap_r - 6][tap_c - 2] == 0)
				{
					c3_tapped = 1;
					lrlcu_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c + 1] == 1 || board[tap_r - 5][tap_c + 1] == 2) && board[tap_r - 6][tap_c + 2] == 0)
				{
					c3_tapped = 1;
					lrrcu_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
			}
		}
		if (tap_r - 2 >= 0 && tap_r - 1 < 8 && tap_c >= 0 && tap_c + 2 < 8 && board[tap_r][tap_c] == 2 && (board[tap_r - 1][tap_c + 1] == -1 || board[tap_r - 1][tap_c + 1] == -2) && board[tap_r - 2][tap_c + 2] == 0)
		{
			c_tapped = 1;
			rcu_valid = 1;
			if(turn == 1) prom_piece = 1;
			else prom_piece = -1;
			if (tap_r - 4 >= 0 && tap_c + 4 < 8 && (board[tap_r - 3][tap_c + 1] == -1 || board[tap_r - 3][tap_c + 1] == -2) && board[tap_r - 4][tap_c] == 0)
			{
				c2_tapped = 1;
				rlcu_valid = 1;
				if(turn == 1) prom_piece = 1;
			    else prom_piece = -1;
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c - 1] == -1 || board[tap_r - 5][tap_c - 1] == -2) && board[tap_r - 6][tap_c - 2] == 0)
				{
					c3_tapped = 1;
					rllcu_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c + 1] == -1 || board[tap_r - 5][tap_c + 1] == -1) && board[tap_r - 6][tap_c + 2] == 0)
				{
					c3_tapped = 1;
					rlrcu_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
			}
			if (tap_r - 4 >= 0 && (board[tap_r - 3][tap_c + 3] == -1 || board[tap_r - 3][tap_c + 3] == -2) && board[tap_r - 4][tap_c + 4] == 0)
			{
				c2_tapped = 1;
				rrcu_valid = 1;
				if(turn == 1) prom_piece = 1;
			    else prom_piece = -1;
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c + 3] == -1 || board[tap_r - 5][tap_c + 3] == -2) && board[tap_r - 6][tap_c + 2] == 0)
				{
					c3_tapped = 1;
					rrlcu_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && tap_c + 6 < 8 && (board[tap_r - 5][tap_c + 5] == -1 || board[tap_r - 5][tap_c + 5] == -2) && board[tap_r - 6][tap_c + 6] == 0)
				{
					c3_tapped = 1;
					rrrcu_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
			}
		}
		if (tap_r - 2 >= 0 && tap_r - 1 < 8 && tap_c >= 0 && tap_c + 2 < 8 && board[tap_r][tap_c] == -2 && (board[tap_r - 1][tap_c + 1] == 1 || board[tap_r - 1][tap_c + 1] == 2) && board[tap_r - 2][tap_c + 2] == 0)
		{
			c_tapped = 1;
			rcu_valid = 1;
			if(turn == 1) prom_piece = 1;
			else prom_piece = -1;
			if (tap_r - 4 >= 0 && tap_c + 4 < 8 && (board[tap_r - 3][tap_c + 1] == 1 || board[tap_r - 3][tap_c + 1] == 2) && board[tap_r - 4][tap_c] == 0)
			{
				c2_tapped = 1;
				rlcu_valid = 1;
				if(turn == 1) prom_piece = 1;
			    else prom_piece = -1;
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c - 1] == 1 || board[tap_r - 5][tap_c - 1] == 2) && board[tap_r - 6][tap_c - 2] == 0)
				{
					c3_tapped = 1;
					rllcu_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c + 1] == 1 || board[tap_r - 5][tap_c + 1] == 1) && board[tap_r - 6][tap_c + 2] == 0)
				{
					c3_tapped = 1;
					rlrcu_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
			}
			if (tap_r - 4 >= 0 && (board[tap_r - 3][tap_c + 3] == 1 || board[tap_r - 3][tap_c + 3] == 2) && board[tap_r - 4][tap_c + 4] == 0)
			{
				c2_tapped = 1;
				rrcu_valid = 1;
				if(turn == 1) prom_piece = 1;
			    else prom_piece = -1;
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c + 3] == 1 || board[tap_r - 5][tap_c + 3] == 2) && board[tap_r - 6][tap_c + 2] == 0)
				{
					c3_tapped = 1;
					rrlcu_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && tap_c + 6 < 8 && (board[tap_r - 5][tap_c + 5] == 1 || board[tap_r - 5][tap_c + 5] == 2) && board[tap_r - 6][tap_c + 6] == 0)
				{
					c3_tapped = 1;
					rrrcu_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
			}
		}
	}
	if ((turn == 1 && (board[tap_r][tap_c] == 2)) || (turn == 2 && (board[tap_r][tap_c] == -2))) // BLACK_LIKE MOVES FOR PROMOTED PIECES//
	{
		if (tap_r >= 0 && tap_r + 1 < 8 && tap_c - 1 >= 0 && tap_c < 8 && (board[tap_r][tap_c] == 2 || board[tap_r][tap_c] == -2) && board[tap_r + 1][tap_c - 1] == 0) // SIMPLE MOVE FOR BLACKS//
		{
			tapped2 = 1;
			ld_valid = 1;
			if(turn == 1) prom_piece = 1;
			else prom_piece = -1;
		}
		if (tap_r >= 0 && tap_r + 1 < 8 && tap_c >= 0 && tap_c + 1 < 8 && (board[tap_r][tap_c] == 2 || board[tap_r][tap_c] == -2) && board[tap_r + 1][tap_c + 1] == 0)
		{
			tapped2 = 1;
			rd_valid = 1;
			if(turn == 1) prom_piece = 1;
			else prom_piece = -1;
		}
		if (tap_r >= 0 && tap_r + 2 < 8 && tap_c - 2 >= 0 && tap_c < 8 && board[tap_r][tap_c] == 2 && (board[tap_r + 1][tap_c - 1] == -1 || board[tap_r + 1][tap_c - 1] == -2) && board[tap_r + 2][tap_c - 2] == 0)
		{
			c_tapped2 = 1;
			lcd_valid = 1;
			if(turn == 1) prom_piece = 1;
			else prom_piece = -1;
			if (tap_r + 4 < 8 && tap_c - 4 >= 0 && (board[tap_r + 3][tap_c - 3] == -1 || board[tap_r + 3][tap_c - 3] == -2) && board[tap_r + 4][tap_c - 4] == 0)
			{
				c2_tapped2 = 1;
				llcd_valid = 1;
				if(turn == 1) prom_piece = 1;
			    else prom_piece = -1;
				if (tap_r + 6 < 8 && tap_c - 6 >= 0 && (board[tap_r + 5][tap_c - 5] == -1 || board[tap_r + 5][tap_c - 5] == -2) && board[tap_r + 6][tap_c - 6] == 0) // TRIPLE CAPTURES//
				{
					c3_tapped2 = 1;
					lllcd_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c - 3] == -1 || board[tap_r + 5][tap_c - 3] == -2) && board[tap_r + 6][tap_c - 2] == 0)
				{
					c3_tapped2 = 1;
					llrcd_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
			}
			if (tap_r + 4 < 8 && (board[tap_r + 3][tap_c - 1] == -1 || board[tap_r + 3][tap_c - 1] == -2) && board[tap_r + 4][tap_c] == 0)
			{
				c2_tapped2 = 1;
				lrcd_valid = 1;
				if(turn == 1) prom_piece = 1;
			    else prom_piece = -1;
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c - 1] == -1 || board[tap_r + 5][tap_c - 1] == -2) && board[tap_r + 6][tap_c - 2] == 0)
				{
					c3_tapped2 = 1;
					lrlcd_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c + 1] == -1 || board[tap_r + 5][tap_c + 1] == -2) && board[tap_r + 6][tap_c + 2] == 0)
				{
					c3_tapped2 = 1;
					lrrcd_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
			}
		}
		if (tap_r >= 0 && tap_r + 2 < 8 && tap_c - 2 >= 0 && tap_c < 8 && board[tap_r][tap_c] == -2 && (board[tap_r + 1][tap_c - 1] == 1 || board[tap_r + 1][tap_c - 1] == 2) && board[tap_r + 2][tap_c - 2] == 0)
		{
			c_tapped2 = 1;
			lcd_valid = 1;
			if(turn == 1) prom_piece = 1;
			else prom_piece = -1;
			if (tap_r + 4 < 8 && tap_c - 4 >= 0 && (board[tap_r + 3][tap_c - 3] == 1 || board[tap_r + 3][tap_c - 3] == 2) && board[tap_r + 4][tap_c - 4] == 0)
			{
				c2_tapped2 = 1;
				llcd_valid = 1;
				if(turn == 1) prom_piece = 1;
			    else prom_piece = -1;
				if (tap_r + 6 < 8 && tap_c - 6 >= 0 && (board[tap_r + 5][tap_c - 5] == 1 || board[tap_r + 5][tap_c - 5] == 2) && board[tap_r + 6][tap_c - 6] == 0) // TRIPLE CAPTURES//
				{
					c3_tapped2 = 1;
					lllcd_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c - 3] == 1 || board[tap_r + 5][tap_c - 3] == 2) && board[tap_r + 6][tap_c - 2] == 0)
				{
					c3_tapped2 = 1;
					llrcd_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
			}
			if (tap_r + 4 < 8 && (board[tap_r + 3][tap_c - 1] == 1 || board[tap_r + 3][tap_c - 1] == 2) && board[tap_r + 4][tap_c] == 0)
			{
				c2_tapped2 = 1;
				lrcd_valid = 1;
				if(turn == 1) prom_piece = 1;
			    else prom_piece = -1;
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c - 1] == 1 || board[tap_r + 5][tap_c - 1] == 2) && board[tap_r + 6][tap_c - 2] == 0)
				{
					c3_tapped2 = 1;
					lrlcd_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c + 1] == 1 || board[tap_r + 5][tap_c + 1] == 2) && board[tap_r + 6][tap_c + 2] == 0)
				{
					c3_tapped2 = 1;
					lrrcd_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
			}
		}
		if (tap_r >= 0 && tap_r + 2 < 8 && tap_c >= 0 && tap_c + 2 < 8 && board[tap_r][tap_c] == 2 && (board[tap_r + 1][tap_c + 1] == -1 || board[tap_r + 1][tap_c + 1] == -2) && board[tap_r + 2][tap_c + 2] == 0)
		{
			c_tapped2 = 1;
			rcd_valid = 1;
			if(turn == 1) prom_piece = 1;
			else prom_piece = -1;
			if (tap_r + 4 < 8 && tap_c + 4 < 8 && (board[tap_r + 3][tap_c + 1] == -1 || board[tap_r + 3][tap_c + 1] == -2) && board[tap_r + 4][tap_c] == 0)
			{
				c2_tapped2 = 1;
				rlcd_valid = 1;
				if(turn == 1) prom_piece = 1;
			    else prom_piece = -1;
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c - 1] == -1 || board[tap_r + 5][tap_c - 1] == -2) && board[tap_r + 6][tap_c - 2] == 0)
				{
					c3_tapped2 = 1;
					rllcd_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c + 1] == -1 || board[tap_r + 5][tap_c + 1] == -2) && board[tap_r + 6][tap_c + 2] == 0)
				{
					c3_tapped2 = 1;
					rlrcd_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
			}
			if (tap_r + 4 < 8 && (board[tap_r + 3][tap_c + 3] == -1 || board[tap_r + 3][tap_c + 3] == -2) && board[tap_r + 4][tap_c + 4] == 0)
			{
				c2_tapped2 = 1;
				rrcd_valid = 1;
				if(turn == 1) prom_piece = 1;
			    else prom_piece = -1;
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c + 3] == -1 || board[tap_r + 5][tap_c + 3] == -2) && board[tap_r + 6][tap_c + 2] == 0)
				{
					c3_tapped2 = 1;
					rrlcd_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && tap_c + 6 < 8 && (board[tap_r - 5][tap_c + 5] == -1 || board[tap_r - 5][tap_c + 5] == -2) && board[tap_r + 6][tap_c + 6] == 0)
				{
					c3_tapped2 = 1;
					rrrcd_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
			}
		}
		if (tap_r >= 0 && tap_r + 2 < 8 && tap_c >= 0 && tap_c + 2 < 8 && board[tap_r][tap_c] == -2 && (board[tap_r + 1][tap_c + 1] == 1 || board[tap_r + 1][tap_c + 1] == 2) && board[tap_r + 2][tap_c + 2] == 0)
		{
			c_tapped2 = 1;
			rcd_valid = 1;
			if(turn == 1) prom_piece = 1;
			else prom_piece = -1;
			if (tap_r + 4 < 8 && tap_c + 4 < 8 && (board[tap_r + 3][tap_c + 1] == 1 || board[tap_r + 3][tap_c + 1] == 2) && board[tap_r + 4][tap_c] == 0)
			{
				c2_tapped2 = 1;
				rlcd_valid = 1;
				if(turn == 1) prom_piece = 1;
			    else prom_piece = -1;
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c - 1] == 1 || board[tap_r + 5][tap_c - 1] == 2) && board[tap_r + 6][tap_c - 2] == 0)
				{
					c3_tapped2 = 1;
					rllcd_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c + 1] == 1 || board[tap_r + 5][tap_c + 1] == 2) && board[tap_r + 6][tap_c + 2] == 0)
				{
					c3_tapped2 = 1;
					rlrcd_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
			}
			if (tap_r + 4 < 8 && (board[tap_r + 3][tap_c + 3] == 1 || board[tap_r + 3][tap_c + 3] == 2) && board[tap_r + 4][tap_c + 4] == 0)
			{
				c2_tapped2 = 1;
				rrcd_valid = 1;
				if(turn == 1) prom_piece = 1;
			    else prom_piece = -1;
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c + 3] == 1 || board[tap_r + 5][tap_c + 3] == 2) && board[tap_r + 6][tap_c + 2] == 0)
				{
					c3_tapped2 = 1;
					rrlcd_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && tap_c + 6 < 8 && (board[tap_r - 5][tap_c + 5] == 1 || board[tap_r - 5][tap_c + 5] == 2) && board[tap_r + 6][tap_c + 6] == 0)
				{
					c3_tapped2 = 1;
					rrrcd_valid = 1;
					if(turn == 1) prom_piece = 1;
			        else prom_piece = -1;
				}
			}
		}
	}
}
void reset_timer() {
	hour = 0;
	minute = 0; 
	sec = 0;
}

// update the sec += 1, and calculate the hour and min according to that
void update_timer_red() {
	sec++;
	if (sec >= 60) {
		sec = 0;
		minute++;
	} 
	if (minute >= 60) {
		minute = 0;
		hour++;
	}
}
void update_timer_black() {
	sec1++;
	if (sec1 >= 60) {
		sec1 = 0;
		minute1++;
	} 
	if (minute1 >= 60) {
		minute1 = 0;
		hour1++;
	}
}

// draw the timer in the game screen
void draw_timer_red() {
	ostringstream oss_h;
    oss_h << setw(2) << setfill('0') << hour;
    string formattedhour = oss_h.str();

	ostringstream oss_m;
    oss_m << setw(2) << setfill('0') << minute;
    string formattedminute = oss_m.str();

	ostringstream oss_s;
    oss_s << setw(2) << setfill('0') << sec;
    string formattedsec = oss_s.str();

	string temp = "RED                                 TIME : " + formattedhour + ":" + formattedminute + ":" + formattedsec;
	char* cstr = new char[temp.size() + 1];
	strcpy(cstr, temp.c_str());
	iText(844, 387, cstr , GLUT_BITMAP_HELVETICA_18);
}
void draw_timer_black() {
	ostringstream oss_h;
    oss_h << setw(2) << setfill('0') << hour1;
    string formattedhour = oss_h.str();

	ostringstream oss_m;
    oss_m << setw(2) << setfill('0') << minute1;
    string formattedminute = oss_m.str();

	ostringstream oss_s;
    oss_s << setw(2) << setfill('0') << sec1;
    string formattedsec = oss_s.str();

	string temp = "BLACK                            TIME : " + formattedhour + ":" + formattedminute + ":" + formattedsec;
	char* cstr = new char[temp.size() + 1];
	strcpy(cstr, temp.c_str());
	iText(844, 745, cstr , GLUT_BITMAP_HELVETICA_18);
}
int main()
{
	// place your own initialization codes here.
	load_anim1();
	load_anim2();
	load_anim3();
	setup();
	iSetTimer(1000, update_timer_red);
	iSetTimer(1000,update_timer_black);
	iSetTimer(20,update_anim1);
	iSetTimer(20,update_anim2);
	iSetTimer(20,update_anim3);
	iInitialize(1200, 800, "Checkers");
	iSetTimer(20,update_anim1);
	// codes written here after initialization doesnt get executed until the end of the program
	return 0;
}