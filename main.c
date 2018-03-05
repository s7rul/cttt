//main file
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <time.h>

//functions in logic.c
void clean_table(int *table);
int test_win(int *table, int turn);
void inputfunc(int *table, int turn, int *xs, int *os, int *cpoint);

//functions in visual.c
void print_table(int *table, int hlight);
void win_message(int turn);
int menu();

//functions in ai.c
void ai_move(int *table, int *os);


int two_player_loop(){
	int *table = (int *) malloc(9 * sizeof(int));
	int *xs = (int *) malloc(sizeof(int));
	int *os = (int *) malloc(sizeof(int));
	int *cpoint = (int *) malloc(2 * sizeof(int));

	int win;
	int turn;

	clean_table(table);
	turn = 1;
	win = 0;
	*xs = 0;
	*os = 0;
	cpoint[0] = 1;
	cpoint[1] = 1;


	while(win == 0){
		clear();
		inputfunc(table, turn, xs, os, cpoint);
		win = test_win(table, turn);

		if (win == 1){
			print_table(table, 0);
			win_message(turn);
		}

		if (turn == 1){turn = 2;}
		else if (turn == 2){turn = 1;}
	}


	free(table);
	free(xs);
	free(os);
	free(cpoint);
}

int one_player_loop(){
	time_t t;
	srand((unsigned) t);
	clear();
	refresh();
	int startx, starty, height, width, lines, cols;

	int *table = (int *) malloc(9 * sizeof(int));
	int *xs = (int *) malloc(sizeof(int));
	int *os = (int *) malloc(sizeof(int));
	int *cpoint = (int *) malloc(2 * sizeof(int));

	int win;
	int turn;

	clean_table(table);
	turn = 1;
	win = 0;
	*xs = 0;
	*os = 0;
	cpoint[0] = 1;
	cpoint[1] = 1;


	while(win == 0){
		clear();
		if (turn == 1){inputfunc(table, turn, xs, os, cpoint);}
		else ai_move(table, os);
		win = test_win(table, turn);

		if (win == 1){
			print_table(table, 0);
			win_message(turn);
		}

		if (turn == 1){turn = 2;}
		else if (turn == 2){turn = 1;}
	}


	free(table);
	free(xs);
	free(os);
	free(cpoint);
}


int main(){
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	menu();
	endwin();
	return 0;
}
