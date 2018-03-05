//ai to play ttt 
#include <stdlib.h>

int rnd(int max){
	int r;
	r = rand() % max;
	return r;
}

void ai_move(int *table, int *os){
	int empty, move, full;
	empty = 0;
	full = 0;

	if (*os < 3){
		while(!empty){
			move = rnd(9);
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
