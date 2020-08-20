/*Author - Sauronil Das 
 * Version - Alpha v1.0
 * Dated 1st of August, 2020
 * LICENSE - Open Source Free Market Software
*/

#include<stdio.h>  //for source string I/O
#include<stdlib.h> //for standard library

#define CAPACITY 100 //Parking Space capacity --- Edit as your requrement



//Base Idea is Implementing Parking Lot Management

//Forward Decalarations
void FourWheeler();
void ThreeWheeler();
void TwoWheeler();
void Display();
void Delete();

int Menu();

//global declarations

int N_4W=0; //Number of 4-wheeler -- BUS, TRUCK & CAR
int N_3W=0; //Number of 3-wheeler -- Rickshaw
int N_2W=0; //Number of 2-wheeler -- Scooter & Bike

/* 
 * Pricing System - 4-Wheeler - 50/-
 *                  3-Wheeler - 40/-
 *                  2-Wheeler - 20/-
 *                  
*/

//Change Values of Amount as per Requirement

int amount_4W=50;
int amount_3W=30;
int amount_2W=20;

int grand_amount=0;
int total_vehicles=0;

int choice;



int main()
{
    while(1)
    {
        switch(Menu(choice))
        {
            case 1: FourWheeler();
                break;
            case 2: ThreeWheeler();
                break;
            case 3: TwoWheeler();
                break;
            case 4: Delete(&N_4W, &N_3W, &N_2W, &grand_amount, &total_vehicles);
                break;
            case 5: Display();
                break;
            case 0: exit(0);
                    break;
            default:
                printf("\nInvalid Choice\n");
                break;
        }
    }
    return 0;
}

int Menu() //Display Function -- USER INTERFACE
{
    printf("\n1. Press 1 for Four-Wheeler\n");
    printf("\n2. Press 2 for Three-Wheeler\n");
    printf("\n3. Press 3 for Two-Wheeler\n");
    printf("\n4. Press 4 To Delete Entry\n");
    printf("\n5. Press 5 To Display Details\n");
    printf("\n6. Press 0 To Exit Program\n");

    printf("\nEnter Choice: ");
    scanf("%d", &choice);
    return choice;
}

void FourWheeler()
{
    if(total_vehicles < CAPACITY)
    {
        N_4W++;
        total_vehicles++; //Update 
        grand_amount=grand_amount+amount_4W;
    }
    else
    {
        printf("\nError: CAPACITY EXCEEDED\n");
        //some call to menu to be inserted
    }
}

void ThreeWheeler()
{
    if(total_vehicles < CAPACITY)
    {
        N_3W++;
        total_vehicles++; //Update 
        grand_amount=grand_amount+amount_3W;
    }
    else
    {
        printf("\nError: CAPACITY EXCEEDED\n");
        //some call to menu to be inserted
    }

}
void TwoWheeler()
{
    if(total_vehicles < CAPACITY)
    {
        N_2W++;
        total_vehicles++; //Update 
        grand_amount=grand_amount+amount_2W;
    }
    else
    {
        printf("\nError: CAPACITY EXCEEDED\n");
        //some call to menu to be inserted
    }

}

void Display(void)
{
    printf("\nNumber of Four-Wheeler:      %3d", N_4W);
    printf("\nNumber of Three-Wheeler:     %3d", N_3W);
    printf("\nNumber of Two-Wheeler:       %3d\n", N_2W);
    printf("\n\nTotal Vechicles Parked:      %3d", total_vehicles);
    printf("\n\nRevenue Generated:           %3d/-\n", grand_amount);
}

void Delete(int* N_4W, int* N_3W, int* N_2W, int* grand_amount, int* total_vehicles)
{
    *N_4W=0;
    *N_3W=0;
    *N_2W=0;
    *grand_amount=0;
    *total_vehicles=0;
}
