#include<stdio.h>
#include<stdlib.h>
int PLAYER_1, PLAYER_2;
void Setup();
void GameEngine();
int Menu();
void Win();
void Loss();
void Draw();

int main()
{
    while(1)
    {
        //system("clear");
        PLAYER_1=Menu();
        GameEngine();
        printf("\nPress Any Key To Continue..... ");
        char c;
        scanf("%c", &c);
    }
    return 0;
}

int Menu()
{
    int choice;
    printf("\n1. Press 1 To Select Rock");
    printf("\n2. Press 2 To Select Paper");
    printf("\n3. Press 3 To Select Scissor");
    printf("\n0. Press 0 To Exit Game");

    printf("\n\nEnter Your Choice: " );
    scanf("%d", &choice);
    return choice;
}

/* Assigning Number to Choices
 * ROCK     = 1
 * PAPER    = 2
 * SCISSORS = 3
 */

void GameEngine()
{
    PLAYER_2=rand()%(3+1-1)+1;
    switch(PLAYER_1)
    {
        case 1: 
            if(PLAYER_2==1)
            {
                Draw();
                printf("\nPLAYER 1 = ROCK\n");
                printf("\nCOMPUTER = ROCK\n");
            }
            else if(PLAYER_2==2)
            {
                Loss();
                printf("\nPLAYER 1 = ROCK\n");
                printf("\nCOMPUTER = PAPER\n");
            }
            else
            {
                Win();
                printf("\nPLAYER 1 = ROCK\n");
                printf("\nCOMPUTER = SCISSOR\n");
            }
            break;
        case 2:
            if(PLAYER_2==1)
            {
                Win();
                printf("\nPLAYER 1 = PAPER\n");
                printf("\nCOMPUTER = ROCK\n");
            }
            else if(PLAYER_2==2)
            {
                Draw();
                printf("\nPLAYER 1 = PAPER\n");
                printf("\nCOMPUTER = PAPER\n");
            }
            else
            {
                Loss();
                printf("\nPLAYER 1 = PAPER\n");
                printf("\nCOMPUTER = SCISSOR\n");
            }
            break;
        case 3:
            if(PLAYER_2==1)
            {
                Loss();
                printf("\nPLAYER 1 = SCISSOR \n");
                printf("\nCOMPUTER = ROCK\n");
            }
            else if(PLAYER_2==2)
            {
                Win();
                printf("\nPLAYER 1 = SCISSOR\n");
                printf("\nCOMPUTER = PAPER\n");
            }
            else
            {
                Draw();
                printf("\nPLAYER 1 = SCISSOR\n");
                printf("\nCOMPUTER = SCISSOR\n");
            }
            break;
        case 0: 
                exit(0);
                break;
        default:
            printf("\nInvalid Choice. Try Again!!!");
    }
}

void Win()
{
    printf("\n**********************************\n");
    printf("            PLAYER 1 WINS");
    printf("\n**********************************\n");
}

void Loss()
{
    printf("\n**********************************\n");
    printf("            COMPUTER WINS");
    printf("\n**********************************\n");
}
void Draw()
{
    printf("\n**********************************\n");
    printf("            GAME DRAWN");
    printf("\n**********************************\n");
}
