//ai to play ttt 
#include <stdlib.h>
#include <stdio.h>

FILE logg;

int rnd(int max){
	int r;
	r = rand() % max;
	return r;
}

int check_for_win(int *table, int move){
	//mode 1 = check i human can win
	//mode 2 = check if ai can win
	//
	//#########
	//# 0 1 2 #
	//# 3 4 5 #
	//# 6 7 8 #
	//#########

	int ret = 9;

	if (table[0] == move && table[1] == move && table[2] == 0){ret = 2;}
	if (table[0] == move && table[2] == move && table[1] == 0){ret = 1;}
	if (table[1] == move && table[2] == move && table[0] == 0){ret = 0;}

	if (table[3] == move && table[4] == move && table[5] == 0){ret = 5;}
	if (table[3] == move && table[5] == move && table[4] == 0){ret = 4;}
	if (table[4] == move && table[5] == move && table[3] == 0){ret = 3;}

	if (table[6] == move && table[7] == move && table[8] == 0){ret = 8;}
	if (table[6] == move && table[8] == move && table[7] == 0){ret = 7;}
	if (table[7] == move && table[8] == move && table[6] == 0){ret = 6;}

	if (table[0] == move && table[3] == move && table[6] == 0){ret = 6;}
	if (table[0] == move && table[6] == move && table[3] == 0){ret = 3;}
	if (table[3] == move && table[6] == move && table[0] == 0){ret = 0;}

	if (table[1] == move && table[4] == move && table[7] == 0){ret = 7;}
	if (table[1] == move && table[7] == move && table[4] == 0){ret = 4;}
	if (table[4] == move && table[7] == move && table[1] == 0){ret = 1;}

	if (table[2] == move && table[5] == move && table[8] == 0){ret = 8;}
	if (table[2] == move && table[8] == move && table[5] == 0){ret = 5;}
	if (table[5] == move && table[8] == move && table[2] == 0){ret = 2;}

	if (table[0] == move && table[4] == move && table[8] == 0){ret = 8;}
	if (table[0] == move && table[8] == move && table[4] == 0){ret = 4;}
	if (table[4] == move && table[8] == move && table[0] == 0){ret = 0;}

	if (table[2] == move && table[4] == move && table[6] == 0){ret = 6;}
	if (table[2] == move && table[6] == move && table[4] == 0){ret = 4;}
	if (table[4] == move && table[6] == move && table[2] == 0){ret = 2;}

	return ret;
} 

void ai_move(int *table, int *os){
	int empty, move, full;
	empty = 0;
	full = 0;

	if (*os < 3){
		while(!empty){
			move = check_for_win(table, 1);
			if (move == 9){
				move = rnd(9);
			}
			if (table[move] == 0){empty = 1;}
		}
		table[move] = 2;
		*os += 1;
	}
	else {
		while(!full){
			move = rnd(9);
			if (table[move] == 2){full = 1;}
		}
		table[move] = 0;

		while(!empty){
			move = rnd(9);
			if (table[move] == 0){empty = 1;}
		}
		table[move] = 2;
	}

	return; 
}
