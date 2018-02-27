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

	move(25, 0);
	printw("#######################\n");
	printw("#                     #\n");
	printw("#       %c Won!        #\n", winner);
	printw("#                     #\n");
	printw("#######################\n");
	refresh();
	getch();
}

int vmenu(){
	clear();
	refresh();
	WINDOW *menu_win;
	int height, width, starty, startx, lines, cols;
	int input;
	int hlight = 0;
	char *smenu[3];
	smenu[0] = "# 1 - two player  #";
	smenu[1] = "# 2 - one player  #";
	smenu[2] = "# 3 - quit        #";

	height = 5;
	width = 19;
	getmaxyx(stdscr, lines, cols);
	starty = (lines - height) / 2;
	startx = (cols - width) / 2;

	menu_win = newwin(height, width, starty, startx);
	keypad(menu_win, TRUE);

	while(1){
		wmove(menu_win, 0, 0);
		wprintw(menu_win, "###################");

		for (int l = 0; l < 3; l++){
			if (hlight == l){
				wattron(menu_win, A_STANDOUT);
				wprintw(menu_win, "%s", smenu[l]);
				wattroff(menu_win, A_STANDOUT);
			}
			else wprintw(menu_win,"%s", smenu[l]);
		}

		wprintw(menu_win, "###################");
		wrefresh(menu_win);

		input = wgetch(menu_win);

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
				return hlight + 1;
				break;
		}

	}

	delwin(menu_win);
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

void print_turn(int turn){
	switch(turn){
		case(1):
			mvprintw(25, 0, "X's turn\n");
			break;
		case(2):
			mvprintw(25, 0, "O's turn\n");
			break;
	}
	return;
}

void print_only(char * chartable[9][5], int hlight){
	move(0, 0);
	printw("#########################\n");
	printw("#       #       #       #\n");
	printw("#       #       #       #\n");
	printw("#       #       #       #\n");
	printw("#       #       #       #\n");
	printw("#       #       #       #\n");
	printw("#       #       #       #\n");
	printw("#       #       #       #\n");
	printw("#########################\n");
	printw("#       #       #       #\n");
	printw("#       #       #       #\n");
	printw("#       #       #       #\n");
	printw("#       #       #       #\n");
	printw("#       #       #       #\n");
	printw("#       #       #       #\n");
	printw("#       #       #       #\n");
	printw("#########################\n");
	printw("#       #       #       #\n");
	printw("#       #       #       #\n");
	printw("#       #       #       #\n");
	printw("#       #       #       #\n");
	printw("#       #       #       #\n");
	printw("#       #       #       #\n");
	printw("#       #       #       #\n");
	printw("#########################\n");

	//pos 1
	if (hlight == 1){
		attron(A_STANDOUT);
	}
	mvprintw(2, 1," %s ", chartable[0][0]);
	mvprintw(3, 1," %s ", chartable[0][1]);
	mvprintw(4, 1," %s ", chartable[0][2]);
	mvprintw(5, 1," %s ", chartable[0][3]);
	mvprintw(6, 1," %s ", chartable[0][4]);
	attroff(A_STANDOUT);

	//pos 2
	if (hlight == 2){
		attron(A_STANDOUT);
	}
	mvprintw(2, 9," %s ", chartable[1][0]);
	mvprintw(3, 9," %s ", chartable[1][1]);
	mvprintw(4, 9," %s ", chartable[1][2]);
	mvprintw(5, 9," %s ", chartable[1][3]);
	mvprintw(6, 9," %s ", chartable[1][4]);
	attroff(A_STANDOUT);

	//pos 3
	if (hlight == 3){
		attron(A_STANDOUT);
	}
	mvprintw(2, 17," %s ", chartable[2][0]);
	mvprintw(3, 17," %s ", chartable[2][1]);
	mvprintw(4, 17," %s ", chartable[2][2]);
	mvprintw(5, 17," %s ", chartable[2][3]);
	mvprintw(6, 17," %s ", chartable[2][4]);
	attroff(A_STANDOUT);
	
	//pos 4
	if (hlight == 4){
		attron(A_STANDOUT);
	}
	mvprintw(10, 1," %s ", chartable[3][0]);
	mvprintw(11, 1," %s ", chartable[3][1]);
	mvprintw(12, 1," %s ", chartable[3][2]);
	mvprintw(13, 1," %s ", chartable[3][3]);
	mvprintw(14, 1," %s ", chartable[3][4]);
	attroff(A_STANDOUT);

	//pos 5
	if (hlight == 5){
		attron(A_STANDOUT);
	}
	mvprintw(10, 9," %s ", chartable[4][0]);
	mvprintw(11, 9," %s ", chartable[4][1]);
	mvprintw(12, 9," %s ", chartable[4][2]);
	mvprintw(13, 9," %s ", chartable[4][3]);
	mvprintw(14, 9," %s ", chartable[4][4]);
	attroff(A_STANDOUT);

	//pos 6
	if (hlight == 6){
		attron(A_STANDOUT);
	}
	mvprintw(10, 17," %s ", chartable[5][0]);
	mvprintw(11, 17," %s ", chartable[5][1]);
	mvprintw(12, 17," %s ", chartable[5][2]);
	mvprintw(13, 17," %s ", chartable[5][3]);
	mvprintw(14, 17," %s ", chartable[5][4]);
	attroff(A_STANDOUT);

	//pos 7
	if (hlight == 7){
		attron(A_STANDOUT);
	}
	mvprintw(18, 1," %s ", chartable[6][0]);
	mvprintw(19, 1," %s ", chartable[6][1]);
	mvprintw(20, 1," %s ", chartable[6][2]);
	mvprintw(21, 1," %s ", chartable[6][3]);
	mvprintw(22, 1," %s ", chartable[6][4]);
	attroff(A_STANDOUT);

	//pos 8
	if (hlight == 8){
		attron(A_STANDOUT);
	}
	mvprintw(18, 9," %s ", chartable[7][0]);
	mvprintw(19, 9," %s ", chartable[7][1]);
	mvprintw(20, 9," %s ", chartable[7][2]);
	mvprintw(21, 9," %s ", chartable[7][3]);
	mvprintw(22, 9," %s ", chartable[7][4]);
	attroff(A_STANDOUT);

	//pos 9
	if (hlight == 9){
		attron(A_STANDOUT);
	}
	mvprintw(18, 17," %s ", chartable[8][0]);
	mvprintw(19, 17," %s ", chartable[8][1]);
	mvprintw(20, 17," %s ", chartable[8][2]);
	mvprintw(21, 17," %s ", chartable[8][3]);
	mvprintw(22, 17," %s ", chartable[8][4]);
	attroff(A_STANDOUT);

	return;
}

void print_table(int *table, int hlight){
	char * chartable[9][5];
	clear_chartable(chartable);
	table_to_chartable(table, chartable);
	print_only(chartable, hlight);

	return;
}
