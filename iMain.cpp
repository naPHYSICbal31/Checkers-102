#include "iGraphics.h"
#include <bits/stdc++.h>
#include <unistd.h>
#include <mmsystem.h>
#include <windows.h>
using namespace std;
void setup();
void show_moveable_positions(int tap_r, int tap_c);
void convert();
void reset_timer();
void update_timer_red();
void update_timer_black();
void draw_timer_red();
void draw_timer_black();
void show_pieces();
void playsound();
char name1[100], name2[100], name3[100], name4[100];
int len = 0, mode = 0;
enum screen
{
	TITLE,
	FORMAT,
	CLASSIC,
	END
};
screen now = TITLE;
int px = 158, py = 148;
int incr = 69;
int board[8][8] = {0}; // stores info about where is which piece
int tap_board[8][8] = {0};
char anim1[38][100];
char anim2[26][100];
char anim3[34][100];
char banim1[45][100];
char banim2[46][100];
char banim3[64][100];
int tapped = 0, c_tapped = 0, c2_tapped = 0, c3_tapped = 0;
int tap_c = 0, tap_r = 0;
int lu_valid = 0, ld_valid = 0, ru_valid = 0, rd_valid = 0, lcu_valid = 0, rcu_valid = 0, lcd_valid = 0, rcd_valid = 0, llcu_valid = 0, lrcu_valid = 0, llcd_valid = 0, lrcd_valid = 0, rlcu_valid = 0, rrcu_valid = 0, rlcd_valid = 0, rrcd_valid = 0, lllcu_valid = 0, llrcu_valid = 0, lrlcu_valid = 0, lrrcu_valid = 0, rllcu_valid = 0, rlrcu_valid = 0, rrlcu_valid = 0, rrrcu_valid = 0, lllcd_valid = 0, llrcd_valid = 0, lrlcd_valid = 0, lrrcd_valid = 0, rllcd_valid = 0, rlrcd_valid = 0, rrlcd_valid = 0, rrrcd_valid = 0, tapped2 = 0, c_tapped2 = 0, c2_tapped2 = 0, c3_tapped2 = 0;
int turn = 1;
int prom_piece = 0;
int hour = 0, minute = 0, sec = 0, hour1 = 0, minute1 = 0, sec1 = 0;
int idx = 0;
int idx1 = 0;
int idx2 = 0;
int bidx1 = 0;
int bidx2 = 0;
int bidx3 = 0;
int classic = 0, blitz = 0;
int anim1_clicked = 0;
int anim2_clicked = 0;
int animb1_clicked = 0;
int animb2_clicked = 0;
int move_anim2 = 0;
int move_anim3 = 0;
int move_banim2 = 0;
int move_banim3 = 0;
int pieces_b = 0, pieces_r = 0;
int done1 = 0, done2 = 0;
char p_black[50];
char p_red[50];
int x = 1;
int y = 1;
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
		sprintf(anim1[i], "scene%02d.bmp", i);
	}
}
void update_anim1()
{
	if (idx < 37)
	{
		idx++;
	}
}
void load_anim2()
{
	for (int i = 0; i < 26; i++)
	{
		sprintf(anim2[i], "anim2%02d.bmp", i);
	}
}
void update_anim2()
{
	if (idx1 < 25)
	{
		idx1++;
	}
}
void load_anim3()
{
	for (int i = 0; i < 34; i++)
	{
		sprintf(anim3[i], "anim3%02d.bmp", i);
	}
}
void update_anim3()
{
	if (idx2 < 33)
	{
		idx2++;
	}
}
void load_banim1()
{
	for (int i = 0; i < 45; i++)
	{
		sprintf(banim1[i], "animb%02d.bmp", i);
	}
}
void update_banim2()
{
	if (bidx2 < 45)
	{
		bidx2++;
	}
}
void update_banim1()
{
	if (bidx1 < 44)
	{
		bidx1++;
	}
}
void load_banim2()
{
	for (int i = 0; i < 46; i++)
	{
		sprintf(banim2[i], "animb1%02d.bmp", i);
	}
}
void load_banim3()
{
	for (int i = 0; i < 64; i++)
	{
		sprintf(banim3[i], "animb2%02d.bmp", i);
	}
}
void update_banim3()
{
	if (bidx3 < 63)
	{
		bidx3++;
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
	iPauseTimer(5);
	iPauseTimer(6);
	iPauseTimer(7);
	switch (now)
	{
	case TITLE:
		iShowBMP(0, 0, "title.bmp");
		break;
	case FORMAT:
		if (classic == 1)
		{
			if (move_anim2 == 0)
			{
				iResumeTimer(2);
				iShowBMP(0, 0, anim1[idx]);
			}
			if (anim1_clicked == 1 && move_anim3 == 0)
			{
				iResumeTimer(3);
				move_anim2 = 1;
				iShowBMP(0, 0, anim2[idx1]);
			}
			if (anim2_clicked == 1)
			{
				iResumeTimer(4);
				move_anim3 = 1;
				iShowBMP(0, 0, anim3[idx2]);
				if (idx2 == 33)
				{
					now = CLASSIC;
				}
				if (idx2 == 7 && (done1 == 0 || done2 == 0))
				{
					iPauseTimer(4);
					iSetColor(150, 150, 150);
					iFilledRectangle(150, 520, 350, 50);
					iFilledRectangle(700, 520, 350, 50);
					iSetColor(0, 0, 0);
					iRectangle(150, 520, 350, 50);
					iRectangle(700, 520, 350, 50);
					iText(150, 620, "Enter Name For Player 1", GLUT_BITMAP_HELVETICA_18);
					iText(150, 595, "(Plays Red)", GLUT_BITMAP_HELVETICA_18);
					iText(700, 620, "Enter Name For Player 2", GLUT_BITMAP_HELVETICA_18);
					iText(700, 595, "(Plays Black)", GLUT_BITMAP_HELVETICA_18);
					if (mode == 1)
					{
						iSetColor(0, 0, 0);
						iText(155, 540, name1, GLUT_BITMAP_HELVETICA_18);
					}
					if (mode == 2)
					{
						iSetColor(0, 0, 0);
						iText(705, 540, name3, GLUT_BITMAP_HELVETICA_18);
					}
					if (done1 == 1 && done2 == 1)
					{
						iResumeTimer(4);
						done1 = 0, done2 = 0;
					}
				}
			}
		}
		else if (blitz == 1)
		{
			if (move_banim2 == 0)
			{
				iResumeTimer(5);
				iShowBMP(0, 0, banim1[bidx1]);
			}
			if (animb1_clicked == 1 && move_banim3 == 0)
			{
				iResumeTimer(6);
				iShowBMP(0, 0, banim2[bidx2]);
				move_banim2 = 1;
			}
			if (animb2_clicked == 1)
			{
				move_banim3 = 1;
				iResumeTimer(7);
				iShowBMP(0, 0, banim3[bidx3]);
				if (bidx3 == 63)
				{
					now = CLASSIC;
				}
				if (bidx3 == 15 && (done1 == 0 || done2 == 0))
				{
					iPauseTimer(7);
					iSetColor(255, 255, 255);
					iFilledRectangle(150, 520, 350, 50);
					iFilledRectangle(700, 520, 350, 50);
					iSetColor(255, 255, 255);
					iRectangle(150, 520, 350, 50);
					iRectangle(700, 520, 350, 50);
					iText(150, 620, "Enter Name For Player 1", GLUT_BITMAP_HELVETICA_18);
					iText(150, 595, "(Plays Red)", GLUT_BITMAP_HELVETICA_18);
					iText(700, 620, "Enter Name For Player 2", GLUT_BITMAP_HELVETICA_18);
					iText(700, 595, "(Plays Black)", GLUT_BITMAP_HELVETICA_18);
					if (mode == 1)
					{
						iSetColor(0, 0, 0);
						iText(155, 540, name1, GLUT_BITMAP_HELVETICA_18);
					}
					if (mode == 2)
					{
						iSetColor(0, 0, 0);
						iText(705, 540, name3, GLUT_BITMAP_HELVETICA_18);
					}
					if (done1 == 1 && done2 == 1)
					{
						iResumeTimer(7);
						done1 = 0, done2 = 0;
					}
				}
			}
		}
		break;
	case CLASSIC:
		if (y == 1)
		{
			PlaySound(NULL, NULL, SND_LOOP | SND_ASYNC);
			y = 0;
		}
		if (turn == 1)
		{
			iResumeTimer(0);
			iPauseTimer(1);
		}
		else
		{
			iPauseTimer(0);
			iResumeTimer(1);
		}
		if (classic == 1)
		{
			iShowBMP(0, 0, "checker_board_classic.bmp");
		}
		if (blitz == 1)
		{
			iShowBMP(0, 0, "checker_board_blitz.bmp");
		}
		iShowBMP(814, 0, "sidebar.bmp");
		if (tapped == 1 || c_tapped == 1 || c2_tapped == 1 || c3_tapped == 1)
		{
			iShowBMP(tap_c * incr + px - 1, (7 - tap_r) * incr + py - 1, "highlight.bmp");
		}
		if (tapped2 == 1 || c_tapped2 == 1 || c2_tapped2 == 1 || c3_tapped2 == 1)
		{
			iShowBMP(tap_c * incr + px - 1, (7 - tap_r) * incr + py - 1, "highlight.bmp");
		}
		for (int i = 0; i < 8; i += 1)
		{
			for (int j = 0; j < 8; j += 1)
			{
				if (board[i][j] == 1)
				{
					iShowBMP2(px + incr * j, py + incr * (7 - i), "checker_red.bmp", 0);
					pieces_r += 1;
				}
				else if (board[i][j] == -1)
				{
					iShowBMP2(px + incr * j, py + incr * (7 - i), "checker_black.bmp", 0);
					pieces_b += 1;
				}
				else if (board[i][j] == 2)
				{
					iShowBMP2(px + incr * j, py + incr * (7 - i), "checker_red_prom.bmp", 0);
					pieces_r += 1;
				}
				else if (board[i][j] == -2)
				{
					iShowBMP2(px + incr * j, py + incr * (7 - i), "checker_black_prom.bmp", 0);
					pieces_b += 1;
				}
			}
		}
		sprintf(p_red, "                                 PIECES LEFT : %d", pieces_r);
		sprintf(p_black, "                                 PIECES LEFT : %d", pieces_b);
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
		iSetColor(255, 0, 0);
		if (turn == 1)
		{
			iFilledCircle(828, 395, 5, 100);
		}
		if (turn == 2)
		{
			iFilledCircle(828, 753, 5, 100);
		}
		iSetColor(0, 0, 0);
		draw_timer_red();
		draw_timer_black();
		if ((classic == 1 && pieces_b == 0) || (blitz == 1 && pieces_b <= 2) || (blitz == 1 && minute1 >= 5) || minute1 >= 10)
		{
			iSetColor(0, 255, 0);
			iFilledRectangle(850, 300, 300, 10);
			iSetColor(0, 0, 0);
			if (x == 1)
			{
				strcat(name2, " WON");
				x = 0;
			}
			iText(950, 250, name2, GLUT_BITMAP_HELVETICA_18);
			// iText(1000,250,"WON",GLUT_BITMAP_HELVETICA_18);
			iSetColor(255, 0, 0);
			iFilledRectangle(850, 650, 300, 10);
			iSetColor(0, 0, 0);
		}
		if ((classic == 1 && pieces_r == 0) || (blitz == 1 && pieces_r <= 2) || (blitz == 1 && minute == 5) || minute >= 10)
		{
			iSetColor(0, 255, 0);
			iFilledRectangle(850, 650, 300, 10);
			iSetColor(0, 0, 0);
			if (x == 1)
			{
				strcat(name4, " WON");
				x = 0;
			}
			iText(950, 600, name4, GLUT_BITMAP_HELVETICA_18);
			// iText(1000,600,"WON",GLUT_BITMAP_HELVETICA_18);
			iSetColor(255, 0, 0);
			iFilledRectangle(850, 300, 300, 10);
			iSetColor(0, 0, 0);
		}
		pieces_b = 0, pieces_r = 0;
		iText(844, 357, p_red, GLUT_BITMAP_HELVETICA_18);
		iText(844, 715, p_black, GLUT_BITMAP_HELVETICA_18);
		break;
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
	printf("x = %d y = %d", mx, my);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (now == TITLE)
		{
			if ((375 <= mx) && (mx <= 570) && (125 <= my) && (my <= 200))
			{
				now = FORMAT;
				classic = 1;
				return;
			}
			if ((650 <= mx) && (mx <= 810) && (130 <= my) && (my <= 200))
			{
				now = FORMAT;
				blitz = 1;
				return;
			}
		}
		if (now == FORMAT)
		{
			if (classic == 1 && move_anim2 == 0)
				anim1_clicked = 1;

			if (classic == 1 && move_anim2 == 1)
				anim2_clicked = 1;
			if (idx2 == 7 && mx <= 590)
				mode = 1;
			if (bidx3 == 15 && mx <= 590)
				mode = 1;
			if (idx2 == 7 && mx >= 610)
				mode = 2;
			if (bidx3 == 15 && mx >= 610)
				mode = 2;
			if (blitz == 1 && move_banim2 == 0)
				animb1_clicked = 1;
			if (blitz == 1 && move_banim2 == 1)
				animb2_clicked = 1;
		}
		if (tapped == 0 && tapped2 == 0 && c_tapped == 0 && c_tapped2 == 0 && c2_tapped == 0 && c2_tapped2 == 0 && c3_tapped == 0 && c3_tapped2 == 0) // FIRST TAP FOR A PIECE//
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
				if (prom_piece == 1)
				{
					board[tap_r - 1][tap_c - 1] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r - 1][tap_c - 1] = -2;
				}
				else
				{
					board[tap_r - 1][tap_c - 1] = 1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				playsound();
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (tapped == 1 && ru_valid == 1 && tap_c2 == tap_c + 1 && tap_r2 == tap_r - 1)
			{
				if (prom_piece == 1)
				{
					board[tap_r - 1][tap_c + 1] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r - 1][tap_c + 1] = -2;
				}
				else
				{
					board[tap_r - 1][tap_c + 1] = 1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c_tapped == 1 && lcu_valid == 1 && tap_c2 == tap_c - 2 && tap_r2 == tap_r - 2)
			{
				if (prom_piece == 1)
				{
					board[tap_r - 2][tap_c - 2] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r - 2][tap_c - 2] = -2;
				}
				else
				{
					board[tap_r - 2][tap_c - 2] = 1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r - 1][tap_c - 1] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c_tapped == 1 && rcu_valid == 1 && tap_c2 == tap_c + 2 && tap_r2 == tap_r - 2)
			{
				if (prom_piece == 1)
				{
					board[tap_r - 2][tap_c + 2] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r - 2][tap_c + 2] = -2;
				}
				else
				{
					board[tap_r - 2][tap_c + 2] = 1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r - 1][tap_c + 1] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (tapped2 == 1 && ld_valid == 1 && tap_c2 == tap_c - 1 && tap_r2 == tap_r + 1)
			{
				if (prom_piece == 1)
				{
					board[tap_r + 1][tap_c - 1] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r + 1][tap_c - 1] = -2;
				}
				else
				{
					board[tap_r + 1][tap_c - 1] = -1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (tapped2 == 1 && rd_valid == 1 && tap_c2 == tap_c + 1 && tap_r2 == tap_r + 1)
			{
				if (prom_piece == 1)
				{
					board[tap_r + 1][tap_c + 1] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r + 1][tap_c + 1] = -2;
				}
				else
				{
					board[tap_r + 1][tap_c + 1] = -1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c_tapped2 == 1 && lcd_valid == 1 && tap_c2 == tap_c - 2 && tap_r2 == tap_r + 2)
			{
				if (prom_piece == 1)
				{
					board[tap_r + 2][tap_c - 2] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r + 2][tap_c - 2] = -2;
				}
				else
				{
					board[tap_r + 2][tap_c - 2] = -1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r + 1][tap_c - 1] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c_tapped2 == 1 && rcd_valid == 1 && tap_c2 == tap_c + 2 && tap_r2 == tap_r + 2)
			{
				if (prom_piece == 1)
				{
					board[tap_r + 2][tap_c + 2] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r + 2][tap_c + 2] = -2;
				}
				else
				{
					board[tap_r + 2][tap_c + 2] = -1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r + 1][tap_c + 1] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c2_tapped == 1 && llcu_valid == 1 && tap_c2 == tap_c - 4 && tap_r2 == tap_r - 4)
			{
				if (prom_piece == 1)
				{
					board[tap_r - 4][tap_c - 4] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r - 4][tap_c - 4] = -2;
				}
				else
				{
					board[tap_r - 4][tap_c - 4] = 1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r - 1][tap_c - 1] = 0;
				board[tap_r - 3][tap_c - 3] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c2_tapped == 1 && lrcu_valid == 1 && tap_c2 == tap_c && tap_r2 == tap_r - 4)
			{
				if (prom_piece == 1)
				{
					board[tap_r - 4][tap_c] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r - 4][tap_c] = -2;
				}
				else
				{
					board[tap_r - 4][tap_c] = 1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r - 1][tap_c - 1] = 0;
				board[tap_r - 3][tap_c - 1] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c2_tapped == 1 && rlcu_valid == 1 && tap_c2 == tap_c && tap_r2 == tap_r - 4)
			{
				if (prom_piece == 1)
				{
					board[tap_r - 4][tap_c] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r - 4][tap_c] = -2;
				}
				else
				{
					board[tap_r - 4][tap_c] = 1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r - 1][tap_c + 1] = 0;
				board[tap_r - 3][tap_c + 1] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c2_tapped == 1 && rrcu_valid == 1 && tap_c2 == tap_c + 4 && tap_r2 == tap_r - 4)
			{
				if (prom_piece == 1)
				{
					board[tap_r - 4][tap_c + 4] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r - 4][tap_c + 4] = -2;
				}
				else
				{
					board[tap_r - 4][tap_c + 4] = 1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r - 1][tap_c + 1] = 0;
				board[tap_r - 3][tap_c + 3] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c2_tapped2 == 1 && llcd_valid == 1 && tap_c2 == tap_c - 4 && tap_r2 == tap_r + 4)
			{
				if (prom_piece == 1)
				{
					board[tap_r + 4][tap_c - 4] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r + 4][tap_c - 4] = -2;
				}
				else
				{
					board[tap_r + 4][tap_c - 4] = -1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r + 1][tap_c - 1] = 0;
				board[tap_r + 3][tap_c - 3] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c2_tapped2 == 1 && lrcd_valid == 1 && tap_c2 == tap_c && tap_r2 == tap_r + 4)
			{
				if (prom_piece == 1)
				{
					board[tap_r + 4][tap_c] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r + 4][tap_c] = -2;
				}
				else
				{
					board[tap_r + 4][tap_c] = -1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r + 1][tap_c - 1] = 0;
				board[tap_r + 3][tap_c - 1] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c2_tapped2 == 1 && rlcd_valid == 1 && tap_c2 == tap_c && tap_r2 == tap_r + 4)
			{
				if (prom_piece == 1)
				{
					board[tap_r + 4][tap_c] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r + 4][tap_c] = -2;
				}
				else
				{
					board[tap_r + 4][tap_c] = -1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r + 1][tap_c + 1] = 0;
				board[tap_r + 3][tap_c + 1] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c2_tapped2 == 1 && rrcd_valid == 1 && tap_c2 == tap_c + 4 && tap_r2 == tap_r + 4)
			{
				if (prom_piece == 1)
				{
					board[tap_r - 4][tap_c + 4] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r - 4][tap_c + 4] = -2;
				}
				else
				{
					board[tap_r - 4][tap_c + 4] = -1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r + 1][tap_c + 1] = 0;
				board[tap_r + 3][tap_c + 3] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c3_tapped == 1 && lllcu_valid == 1 && tap_c2 == tap_c - 6 && tap_r2 == tap_r - 6)
			{
				if (prom_piece == 1)
				{
					board[tap_r - 6][tap_c - 6] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r - 6][tap_c - 6] = -2;
				}
				else
				{
					board[tap_r - 6][tap_c - 6] = 1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r - 1][tap_c - 1] = 0;
				board[tap_r - 3][tap_c - 3] = 0;
				board[tap_r - 5][tap_c - 5] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c3_tapped == 1 && llrcu_valid == 1 && tap_c2 == tap_c - 2 && tap_r2 == tap_r - 6)
			{
				if (prom_piece == 1)
				{
					board[tap_r - 6][tap_c - 2] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r - 6][tap_c - 2] = -2;
				}
				else
				{
					board[tap_r - 6][tap_c - 2] = 1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r - 1][tap_c - 1] = 0;
				board[tap_r - 3][tap_c - 3] = 0;
				board[tap_r - 5][tap_c - 3] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c3_tapped == 1 && lrlcu_valid == 1 && tap_c2 == tap_c - 2 && tap_r2 == tap_r - 6)
			{
				if (prom_piece == 1)
				{
					board[tap_r - 6][tap_c - 2] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r - 6][tap_c - 2] = -2;
				}
				else
				{
					board[tap_r - 6][tap_c - 2] = 1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r - 1][tap_c - 1] = 0;
				board[tap_r - 3][tap_c - 1] = 0;
				board[tap_r - 5][tap_c - 1] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c3_tapped == 1 && lrrcu_valid == 1 && tap_c2 == tap_c + 2 && tap_r2 == tap_r - 6)
			{
				if (prom_piece == 1)
				{
					board[tap_r - 6][tap_c + 2] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r - 6][tap_c + 2] = -2;
				}
				else
				{
					board[tap_r - 6][tap_c + 2] = 1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r - 1][tap_c - 1] = 0;
				board[tap_r - 3][tap_c - 1] = 0;
				board[tap_r - 5][tap_c + 1] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c3_tapped == 1 && rllcu_valid == 1 && tap_c2 == tap_c - 2 && tap_r2 == tap_r - 6)
			{
				if (prom_piece == 1)
				{
					board[tap_r - 6][tap_c - 2] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r - 6][tap_c - 2] = -2;
				}
				else
				{
					board[tap_r - 6][tap_c - 2] = 1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r - 1][tap_c + 1] = 0;
				board[tap_r - 3][tap_c + 1] = 0;
				board[tap_r - 5][tap_c - 1] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c3_tapped == 1 && rlrcu_valid == 1 && tap_c2 == tap_c + 2 && tap_r2 == tap_r - 6)
			{
				if (prom_piece == 1)
				{
					board[tap_r - 6][tap_c + 2] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r - 6][tap_c + 2] = -2;
				}
				else
				{
					board[tap_r - 6][tap_c + 2] = 1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r - 1][tap_c + 1] = 0;
				board[tap_r - 3][tap_c + 1] = 0;
				board[tap_r - 5][tap_c + 1] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c3_tapped == 1 && rrlcu_valid == 1 && tap_c2 == tap_c + 2 && tap_r2 == tap_r - 6)
			{
				if (prom_piece == 1)
				{
					board[tap_r - 6][tap_c + 2] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r - 6][tap_c + 2] = -2;
				}
				else
				{
					board[tap_r - 6][tap_c + 2] = 1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r - 1][tap_c + 1] = 0;
				board[tap_r - 3][tap_c + 3] = 0;
				board[tap_r - 5][tap_c + 3] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c3_tapped == 1 && rrrcu_valid == 1 && tap_c2 == tap_c + 6 && tap_r2 == tap_r - 6)
			{
				if (prom_piece == 1)
				{
					board[tap_r - 6][tap_c + 6] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r - 6][tap_c + 6] = -2;
				}
				else
				{
					board[tap_r - 6][tap_c + 6] = 1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r - 1][tap_c + 1] = 0;
				board[tap_r - 3][tap_c + 3] = 0;
				board[tap_r - 5][tap_c + 5] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			// BLACK 3RD CAPTURE//
			if (c3_tapped2 == 1 && lllcd_valid == 1 && tap_c2 == tap_c - 6 && tap_r2 == tap_r + 6)
			{
				if (prom_piece == 1)
				{
					board[tap_r + 6][tap_c - 6] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r + 6][tap_c - 6] = -2;
				}
				else
				{
					board[tap_r + 6][tap_c - 6] = -1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r + 1][tap_c - 1] = 0;
				board[tap_r + 3][tap_c - 3] = 0;
				board[tap_r + 5][tap_c - 5] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c3_tapped2 == 1 && llrcd_valid == 1 && tap_c2 == tap_c - 2 && tap_r2 == tap_r + 6)
			{
				if (prom_piece == 1)
				{
					board[tap_r + 6][tap_c - 2] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r + 6][tap_c - 2] = -2;
				}
				else
				{
					board[tap_r + 6][tap_c - 2] = -1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r + 1][tap_c - 1] = 0;
				board[tap_r + 3][tap_c - 3] = 0;
				board[tap_r + 5][tap_c - 3] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c3_tapped2 == 1 && lrlcd_valid == 1 && tap_c2 == tap_c - 2 && tap_r2 == tap_r + 6)
			{
				if (prom_piece == 1)
				{
					board[tap_r + 6][tap_c - 2] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r + 6][tap_c - 2] = -2;
				}
				else
				{
					board[tap_r + 6][tap_c - 2] = -1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r + 1][tap_c - 1] = 0;
				board[tap_r + 3][tap_c - 1] = 0;
				board[tap_r + 5][tap_c - 1] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c3_tapped2 == 1 && lrrcd_valid == 1 && tap_c2 == tap_c + 2 && tap_r2 == tap_r + 6)
			{
				if (prom_piece == 1)
				{
					board[tap_r + 6][tap_c + 2] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r + 6][tap_c + 2] = -2;
				}
				else
				{
					board[tap_r + 6][tap_c + 2] = -1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r + 1][tap_c - 1] = 0;
				board[tap_r + 3][tap_c - 1] = 0;
				board[tap_r + 5][tap_c + 1] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c3_tapped2 == 1 && rllcd_valid == 1 && tap_c2 == tap_c - 2 && tap_r2 == tap_r + 6)
			{
				if (prom_piece == 1)
				{
					board[tap_r + 6][tap_c - 2] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r + 6][tap_c - 2] = -2;
				}
				else
				{
					board[tap_r + 6][tap_c - 2] = -1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r + 1][tap_c + 1] = 0;
				board[tap_r + 3][tap_c + 1] = 0;
				board[tap_r + 5][tap_c - 1] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c3_tapped2 == 1 && rlrcd_valid == 1 && tap_c2 == tap_c + 2 && tap_r2 == tap_r + 6)
			{
				if (prom_piece == 1)
				{
					board[tap_r + 6][tap_c + 2] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r + 6][tap_c + 2] = -2;
				}
				else
				{
					board[tap_r + 6][tap_c + 2] = -1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r + 1][tap_c + 1] = 0;
				board[tap_r + 3][tap_c + 1] = 0;
				board[tap_r + 5][tap_c + 1] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c3_tapped2 == 1 && rrlcd_valid == 1 && tap_c2 == tap_c + 2 && tap_r2 == tap_r + 6)
			{
				if (prom_piece == 1)
				{
					board[tap_r + 6][tap_c + 2] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r + 6][tap_c + 2] = -2;
				}
				else
				{
					board[tap_r + 6][tap_c + 2] = -1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r + 1][tap_c + 1] = 0;
				board[tap_r + 3][tap_c + 3] = 0;
				board[tap_r + 5][tap_c + 3] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (c3_tapped2 == 1 && rrrcd_valid == 1 && tap_c2 == tap_c + 6 && tap_r2 == tap_r + 6)
			{
				if (prom_piece == 1)
				{
					board[tap_r + 6][tap_c + 6] = 2;
				}
				else if (prom_piece == -1)
				{
					board[tap_r + 6][tap_c + 6] = -2;
				}
				else
				{
					board[tap_r + 6][tap_c + 6] = -1;
				}
				board[tap_r][tap_c] = 0;
				playsound();

				board[tap_r + 1][tap_c + 1] = 0;
				board[tap_r + 3][tap_c + 3] = 0;
				board[tap_r + 5][tap_c + 5] = 0;
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			for (int r = 0, c = 1; c < 8; c += 2)
			{
				if (board[r][c] == 1)
				{
					board[r][c] = 2;
				}
			}
			for (int r = 7, c = 0; c < 8; c += 2)
			{
				if (board[r][c] == -1)
				{

					board[r][c] = -2;
				}
			}
			tapped = 0, c_tapped = 0, c2_tapped = 0, c3_tapped = 0, lu_valid = 0, ld_valid = 0, ru_valid = 0, rd_valid = 0, lcu_valid = 0, rcu_valid = 0, llcu_valid = 0, lrcu_valid = 0, rlcu_valid = 0, rrcu_valid = 0, llrcu_valid = 0, lrlcu_valid = 0, lrrcu_valid = 0, rllcu_valid = 0, rlrcu_valid = 0, rrlcu_valid = 0, rrrcu_valid = 0, lcd_valid = 0, rcd_valid = 0, llcd_valid = 0, lrcd_valid = 0, rlcd_valid = 0, rrcd_valid = 0, llrcd_valid = 0, lrlcd_valid = 0, lrrcd_valid = 0, rllcd_valid = 0, rlrcd_valid = 0, rrlcd_valid = 0, rrrcd_valid = 0, tapped2 = 0, c_tapped2 = 0, c2_tapped2 = 0, c3_tapped2 = 0;
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
	if ((idx2 == 7 && mode == 1) || (bidx3 == 15 && mode == 1))
	{
		if (key == '\r')
		{
			strcpy(name2, name1);
			printf("%s\n", name2);
			name1[0] = 'E', name1[1] = 'N', name1[2] = 'T', name1[3] = 'E', name1[4] = 'R', name1[5] = 'E', name1[6] = 'D';
			for (int i = 7; i < len; i++)
			{
				name1[i] = 0;
			}
			len = 0;
			done1 = 1;
		}
		else
		{
			if (key == 8)
			{
				if (len > 0)
				{
					len--;
					name1[len] = '\0';
				}
				return;
			}
			name1[len] = key;
			len++;
		}
	}
	if ((idx2 == 7 && mode == 2) || (bidx3 == 15 && mode == 2))
	{
		if (key == '\r')
		{
			strcpy(name4, name3);
			printf("%s\n", name4);
			name3[0] = 'E', name3[1] = 'N', name3[2] = 'T', name3[3] = 'E', name3[4] = 'R', name3[5] = 'E', name3[6] = 'D';
			for (int i = 7; i < len; i++)
			{
				name3[i] = 0;
			}
			len = 0;
			done2 = 1;
		}
		else
		{
			if (key == 8)
			{
				if (len > 0)
				{
					len--;
					name3[len] = '\0';
				}
				return;
			}
			name3[len] = key;
			len++;
		}
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
	if ((turn == 1 && ((board[tap_r][tap_c] == 2)) || ((turn == 2 && board[tap_r][tap_c] == -2)))) // RED_LIKE TURNS FOR PROMOTED PIECES
	{
		if (tap_r - 1 >= 0 && tap_r - 1 < 8 && tap_c - 1 >= 0 && tap_c < 8 && (board[tap_r][tap_c] == 2 || board[tap_r][tap_c] == -2) && board[tap_r - 1][tap_c - 1] == 0) // SIMPLE MOVE FOR RED DIRECTION//
		{
			tapped = 1;
			lu_valid = 1;
			if (turn == 1)
				prom_piece = 1;
			else
				prom_piece = -1;
		}
		if (tap_r - 1 >= 0 && tap_r - 1 < 8 && tap_c >= 0 && tap_c + 1 < 8 && (board[tap_r][tap_c] == 2 || board[tap_r][tap_c] == -2) && board[tap_r - 1][tap_c + 1] == 0)
		{
			tapped = 1;
			ru_valid = 1;
			if (turn == 1)
				prom_piece = 1;
			else
				prom_piece = -1;
		}
		if (tap_r - 2 >= 0 && tap_r - 1 < 8 && tap_c - 2 >= 0 && tap_c < 8 && board[tap_r][tap_c] == 2 && (board[tap_r - 1][tap_c - 1] == -1 || board[tap_r - 1][tap_c - 1] == -2) && board[tap_r - 2][tap_c - 2] == 0) // RED CAPTURTES BLACK//
		{
			c_tapped = 1;
			lcu_valid = 1;
			if (turn == 1)
				prom_piece = 1;
			else
				prom_piece = -1;
			if (tap_r - 4 >= 0 && tap_c - 4 >= 0 && (board[tap_r - 3][tap_c - 3] == -1 || board[tap_r - 3][tap_c - 3] == -2) && board[tap_r - 4][tap_c - 4] == 0) // DOUBLE CAPTURES//
			{
				c2_tapped = 1;
				llcu_valid = 1;
				if (turn == 1)
					prom_piece = 1;
				else
					prom_piece = -1;
				if (tap_r - 6 >= 0 && tap_c - 6 >= 0 && (board[tap_r - 5][tap_c - 5] == -1 || board[tap_r - 5][tap_c - 5] == -2) && board[tap_r - 6][tap_c - 6] == 0) // TRIPLE CAPTURES//
				{
					c3_tapped = 1;
					lllcu_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c - 3] == -1 || board[tap_r - 5][tap_c - 3] == -2) && board[tap_r - 6][tap_c - 2] == 0)
				{
					c3_tapped = 1;
					llrcu_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
			}
			if (tap_r - 4 >= 0 && (board[tap_r - 3][tap_c - 1] == -1 || board[tap_r - 3][tap_c - 1] == -2) && board[tap_r - 4][tap_c] == 0)
			{
				c2_tapped = 1;
				lrcu_valid = 1;
				if (turn == 1)
					prom_piece = 1;
				else
					prom_piece = -1;
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c - 1] == -1 || board[tap_r - 5][tap_c - 1] == -2) && board[tap_r - 6][tap_c - 2] == 0)
				{
					c3_tapped = 1;
					lrlcu_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c + 1] == -1 || board[tap_r - 5][tap_c + 1] == -2) && board[tap_r - 6][tap_c + 2] == 0)
				{
					c3_tapped = 1;
					lrrcu_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
			}
		}
		if (tap_r - 2 >= 0 && tap_r - 1 < 8 && tap_c - 2 >= 0 && tap_c < 8 && board[tap_r][tap_c] == -2 && (board[tap_r - 1][tap_c - 1] == 1 || board[tap_r - 1][tap_c - 1] == 2) && board[tap_r - 2][tap_c - 2] == 0) // RED CAPTURTES BLACK//
		{
			c_tapped = 1;
			lcu_valid = 1;
			if (turn == 1)
				prom_piece = 1;
			else
				prom_piece = -1;
			if (tap_r - 4 >= 0 && tap_c - 4 >= 0 && (board[tap_r - 3][tap_c - 3] == 1 || board[tap_r - 3][tap_c - 3] == 2) && board[tap_r - 4][tap_c - 4] == 0) // DOUBLE CAPTURES//
			{
				c2_tapped = 1;
				llcu_valid = 1;
				if (turn == 1)
					prom_piece = 1;
				else
					prom_piece = -1;
				if (tap_r - 6 >= 0 && tap_c - 6 >= 0 && (board[tap_r - 5][tap_c - 5] == 1 || board[tap_r - 5][tap_c - 5] == 2) && board[tap_r - 6][tap_c - 6] == 0) // TRIPLE CAPTURES//
				{
					c3_tapped = 1;
					lllcu_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c - 3] == 1 || board[tap_r - 5][tap_c - 3] == 2) && board[tap_r - 6][tap_c - 2] == 0)
				{
					c3_tapped = 1;
					llrcu_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
			}
			if (tap_r - 4 >= 0 && (board[tap_r - 3][tap_c - 1] == 1 || board[tap_r - 3][tap_c - 1] == 2) && board[tap_r - 4][tap_c] == 0)
			{
				c2_tapped = 1;
				lrcu_valid = 1;
				if (turn == 1)
					prom_piece = 1;
				else
					prom_piece = -1;
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c - 1] == 1 || board[tap_r - 5][tap_c - 1] == 2) && board[tap_r - 6][tap_c - 2] == 0)
				{
					c3_tapped = 1;
					lrlcu_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c + 1] == 1 || board[tap_r - 5][tap_c + 1] == 2) && board[tap_r - 6][tap_c + 2] == 0)
				{
					c3_tapped = 1;
					lrrcu_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
			}
		}
		if (tap_r - 2 >= 0 && tap_r - 1 < 8 && tap_c >= 0 && tap_c + 2 < 8 && board[tap_r][tap_c] == 2 && (board[tap_r - 1][tap_c + 1] == -1 || board[tap_r - 1][tap_c + 1] == -2) && board[tap_r - 2][tap_c + 2] == 0)
		{
			c_tapped = 1;
			rcu_valid = 1;
			if (turn == 1)
				prom_piece = 1;
			else
				prom_piece = -1;
			if (tap_r - 4 >= 0 && tap_c + 4 < 8 && (board[tap_r - 3][tap_c + 1] == -1 || board[tap_r - 3][tap_c + 1] == -2) && board[tap_r - 4][tap_c] == 0)
			{
				c2_tapped = 1;
				rlcu_valid = 1;
				if (turn == 1)
					prom_piece = 1;
				else
					prom_piece = -1;
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c - 1] == -1 || board[tap_r - 5][tap_c - 1] == -2) && board[tap_r - 6][tap_c - 2] == 0)
				{
					c3_tapped = 1;
					rllcu_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c + 1] == -1 || board[tap_r - 5][tap_c + 1] == -1) && board[tap_r - 6][tap_c + 2] == 0)
				{
					c3_tapped = 1;
					rlrcu_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
			}
			if (tap_r - 4 >= 0 && (board[tap_r - 3][tap_c + 3] == -1 || board[tap_r - 3][tap_c + 3] == -2) && board[tap_r - 4][tap_c + 4] == 0)
			{
				c2_tapped = 1;
				rrcu_valid = 1;
				if (turn == 1)
					prom_piece = 1;
				else
					prom_piece = -1;
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c + 3] == -1 || board[tap_r - 5][tap_c + 3] == -2) && board[tap_r - 6][tap_c + 2] == 0)
				{
					c3_tapped = 1;
					rrlcu_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && tap_c + 6 < 8 && (board[tap_r - 5][tap_c + 5] == -1 || board[tap_r - 5][tap_c + 5] == -2) && board[tap_r - 6][tap_c + 6] == 0)
				{
					c3_tapped = 1;
					rrrcu_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
			}
		}
		if (tap_r - 2 >= 0 && tap_r - 1 < 8 && tap_c >= 0 && tap_c + 2 < 8 && board[tap_r][tap_c] == -2 && (board[tap_r - 1][tap_c + 1] == 1 || board[tap_r - 1][tap_c + 1] == 2) && board[tap_r - 2][tap_c + 2] == 0)
		{
			c_tapped = 1;
			rcu_valid = 1;
			if (turn == 1)
				prom_piece = 1;
			else
				prom_piece = -1;
			if (tap_r - 4 >= 0 && tap_c + 4 < 8 && (board[tap_r - 3][tap_c + 1] == 1 || board[tap_r - 3][tap_c + 1] == 2) && board[tap_r - 4][tap_c] == 0)
			{
				c2_tapped = 1;
				rlcu_valid = 1;
				if (turn == 1)
					prom_piece = 1;
				else
					prom_piece = -1;
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c - 1] == 1 || board[tap_r - 5][tap_c - 1] == 2) && board[tap_r - 6][tap_c - 2] == 0)
				{
					c3_tapped = 1;
					rllcu_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c + 1] == 1 || board[tap_r - 5][tap_c + 1] == 1) && board[tap_r - 6][tap_c + 2] == 0)
				{
					c3_tapped = 1;
					rlrcu_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
			}
			if (tap_r - 4 >= 0 && (board[tap_r - 3][tap_c + 3] == 1 || board[tap_r - 3][tap_c + 3] == 2) && board[tap_r - 4][tap_c + 4] == 0)
			{
				c2_tapped = 1;
				rrcu_valid = 1;
				if (turn == 1)
					prom_piece = 1;
				else
					prom_piece = -1;
				if (tap_r - 6 >= 0 && (board[tap_r - 5][tap_c + 3] == 1 || board[tap_r - 5][tap_c + 3] == 2) && board[tap_r - 6][tap_c + 2] == 0)
				{
					c3_tapped = 1;
					rrlcu_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && tap_c + 6 < 8 && (board[tap_r - 5][tap_c + 5] == 1 || board[tap_r - 5][tap_c + 5] == 2) && board[tap_r - 6][tap_c + 6] == 0)
				{
					c3_tapped = 1;
					rrrcu_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
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
			if (turn == 1)
				prom_piece = 1;
			else
				prom_piece = -1;
		}
		if (tap_r >= 0 && tap_r + 1 < 8 && tap_c >= 0 && tap_c + 1 < 8 && (board[tap_r][tap_c] == 2 || board[tap_r][tap_c] == -2) && board[tap_r + 1][tap_c + 1] == 0)
		{
			tapped2 = 1;
			rd_valid = 1;
			if (turn == 1)
				prom_piece = 1;
			else
				prom_piece = -1;
		}
		if (tap_r >= 0 && tap_r + 2 < 8 && tap_c - 2 >= 0 && tap_c < 8 && board[tap_r][tap_c] == 2 && (board[tap_r + 1][tap_c - 1] == -1 || board[tap_r + 1][tap_c - 1] == -2) && board[tap_r + 2][tap_c - 2] == 0)
		{
			c_tapped2 = 1;
			lcd_valid = 1;
			if (turn == 1)
				prom_piece = 1;
			else
				prom_piece = -1;
			if (tap_r + 4 < 8 && tap_c - 4 >= 0 && (board[tap_r + 3][tap_c - 3] == -1 || board[tap_r + 3][tap_c - 3] == -2) && board[tap_r + 4][tap_c - 4] == 0)
			{
				c2_tapped2 = 1;
				llcd_valid = 1;
				if (turn == 1)
					prom_piece = 1;
				else
					prom_piece = -1;
				if (tap_r + 6 < 8 && tap_c - 6 >= 0 && (board[tap_r + 5][tap_c - 5] == -1 || board[tap_r + 5][tap_c - 5] == -2) && board[tap_r + 6][tap_c - 6] == 0) // TRIPLE CAPTURES//
				{
					c3_tapped2 = 1;
					lllcd_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c - 3] == -1 || board[tap_r + 5][tap_c - 3] == -2) && board[tap_r + 6][tap_c - 2] == 0)
				{
					c3_tapped2 = 1;
					llrcd_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
			}
			if (tap_r + 4 < 8 && (board[tap_r + 3][tap_c - 1] == -1 || board[tap_r + 3][tap_c - 1] == -2) && board[tap_r + 4][tap_c] == 0)
			{
				c2_tapped2 = 1;
				lrcd_valid = 1;
				if (turn == 1)
					prom_piece = 1;
				else
					prom_piece = -1;
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c - 1] == -1 || board[tap_r + 5][tap_c - 1] == -2) && board[tap_r + 6][tap_c - 2] == 0)
				{
					c3_tapped2 = 1;
					lrlcd_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c + 1] == -1 || board[tap_r + 5][tap_c + 1] == -2) && board[tap_r + 6][tap_c + 2] == 0)
				{
					c3_tapped2 = 1;
					lrrcd_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
			}
		}
		if (tap_r >= 0 && tap_r + 2 < 8 && tap_c - 2 >= 0 && tap_c < 8 && board[tap_r][tap_c] == -2 && (board[tap_r + 1][tap_c - 1] == 1 || board[tap_r + 1][tap_c - 1] == 2) && board[tap_r + 2][tap_c - 2] == 0)
		{
			c_tapped2 = 1;
			lcd_valid = 1;
			if (turn == 1)
				prom_piece = 1;
			else
				prom_piece = -1;
			if (tap_r + 4 < 8 && tap_c - 4 >= 0 && (board[tap_r + 3][tap_c - 3] == 1 || board[tap_r + 3][tap_c - 3] == 2) && board[tap_r + 4][tap_c - 4] == 0)
			{
				c2_tapped2 = 1;
				llcd_valid = 1;
				if (turn == 1)
					prom_piece = 1;
				else
					prom_piece = -1;
				if (tap_r + 6 < 8 && tap_c - 6 >= 0 && (board[tap_r + 5][tap_c - 5] == 1 || board[tap_r + 5][tap_c - 5] == 2) && board[tap_r + 6][tap_c - 6] == 0) // TRIPLE CAPTURES//
				{
					c3_tapped2 = 1;
					lllcd_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c - 3] == 1 || board[tap_r + 5][tap_c - 3] == 2) && board[tap_r + 6][tap_c - 2] == 0)
				{
					c3_tapped2 = 1;
					llrcd_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
			}
			if (tap_r + 4 < 8 && (board[tap_r + 3][tap_c - 1] == 1 || board[tap_r + 3][tap_c - 1] == 2) && board[tap_r + 4][tap_c] == 0)
			{
				c2_tapped2 = 1;
				lrcd_valid = 1;
				if (turn == 1)
					prom_piece = 1;
				else
					prom_piece = -1;
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c - 1] == 1 || board[tap_r + 5][tap_c - 1] == 2) && board[tap_r + 6][tap_c - 2] == 0)
				{
					c3_tapped2 = 1;
					lrlcd_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c + 1] == 1 || board[tap_r + 5][tap_c + 1] == 2) && board[tap_r + 6][tap_c + 2] == 0)
				{
					c3_tapped2 = 1;
					lrrcd_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
			}
		}
		if (tap_r >= 0 && tap_r + 2 < 8 && tap_c >= 0 && tap_c + 2 < 8 && board[tap_r][tap_c] == 2 && (board[tap_r + 1][tap_c + 1] == -1 || board[tap_r + 1][tap_c + 1] == -2) && board[tap_r + 2][tap_c + 2] == 0)
		{
			c_tapped2 = 1;
			rcd_valid = 1;
			if (turn == 1)
				prom_piece = 1;
			else
				prom_piece = -1;
			if (tap_r + 4 < 8 && tap_c + 4 < 8 && (board[tap_r + 3][tap_c + 1] == -1 || board[tap_r + 3][tap_c + 1] == -2) && board[tap_r + 4][tap_c] == 0)
			{
				c2_tapped2 = 1;
				rlcd_valid = 1;
				if (turn == 1)
					prom_piece = 1;
				else
					prom_piece = -1;
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c - 1] == -1 || board[tap_r + 5][tap_c - 1] == -2) && board[tap_r + 6][tap_c - 2] == 0)
				{
					c3_tapped2 = 1;
					rllcd_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c + 1] == -1 || board[tap_r + 5][tap_c + 1] == -2) && board[tap_r + 6][tap_c + 2] == 0)
				{
					c3_tapped2 = 1;
					rlrcd_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
			}
			if (tap_r + 4 < 8 && (board[tap_r + 3][tap_c + 3] == -1 || board[tap_r + 3][tap_c + 3] == -2) && board[tap_r + 4][tap_c + 4] == 0)
			{
				c2_tapped2 = 1;
				rrcd_valid = 1;
				if (turn == 1)
					prom_piece = 1;
				else
					prom_piece = -1;
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c + 3] == -1 || board[tap_r + 5][tap_c + 3] == -2) && board[tap_r + 6][tap_c + 2] == 0)
				{
					c3_tapped2 = 1;
					rrlcd_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && tap_c + 6 < 8 && (board[tap_r - 5][tap_c + 5] == -1 || board[tap_r - 5][tap_c + 5] == -2) && board[tap_r + 6][tap_c + 6] == 0)
				{
					c3_tapped2 = 1;
					rrrcd_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
			}
		}
		if (tap_r >= 0 && tap_r + 2 < 8 && tap_c >= 0 && tap_c + 2 < 8 && board[tap_r][tap_c] == -2 && (board[tap_r + 1][tap_c + 1] == 1 || board[tap_r + 1][tap_c + 1] == 2) && board[tap_r + 2][tap_c + 2] == 0)
		{
			c_tapped2 = 1;
			rcd_valid = 1;
			if (turn == 1)
				prom_piece = 1;
			else
				prom_piece = -1;
			if (tap_r + 4 < 8 && tap_c + 4 < 8 && (board[tap_r + 3][tap_c + 1] == 1 || board[tap_r + 3][tap_c + 1] == 2) && board[tap_r + 4][tap_c] == 0)
			{
				c2_tapped2 = 1;
				rlcd_valid = 1;
				if (turn == 1)
					prom_piece = 1;
				else
					prom_piece = -1;
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c - 1] == 1 || board[tap_r + 5][tap_c - 1] == 2) && board[tap_r + 6][tap_c - 2] == 0)
				{
					c3_tapped2 = 1;
					rllcd_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c + 1] == 1 || board[tap_r + 5][tap_c + 1] == 2) && board[tap_r + 6][tap_c + 2] == 0)
				{
					c3_tapped2 = 1;
					rlrcd_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
			}
			if (tap_r + 4 < 8 && (board[tap_r + 3][tap_c + 3] == 1 || board[tap_r + 3][tap_c + 3] == 2) && board[tap_r + 4][tap_c + 4] == 0)
			{
				c2_tapped2 = 1;
				rrcd_valid = 1;
				if (turn == 1)
					prom_piece = 1;
				else
					prom_piece = -1;
				if (tap_r + 6 < 8 && (board[tap_r + 5][tap_c + 3] == 1 || board[tap_r + 5][tap_c + 3] == 2) && board[tap_r + 6][tap_c + 2] == 0)
				{
					c3_tapped2 = 1;
					rrlcd_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
				if (tap_r - 6 >= 0 && tap_c + 6 < 8 && (board[tap_r - 5][tap_c + 5] == 1 || board[tap_r - 5][tap_c + 5] == 2) && board[tap_r + 6][tap_c + 6] == 0)
				{
					c3_tapped2 = 1;
					rrrcd_valid = 1;
					if (turn == 1)
						prom_piece = 1;
					else
						prom_piece = -1;
				}
			}
		}
	}
}
void reset_timer()
{
	hour = 0;
	minute = 0;
	sec = 0;
}

// update the sec += 1, and calculate the hour and min according to that
void update_timer_red()
{
	sec += 1;
	if (sec >= 60)
	{
		sec = 0;
		minute++;
	}
	if (minute >= 60)
	{
		minute = 0;
		hour++;
	}
}
void update_timer_black()
{
	sec1 += 1;
	if (sec1 >= 60)
	{
		sec1 = 0;
		minute1++;
	}
	if (minute1 >= 60)
	{
		minute1 = 0;
		hour1++;
	}
}

// draw the timer in the game screen
void draw_timer_red()
{
	ostringstream oss_h;
	oss_h << setw(2) << setfill('0') << hour;
	string formattedhour = oss_h.str();

	ostringstream oss_m;
	oss_m << setw(2) << setfill('0') << minute;
	string formattedminute = oss_m.str();

	ostringstream oss_s;
	oss_s << setw(2) << setfill('0') << sec;
	string formattedsec = oss_s.str();

	string temp = "RED                         TIME :      " + formattedhour + ":" + formattedminute + ":" + formattedsec;
	char *cstr = new char[temp.size() + 1];
	strcpy(cstr, temp.c_str());
	iText(844, 387, cstr, GLUT_BITMAP_HELVETICA_18);
}
void draw_timer_black()
{
	ostringstream oss_h;
	oss_h << setw(2) << setfill('0') << hour1;
	string formattedhour = oss_h.str();

	ostringstream oss_m;
	oss_m << setw(2) << setfill('0') << minute1;
	string formattedminute = oss_m.str();

	ostringstream oss_s;
	oss_s << setw(2) << setfill('0') << sec1;
	string formattedsec = oss_s.str();

	string temp = "BLACK                    TIME :      " + formattedhour + ":" + formattedminute + ":" + formattedsec;
	char *cstr = new char[temp.size() + 1];
	strcpy(cstr, temp.c_str());
	iText(844, 745, cstr, GLUT_BITMAP_HELVETICA_18);
}
void playsound()
{
	PlaySound("capture.wav", NULL, SND_FILENAME | SND_ASYNC);
}
int main()
{
	load_anim1();
	load_anim2();
	load_anim3();
	load_banim1();
	load_banim2();
	load_banim3();
	setup();
	iSetTimer(1000, update_timer_red);
	iSetTimer(1000, update_timer_black);
	iSetTimer(20, update_anim1);
	iSetTimer(20, update_anim2);
	iSetTimer(20, update_anim3);
	iSetTimer(25, update_banim1);
	iSetTimer(25, update_banim2);
	iSetTimer(25, update_banim3);
	PlaySound("background.wav", NULL, SND_LOOP | SND_ASYNC);
	iInitialize(1200, 800, "Checkers");
	iSetTimer(20, update_anim1);
	return 0;
}