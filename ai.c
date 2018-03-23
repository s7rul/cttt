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

int *dont_remove(int *table){
	int *ret = malloc(2 * sizeof(int));

	//#########
	//# 0 1 2 #
	//# 3 4 5 #
	//# 6 7 8 #
	//#########

	ret[0] = 9;
	ret[1] = 9;

	if (check_for_win(table, 2) == 2 && table[2] == 0){ret[0] = 0; ret[1] = 1;}
	if (check_for_win(table, 2) == 1 && table[1] == 0){ret[0] = 0; ret[1] = 2;}
	if (check_for_win(table, 2) == 0 && table[0] == 0){ret[0] = 1; ret[1] = 2;}

	if (check_for_win(table, 2) == 5 && table[5] == 0){ret[0] = 3; ret[1] = 4;}
	if (check_for_win(table, 2) == 4 && table[4] == 0){ret[0] = 3; ret[1] = 5;}
	if (check_for_win(table, 2) == 3 && table[3] == 0){ret[0] = 4; ret[1] = 5;}

	if (check_for_win(table, 2) == 8 && table[8] == 0){ret[0] = 6; ret[1] = 7;}
	if (check_for_win(table, 2) == 7 && table[7] == 0){ret[0] = 6; ret[1] = 8;}
	if (check_for_win(table, 2) == 6 && table[6] == 0){ret[0] = 7; ret[1] = 8;}

	if (check_for_win(table, 2) == 6 && table[6] == 0){ret[0] = 0; ret[1] = 3;}
	if (check_for_win(table, 2) == 3 && table[3] == 0){ret[0] = 0; ret[1] = 6;}
	if (check_for_win(table, 2) == 0 && table[0] == 0){ret[0] = 3; ret[1] = 6;}

	if (check_for_win(table, 2) == 7 && table[7] == 0){ret[0] = 1; ret[1] = 4;}
	if (check_for_win(table, 2) == 4 && table[4] == 0){ret[0] = 1; ret[1] = 7;}
	if (check_for_win(table, 2) == 1 && table[1] == 0){ret[0] = 4; ret[1] = 7;}

	if (check_for_win(table, 2) == 8 && table[8] == 0){ret[0] = 2; ret[1] = 5;}
	if (check_for_win(table, 2) == 5 && table[5] == 0){ret[0] = 2; ret[1] = 8;}
	if (check_for_win(table, 2) == 2 && table[2] == 0){ret[0] = 5; ret[1] = 8;}

	if (check_for_win(table, 2) == 8 && table[8] == 0){ret[0] = 0; ret[1] = 4;}
	if (check_for_win(table, 2) == 4 && table[4] == 0){ret[0] = 0; ret[1] = 8;}
	if (check_for_win(table, 2) == 0 && table[0] == 0){ret[0] = 4; ret[1] = 8;}

	if (check_for_win(table, 2) == 6 && table[6] == 0){ret[0] = 2; ret[1] = 4;}
	if (check_for_win(table, 2) == 4 && table[4] == 0){ret[0] = 2; ret[1] = 6;}
	if (check_for_win(table, 2) == 2 && table[2] == 0){ret[0] = 4; ret[1] = 6;}

	return ret;
}

void ai_below_3_move(int *table){
	int empty = 0;
	int v_rnd = 1;
	int move;

	while(!empty){
		if (check_for_win(table, 1) != 9){
			move = check_for_win(table, 1);
			v_rnd = 0;
		}
		if (check_for_win(table, 2) != 9){
			move = check_for_win(table, 2);
			v_rnd = 0;
		}
		if (v_rnd){
			move = rnd(9);
		}
		if (table[move] == 0){empty = 1;}
	}
	table[move] = 2;
}

void ai_over_3_move(int *table){
	int full = 0;
	int move;
	int *dremove;

	dremove = dont_remove(table);

	while(!full){
		move = rnd(9);
		if (dremove[0] == move){continue;}
		if (dremove[1] == move){continue;}
		if (table[move] == 2){full = 1;}
	}
	table[move] = 0;

	ai_below_3_move(table);

	free(dremove);
}

void ai_move(int *table, int *os){
	if (*os < 3){
		ai_below_3_move(table);
		*os += 1;
	}
	else {
		ai_over_3_move(table);
	}

	return; 
}
