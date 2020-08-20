#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float result=0;
short clear=0;

void Add();
void Sub();
void Mul();
void Div();
void Pow();
void Sqrt();
void Clear();
int Menu();

int main()
{
    while(1)
    {
        switch(Menu())
        {
            case 1:
                Div();
                break;
            case 2:
                Mul();
                break;
            case 3:
                Sub();
                break;
            case 4:
                Add();
                break;
            case 5:
                Pow();
                break;
            case 6:
                Sqrt();
                break;
            case 7:
                Clear();
                break;
            case 8:
                exit(0);
            default:
                printf("\nInvalid Option.");
                break;
        }
    }
    return 0;
}

int Menu()
{
    char ch[5];
    int c;
    printf("\n***************RESULT- %.3f ***************\n", result);
    printf("\n1. Division        (/)");
    printf("\n2. Multiplication  (X)");
    printf("\n3. Substraction    (-)");
    printf("\n4. Addition        (+)");
    printf("\n5. Power           (^)");
    printf("\n6. Square Root     (|--)");
    printf("\n7. Clear Result     (C)");
    printf("\n8. Exit");
    printf("\n********************************************");

    printf("\n\nEnter Your Choice: ");
    scanf("%s", ch);
    c=atoi(ch);
    return c;
}


void Add() //1
{
    float a, b;
    if(clear)
    {
        printf("\nEnter Number: ");
        scanf("%f", &a);
        result+=a;
    }
    else
    {
        printf("\nProvide TWO Numbers: ");
        scanf("%f" "%f", &a, &b);
        result=a+b;
        clear++;
    }
}

void Sub() //2
{
    float a, b;
    if(clear)
    {
        printf("\nEnter Number: ");
        scanf("%f", &a);
        result-=a;
    }
    else
    {
        printf("\nProvide TWO Numbers: ");
        scanf("%f" "%f", &a, &b);
        result=a-b;
        clear++;
    }
}


void Mul() //3
{
    float a, b;
    if(clear)
    {
        printf("\nEnter Number: ");
        scanf("%f", &a);
        result*=a;
    }
    else
    {
        printf("\nProvide TWO Numbers: ");
        scanf("%f" "%f", &a, &b);
        result=a*b;
        clear++;
    }
}
void Div() //4
{
    float a, b;
    if(clear)
    {
        printf("\nEnter Number: ");
        scanf("%f", &a);
        result/=a;
    }
    else
    {
        printf("\nProvide TWO Numbers: ");
        scanf("%f" "%f", &a, &b);
        result=a/b;
        clear++;
    }
}
void Pow() //5
{
    float a, b;
    if(clear)
    {
        printf("\nEnter Number: ");
        scanf("%f", &a);
        result=pow(result, a);

    }
    else
    {
        printf("\nProvide Two Numbers (x^y): ");
        scanf("%f" "%f", &a, &b);
        result=pow(a, b);
        clear++;
    }
}
void Sqrt() //6
{
    float a;
    if(clear)
    {
        result=sqrt(result);
        printf("\nSquare Root of Result Number: %.3f", result);
    }
    else
    {
        printf("\nEnter Number: ");
        scanf("%f", &a);
        result=sqrt(a);
        clear++;
    }
}

void Clear()
{
    clear=0;
    result=0;
    system("clear");
}
