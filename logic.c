//all the logical parts of the game
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

//funktion declaree in visual.c
void print_table(int *table, int hlight);

void clean_table(int *table){
	int n;

	for (n = 0; n < 9; n++){
		table[n] = 0;
	}
}

int test_win(int table[9], int turn){

	if (table[0] == turn && table[1] == turn && table[2] == turn){return 1;}
	if (table[3] == turn && table[4] == turn && table[5] == turn){return 1;}
	if (table[6] == turn && table[7] == turn && table[8] == turn){return 1;}
	
	if (table[0] == turn && table[3] == turn && table[6] == turn){return 1;}
	if (table[1] == turn && table[4] == turn && table[7] == turn){return 1;}
	if (table[2] == turn && table[5] == turn && table[8] == turn){return 1;}

	if (table[0] == turn && table[4] == turn && table[8] == turn){return 1;}
	if (table[2] == turn && table[4] == turn && table[6] == turn){return 1;}

	return 0;
}

int xy_to_hlight(int x, int y){

	if (y == 0 && x == 0){return 1;}
	if (y == 0 && x == 1){return 2;}
	if (y == 0 && x == 2){return 3;}

	if (y == 1 && x == 0){return 4;}
	if (y == 1 && x == 1){return 5;}
	if (y == 1 && x == 2){return 6;}

	if (y == 2 && x == 0){return 7;}
	if (y == 2 && x == 1){return 8;}
	if (y == 2 && x == 2){return 9;}

	return 0;
}

int vinput(int *table, int *cpoint){
	int x = cpoint[0];
	int y = cpoint[1];
	int i;

	while(1){
		print_table(table, xy_to_hlight(x, y));
		i = getch();
		mvprintw(0, 0,"%d",i);

		switch(i){
			case KEY_UP:
				if (y == 0){
					break;
				}
				else y--;
				break;
			case KEY_DOWN:
				if (y == 2){
					break;
				}
				else y++;
				break;
			case KEY_LEFT:
				if (x == 0){
					break;
				}
				else x--;
				break;
			case KEY_RIGHT:
				if (x == 2){
					break;
				}
				else x++;
				break;
			case 10:
				cpoint[0] = x;
				cpoint[1] = y;
				return xy_to_hlight(x, y);
				break;
		}
	}
}

void place(int *table, int turn, int *xs, int *os, int *cpoint){

	int input;

	while(1 == 1){
		input = vinput(table, cpoint);

		if (table[input - 1] == 0){
			table[input - 1] = turn;
			if (turn == 1){*xs += 1;}
			else *os += 1;
			break;
		}
	}

}

void take(int *table, int turn, int *xs, int *os, int *cpoint){
	int input;

	while(1 == 1){
		input = vinput(table, cpoint);

		if (table[input - 1] == turn){
			table[input - 1] = 0;
			if (turn == 1){*xs -= 1;}
			else *os -= 1;
			break;
		}
	}

}


void inputfunc(int *table, int turn, int *xs, int *os, int *cpoint){

	printw("#x: %d #o: %d\n", *xs, *os);

	switch(turn){
		case(1):
			if (*xs == 3){take(table, turn, xs, os, cpoint);}
			if (*xs < 3){place(table, turn, xs, os, cpoint);}
			break;
		case(2):
			if (*os == 3){take(table, turn, xs, os, cpoint);}
			if (*os < 3){place(table, turn, xs, os, cpoint);}
			break;
	}
}
