//this is the visual table part of the game
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

//funktions in main.c
int one_player_loop();
int two_player_loop();

void win_message(int turn){
	char winner;

	if (turn == 1){winner = 'x';}
	if (turn == 2){winner = 'o';}

	printw("#######################\n");
	printw("#                     #\n");
	printw("#       %c Won!        #\n", winner);
	printw("#                     #\n");
	printw("#######################\n");
	getch();
	refresh();
}

int vmenu(){
	int input;
	int hlight = 0;
	char *smenu[3];
	smenu[0] = "# 1 - two player  #\n";
	smenu[1] = "# 2 - one player  #\n";
	smenu[2] = "# 3 - quit        #\n";


	while(1){
		cbreak();
		noecho();
		keypad(stdscr, TRUE);
		clear();
		move(0, 0);
		printw("###################\n");

		for (int l = 0; l < 3; l++){
			if (hlight == l){
				attron(A_STANDOUT);
				printw("%s", smenu[l]);
				attroff(A_STANDOUT);
			}
			else printw("%s", smenu[l]);
		}

		move(4, 0);
		printw("###################\n");
		refresh();

		input = getch();

		switch(input){
			case KEY_UP:
				if (hlight == 0){
					break;
				}
				else hlight--;
				break;
			case KEY_DOWN:
				if (hlight == 2){
					break;
				}
				else hlight++;
				break;
			case 10:
				keypad(stdscr, FALSE);
				echo();
				nocbreak();
				return hlight + 1;
				break;
		}

	}
}

int menu(){

	int shoice;

	int end = 0;
    
	while(end != 1){
		shoice = vmenu();
		switch(shoice){
			case 1:
				two_player_loop();
				break;
			case 2:
				one_player_loop();
				break;
			case 3:
				return 0;
				break;
		}
	}
}

void clear_chartable(char * chartable[9][5]){

	int x;
	int z;

	for (int x = 0; x < 9; x++){
		for (int z = 0; z < 5; z++){
			chartable[x][z] = "     ";
		}
	}

	chartable[0][2] = "  1  ";
	chartable[1][2] = "  2  ";
	chartable[2][2] = "  3  ";
	chartable[3][2] = "  4  ";
	chartable[4][2] = "  5  ";
	chartable[5][2] = "  6  ";
	chartable[6][2] = "  7  ";
	chartable[7][2] = "  8  ";
	chartable[8][2] = "  9  ";

	return;
}

void table_to_chartable(int *table, char * chartable[9][5]){
	int x;
	int z;
	int n;

	char * cx[5];
	char * co[5];

	cx[0] = "X   X";
	cx[1] = " X X ";
	cx[2] = "  X  ";
	cx[3] = " X X ";
	cx[4] = "X   X";

	co[0] = " OOO ";
	co[1] = "O   O";
	co[2] = "O   O";
	co[3] = "O   O";
	co[4] = " OOO ";

	for (x = 0; x < 9; x++){
		if (table[x] == 1){
			for (n = 0; n < 5; n++){
				chartable[x][n] = cx[n];
			}
		}
		if (table[x] == 2){
			for (n = 0; n < 5; n++){
				chartable[x][n] = co[n];
			}
		}
	}
	return;
}

void print_only(char * chartable[9][5]){
	move(0, 0);
	printw("#########################\n");
	printw("#       #       #       #\n");
	printw("# %s # %s # %s #\n", chartable[0][0], chartable[1][0], chartable[2][0]);
	printw("# %s # %s # %s #\n", chartable[0][1], chartable[1][1], chartable[2][1]);
	printw("# %s # %s # %s #\n", chartable[0][2], chartable[1][2], chartable[2][2]);
	printw("# %s # %s # %s #\n", chartable[0][3], chartable[1][3], chartable[2][3]);
	printw("# %s # %s # %s #\n", chartable[0][4], chartable[1][4], chartable[2][4]);
	printw("#       #       #       #\n");
	printw("#########################\n");
	printw("#       #       #       #\n");
	printw("# %s # %s # %s #\n", chartable[3][0], chartable[4][0], chartable[5][0]);
	printw("# %s # %s # %s #\n", chartable[3][1], chartable[4][1], chartable[5][1]);
	printw("# %s # %s # %s #\n", chartable[3][2], chartable[4][2], chartable[5][2]);
	printw("# %s # %s # %s #\n", chartable[3][3], chartable[4][3], chartable[5][3]);
	printw("# %s # %s # %s #\n", chartable[3][4], chartable[4][4], chartable[5][4]);
	printw("#       #       #       #\n");
	printw("#########################\n");
	printw("#       #       #       #\n");
	printw("# %s # %s # %s #\n", chartable[6][0], chartable[7][0], chartable[8][0]);
	printw("# %s # %s # %s #\n", chartable[6][1], chartable[7][1], chartable[8][1]);
	printw("# %s # %s # %s #\n", chartable[6][2], chartable[7][2], chartable[8][2]);
	printw("# %s # %s # %s #\n", chartable[6][3], chartable[7][3], chartable[8][3]);
	printw("# %s # %s # %s #\n", chartable[6][4], chartable[7][4], chartable[8][4]);
	printw("#       #       #       #\n");
	printw("#########################\n");
	refresh();
	return;
}

void print_table(int *table){
	char * chartable[9][5];
	clear_chartable(chartable);
	table_to_chartable(table, chartable);
	print_only(chartable);
	return;
}

void print_turn(int turn){
	switch(turn){
		case(1):
			printw("X's turn\n");
			break;
		case(2):
			printw("O's turn\n");
			break;
	}
	return;
}
