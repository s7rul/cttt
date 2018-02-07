//main file
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

//functions in logic.c
void clean_table(int *table);
int test_win(int *table, int turn);
void inputfunc(int *table, int turn, int *xs, int *os);

//functions in visual.c
void print_table(int *table);
void print_turn(int turn);
void win_message(int turn);
int menu();


int two_player_loop(){

	int *table = (int *) malloc(9 * sizeof(int));
	int *xs = (int *) malloc(sizeof(int));
	int *os = (int *) malloc(sizeof(int));

	int win;
	int turn;

	clean_table(table);
	turn = 1;
	win = 0;
	*xs = 0;
	*os = 0;


	while(win == 0){
		clear();
		print_turn(turn);
		print_table(table);
		inputfunc(table, turn, xs, os);
		win = test_win(table, turn);

		if (win == 1){print_table(table);}
		if (win == 1){win_message(turn);}

		if (turn == 1){turn = 2;}
		else if (turn == 2){turn = 1;}
	}


	free(table);
	free(xs);
	free(os);
}

int one_player_loop(){
	move(0, 0);
	clear();
	printw("###################\n");
	printw("#      Under      #\n");
	printw("#  construction!  #\n");
	printw("###################\n");
	refresh();
	getch();
}


int main(){
	initscr();
	menu();
	endwin();
	return 0;
}
