//main file
#include <stdlib.h>
#include <stdio.h>

//functions in logic.c
void clean_table(int **table);
int test_win(int **table, int turn);
void inputfunc(int **table, int turn);

//functions in table.c
void print_table(int **table);
void print_turn(int turn);


int two_player_loop(){
    int **table = (int **) malloc(3 * sizeof(int));
    table[0] = (int *) malloc(3 * sizeof(int));
    table[1] = (int *) malloc(3 * sizeof(int));
    table[2] = (int *) malloc(3 * sizeof(int));

    int win;
    int turn;

    clean_table(table);
    turn = 1;
    win = 0;


    while(win == 0){
        print_turn(turn);
        printf("interger turn:%d\n", turn);
        print_table(table);
        inputfunc(table, turn);
        win = test_win(table, turn);

        if (turn == 1){turn = 2;}
        else if (turn == 2){turn = 1;}
    }


    free(table[0]);
    free(table[1]);
    free(table[2]);
    free(table);
}

int one_player_loop(){
    printf("###################\n");
    printf("#      Under      #\n");
    printf("#  construction!  #\n");
    printf("###################\n");
}

int menu(){
    int * shoice = (int *) malloc(sizeof(int));
    
    printf("###################\n");
    printf("# 1 - two player  #\n");
    printf("# 2 - one player  #\n");
    printf("# 3 - quit        #\n");
    printf("###################\n");
    printf("Your shoice: ");
    scanf("%d", shoice);

    switch(*shoice){
        case 1:
            free(shoice);
            two_player_loop();
            break;
        case 2:
            free(shoice);
            one_player_loop();
            break;
        case 3:
            free(shoice);
            return 0;
            break;
    }

    menu();
}

int main(){
    printf("Hello and wealcome to tic tac toe writhen in c.\n");
    menu();
}
