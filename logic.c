//all the logical parts of the game
#include <stdlib.h>
#include <stdio.h>

void clean_table(int **table){
    int x;
    int y;

    for (x = 0; x < 3; x++){
        for (y = 0; y < 3; y++){
            table[x][y] = 0;
        }
    }
}

int test_win(int **table, int turn){

    for (int x; x < 3; x++){
        if (table[x][0] == turn && table[x][1] == turn && table[x][2] == turn){
            return 1;
        }
    }

    for (int y; y < 3; y++){
        if (table[0][y] == turn && table[1][y] == turn && table[2][y] == turn){
            return 1;
        }
    }

    if (table[0][0] == turn && table[1][1] == turn && table[2][2] == turn){
        return 1;
    }

    if (table[2][0] == turn && table[1][1] == turn && table[0][2] == turn){
        return 1;
    }

    return 0;
}

int chartoint(char input){
    switch (input){
        case('1'):
            return 0;
        case('2'):
            return 1;
        case('3'):
            return 2;

        case('a'):
            return 0;
        case('b'):
            return 1;
        case('c'):
            return 2;
    }
}

void inputfunc(int **table, int turn){

    char * input = (char *) malloc(sizeof(input));
    int x;
    int y;

    while(1 == 1){
        printf("Place marker on: ");
        scanf("%s", input);

        x = chartoint(input[0]);
        y = chartoint(input[1]);

        printf("x:%d y:%d\n", x, y);

        if (table[x][y] == 0){
            table[x][y] = turn;
            break;
        }
    }

    free(input);
}
