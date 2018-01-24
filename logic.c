//all the logical parts of the game
#include <stdlib.h>
#include <stdio.h>

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


void inputfunc(int *table, int turn, int *xs, int *os){

	int input;
	int x;
	int y;

	while(1 == 1){
		printf("Place marker on: ");
		scanf("%i", &input);

		printf("input: %d\n", input);

		if (table[input - 1] == 0){
			table[input - 1] = turn;
			if (turn == 1){*xs += 1;}
			else *os += 1;
			break;
		}
	}
}
