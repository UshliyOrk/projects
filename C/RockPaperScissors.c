#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <time.h>

//1-rock 2-paper 3-scissors
int game (int player);

int main(void)
{
    printf("\033[91m Rock \033[92mPaper \033[94mScissors\n \033[0m");
    while (1)
    {
        int move;
        printf("(1=Rock 2=Paper 3=Scissors -1=exit) Make your move --> ");
        scanf("%d", &move);
        if(move == -1) break;
        int round = game(move);
        if(round == -1) printf("Draw. \n");
        else if (round) printf("You Win!! \n");
        else printf("You Lose :( \n");
    }
    printf("\033[93mThanks for playing !\n \033[0m");
    printf("Press ENTER to exit ... ");
    getchar();
    getchar();
    
    return 0;
}

int game (int player)
{
    player -= 1;
    srand(time(NULL));
    int bot = rand()%3;
    if (bot == 0) printf("computer : Rock\n");
    else if (bot == 1) printf("computer : Paper\n");
    else printf("computer : Scissors\n");

    if (bot == player) return -1;
    else if (bot == 0 and player == 1) return 1;
    else if (bot == 0 and player == 2) return 0;
    else if (bot == 1 and player == 0) return 1;
    else if (bot == 1 and player == 2) return 0;
    else if (bot == 2 and player == 1) return 0;
    else if (bot == 2 and player == 0) return 1;
    else{
        printf("invalid move\n");
        exit(-1);
    }
}