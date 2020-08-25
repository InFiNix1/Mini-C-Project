#include<stdio.h>
#include<stdlib.h>

char grid[9]={'1', '2', '3',
    '4', '5', '6',
    '7', '8', '9'};

int set=0; //Alternates Between Player 1 & 2
int end=1;
int count=0;
int reset=1;
void Display()
{
    printf("\n\t\t\t\tTIC-TAC-TOE");
    printf("\n\t\t\t\t   GAME");

    printf("\n\n\t\t\t\t|---|---|---|");
    printf("\n\t\t\t\t| %c | %c | %c |", grid[0], grid[1], grid[2]);
    printf("\n\t\t\t\t|---|---|---|");
    printf("\n\t\t\t\t| %c | %c | %c |", grid[3], grid[4], grid[5]);
    printf("\n\t\t\t\t|---|---|---|");
    printf("\n\t\t\t\t| %c | %c | %c |", grid[6], grid[7], grid[8]);
    printf("\n\t\t\t\t|---|---|---|");
    printf("\n");
}
void PlayerModel()
{
    printf("\n\nPLAYER 1 = \'X\'");
    printf("\nPLAYER 2 = \'O\'\n");
    printf("\nNOTE: PLAYER 1 ALWAYS STARTS THE GAME\n");
}

void GetInput()
{
    int pos;
    printf("\nSELECT LOCATION: ");
    fflush(stdin);
    scanf("%d", &pos);
    if(pos < 1 || pos > 10)
    {
        printf("\nINVALID LOCATION\n");
        printf("\nTRY AGAIN");
    }
    else
    {
        if(set==0)
        {
            grid[pos-1]='X';
            set=1;
            count++;
        }
        else
        {
            grid[pos-1]='O';
            set=0;
            count++;
        }
    }
}

int GameEngine()
{
    if((grid[0] == 'X' && grid [1]== 'X' && grid[2]== 'X') ||
            (grid[0] == 'X' && grid [3]== 'X' && grid[6]== 'X') ||
            (grid[0] == 'X' && grid [4]== 'X' && grid[8]== 'X') ||
            (grid[1] == 'X' && grid [4]== 'X' && grid[7]== 'X') ||
            (grid[1] == 'X' && grid [4]== 'X' && grid[7]== 'X') ||
            (grid[2] == 'X' && grid [5]== 'X' && grid[8]== 'X') ||
            (grid[2] == 'X' && grid [5]== 'X' && grid[8]== 'X') ||
            (grid[2] == 'X' && grid [4]== 'X' && grid[6]== 'X') ||
            (grid[3] == 'X' && grid [4]== 'X' && grid[5]== 'X') ||
            (grid[6] == 'X' && grid [7]== 'X' && grid[8]== 'X'))
    {
        end=0;
        return 1;
    }
    else if((grid[0] == 'O' && grid [1]== 'O' && grid[2]== 'O') ||
            (grid[0] == 'O' && grid [3]== 'O' && grid[6]== 'O') ||
            (grid[0] == 'O' && grid [4]== 'O' && grid[8]== 'O') ||
            (grid[1] == 'O' && grid [4]== 'O' && grid[7]== 'O') ||
            (grid[1] == 'O' && grid [4]== 'O' && grid[7]== 'O') ||
            (grid[2] == 'O' && grid [5]== 'O' && grid[8]== 'O') ||
            (grid[2] == 'O' && grid [5]== 'O' && grid[8]== 'O') ||
            (grid[2] == 'O' && grid [4]== 'O' && grid[6]== 'O') ||
            (grid[3] == 'O' && grid [4]== 'O' && grid[5]== 'O') ||
            (grid[6] == 'O' && grid [7]== 'O' && grid[8]== 'O'))
    {
        end=0;
        return 2;
    }
    else if(count==9)
    {
        end=0;
        return 3;
    }
    else
    {
        return 4;
    }
}

void Result()
{
    if(GameEngine()==1)
    {
        Display();
        printf("\n\n\t\t\t\tPLAYER 1 WON\n");
    }
    else if(GameEngine()==2)
    {
        Display();
        printf("\n\n\t\t\t\tPLAYER 2 WON\n");
    }
    else if(GameEngine()==3)
    {
        Display();
        printf("\n\n\t\t\t\tGAME DRAW\n");
    }
    else
    {

    }
}
int  Start()
{
    while(end)
    {
        Display();
        GetInput();
        Display();
        Result();
    }
}

void ResetGame()
{
    int choice;
    fflush(stdin);
    printf("\n\nRESTART GAME? (y/N)(1/0): ");
    scanf("%d", &choice);
    if(choice)
    {
        end=1;
        Start();
        reset=1;
    }    
}

void ResetArray()
{

    char grid[9]={'1', '2', '3',
        '4', '5', '6',
        '7', '8', '9'};
    set=0;
}


int main()
{
    Display();
    PlayerModel();
    Start();

    while(reset)
    {
        ResetArray();
        ResetGame();
        reset=0;
    }

    printf("\nCREDITS: SAURONIL DAS\n\n");


    return 0;
}
