#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int Balance;
int t_amount;

int Account_Number;
char name[20];

void AccountDetail();
void Deposit();
void Withdraw();
int Menu();
void Transfer();
void CheckDetails();

int main()
{
    AccountDetail();

    while(1)
    {
        switch(Menu())
        {
            case 1: Deposit();
                    break;
            case 2:
                    Withdraw();
                    break;
            case 3: Transfer();
                    break;
            case 4: 
                    CheckDetails();
                    break;
            case 5:
                    exit(0);
                    break;
            default: printf("Invalid Choice\n");
                     break;
        }
    }

    return 0;
}

int Menu()
{
    char choice[10];
    int c;
    printf("\n1. Press 1 To Deposit.");
    printf("\n2. Press 2 To Withdraw.");
    printf("\n3. Press 3 To Transfer Money.");
    printf("\n4. Press 4 To Check Account Details.");
    printf("\n5. Press 5 To Exit Program.");

    printf("\n\nEnter Your Choice: ");
    scanf("%s", choice);
    c=atoi(choice);
    return c;
}

void Deposit()
{
    printf("\nEnter Amount To Deposit: ");
    scanf("%d", &t_amount);

    Balance+=t_amount;
}

void Withdraw()
{
    printf("\nEnter Withdraw Amount: ");
    scanf("%d", &t_amount);

    if(t_amount>Balance)
    {
        printf("\nInsufficient Fund\nYou Have %d/- in Your Account", Balance);
        Withdraw();
    }
    else
    {
        Balance-=t_amount;
    }
}

void Transfer()
{
    printf("\nEnter Transfer Amount: ");
    scanf("%d", &t_amount);

    if(t_amount>Balance)
    {
        printf("\nInsufficient Fund\nYou Have %d/- in Your Account", Balance);
        Transfer();
    }
    else
    {
        Balance-=t_amount;
    }
}

void CheckDetails()
{
    printf("\n***********************************************************");
    printf("\nName:                      %s", name);
    printf("\nAccount Number:            %d", Account_Number);
    printf("\nAccount Net Balance:       %d/-", Balance);
    printf("\n***********************************************************\n");
}

void AccountDetail()
{
    printf("Enter Your Name: ");
    fflush(stdin);
    gets(name);

    printf("\nEnter Your Account Number: ");
    scanf("%d", &Account_Number);
    Balance=0;
    printf("\nEnter Your Account Balance: ");
    scanf("%d", &Balance);
}
