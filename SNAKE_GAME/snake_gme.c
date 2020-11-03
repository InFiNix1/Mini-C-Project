#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>


int width=38; //setting up dimensions for frame
int height=24;

int GameOver;

int X, Y, f_X, f_Y, score, art, direction;

void initialize() //initialize function
{

art=5;
GameOver=0;

//snake head location always at center
X=width/2;
Y=height/2;


//fruit location
srand(time(0));
f_X=rand()%(width-1+1 - 1) + 1;
f_Y =rand()%(height-1+1 - 1) + 1;

score=0;
}

void draw() //draw function
{
    system("cls");
    int ch;
    FILE* art;
    art=fopen("C:\\Users\\sauro\\OneDrive\\Desktop\\SNAKE_GAME\\snake_art2.txt", "r");
    if(art==NULL)
        exit(0);
    while((ch=fgetc(art))!=EOF)
          {
              printf("%c", ch);
          }
    printf("\n");

    int i, j;

    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            if(i==0 || j==width-1 || j==0 || i==height-1)
            {
                printf("#");
            }
            else
            {
                if(i==Y && j==X)
                {
                    printf("O");
                }
                else if(i==f_Y && j== f_X)
                {
                    printf("@");
                }
                else{
                        printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("\n\t\tSCORE : %d", score);
}

void input()
{
    if(kbhit())
    {
        switch(getch())
        {
        case 'w': //wasd 8246
            direction=8;
            break;
        case 's':
            direction=2;
            break;
        case 'a':
            direction=4;
            break;
        case 'd':
            direction=6;
            break;
        case 'x':
            GameOver=1;
            break;
        }
    }
}

void MakeLogic()
{
    switch(direction)
    {
    case 2:
        Y++;
        break;
    case 4:
        X--;
        break;
    case 6:
        X++;
        break;
    case 8:
        Y--;
        break;
    default:
        break;
    }

    if(X<=0 || X>=width-1 || Y<=0 || Y>=height-1)
        GameOver=1;
    if(X==f_X && Y == f_Y)
    {
        srand(time(0));
        f_X=rand()%(width-1 - 1) + 1;
        f_Y =rand()%(height-1 - 1) + 1;
        score+=10;
    }

}

int main()
{
    int ch;
    initialize();

    while(!GameOver)
    {
        draw();
        input();
        MakeLogic();
        Sleep(0.06);
    }
    system("cls");

    FILE *fp;
    fp=fopen("C:\\Users\\sauro\\OneDrive\\Desktop\\SNAKE_GAME\\game_over.txt", "r");
    while((ch=fgetc(fp))!=EOF)
          {
              printf("%c", ch);
          }
    printf("\n\t\t\tSCORE: %d", score);
    getch();
    return 0;
}
