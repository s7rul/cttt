//all the logical parts of the game
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

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

void place(int *table, int turn, int *xs, int *os){

	int input;

	while(1 == 1){
		printw("Place marker on: ");
		refresh();
		scanw("%i", &input);

		printw("input: %d\n", input);
		refresh();

		if (table[input - 1] == 0){
			table[input - 1] = turn;
			if (turn == 1){*xs += 1;}
			else *os += 1;
			break;
		}
	}

}

void take(int *table, int turn, int *xs, int *os){
	int input;

	while(1 == 1){
		printw("take marker from: ");
		refresh();
		scanw("%i", &input);

		printw("input: %d\n", input);
		refresh();

		if (table[input - 1] == turn){
			table[input - 1] = 0;
			if (turn == 1){*xs -= 1;}
			else *os -= 1;
			break;
		}
	}

}


void inputfunc(int *table, int turn, int *xs, int *os){

	printw("#x: %d #o: %d\n", *xs, *os);

	switch(turn){
		case(1):
			if (*xs == 3){take(table, turn, xs, os);}
			if (*xs < 3){place(table, turn, xs, os);}
			break;
		case(2):
			if (*os == 3){take(table, turn, xs, os);}
			if (*os < 3){place(table, turn, xs, os);}
			break;
	}
}
