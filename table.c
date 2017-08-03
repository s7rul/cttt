//this is the visual table part of the game
#include <stdio.h>

void clear_chartable(char * chartable[3][3][5]){

    int x;
    int y;
    int z;

    for (int x = 0; x < 3; x++){
        for (int y = 0; y < 3; y++){
            for (int z = 0; z < 5; z++){
                chartable[x][y][z] = "     ";
            }
        }
    }
    return;
}

void table_to_chartable(int **table, char * chartable[3][3][5]){
    int x;
    int y;
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

    for (x = 0; x < 3; x++){
        for (y = 0; y < 3; y++){
            if (table[x][y] == 1){
                for (n = 0; n < 5; n++){
                    chartable[x][y][n] = cx[n];
                }
            }
            if (table[x][y] == 2){
                for (n = 0; n < 5; n++){
                    chartable[x][y][n] = co[n];
                }
            }
        }
    }
    return;
}

void print_only(char * chartable[3][3][5]){
    printf("#########################\n");
    printf("#       #       #       #\n");
    printf("# %s # %s # %s #\n", chartable[0][0][0], chartable[1][0][0], chartable[2][0][0]);
    printf("# %s # %s # %s #\n", chartable[0][0][1], chartable[1][0][1], chartable[2][0][1]);
    printf("# %s # %s # %s #\n", chartable[0][0][2], chartable[1][0][2], chartable[2][0][2]);
    printf("# %s # %s # %s #\n", chartable[0][0][3], chartable[1][0][3], chartable[2][0][3]);
    printf("# %s # %s # %s #\n", chartable[0][0][4], chartable[1][0][4], chartable[2][0][4]);
    printf("#       #       #       #\n");
    printf("#########################\n");
    printf("#       #       #       #\n");
    printf("# %s # %s # %s #\n", chartable[0][1][0], chartable[1][1][0], chartable[2][1][0]);
    printf("# %s # %s # %s #\n", chartable[0][1][1], chartable[1][1][1], chartable[2][1][1]);
    printf("# %s # %s # %s #\n", chartable[0][1][2], chartable[1][1][2], chartable[2][1][2]);
    printf("# %s # %s # %s #\n", chartable[0][1][3], chartable[1][1][3], chartable[2][1][3]);
    printf("# %s # %s # %s #\n", chartable[0][1][4], chartable[1][1][4], chartable[2][1][4]);
    printf("#       #       #       #\n");
    printf("#########################\n");
    printf("#       #       #       #\n");
    printf("# %s # %s # %s #\n", chartable[0][2][0], chartable[1][2][0], chartable[2][2][0]);
    printf("# %s # %s # %s #\n", chartable[0][2][1], chartable[1][2][1], chartable[2][2][1]);
    printf("# %s # %s # %s #\n", chartable[0][2][2], chartable[1][2][2], chartable[2][2][2]);
    printf("# %s # %s # %s #\n", chartable[0][2][3], chartable[1][2][3], chartable[2][2][3]);
    printf("# %s # %s # %s #\n", chartable[0][2][4], chartable[1][2][4], chartable[2][2][4]);
    printf("#       #       #       #\n");
    printf("#########################\n");
    return;
}

void print_table(int **table){
    char * chartable[3][3][5];
    clear_chartable(chartable);
    table_to_chartable(table, chartable);
    print_only(chartable);
    return;
}

void print_turn(int turn){
    switch(turn){
        case(1):
            printf("X's turn\n");
            break;
        case(2):
            printf("O's turn\n");
            break;
    }
    return;
}
