#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int array[3][3] = makeArray();
    int rowTotal = 0; 
    int columnTotal = 0;
    
    for(int row = 0; row < 3; row++) //printing the array pattern
    {
        printf("[");
        for(int column = 0; column < 3; column++)
        {
            printf("%d", array[row][column]);
        }
        printf("]\n");
    }

    for(int row = 0; row < 3; row++) //checking if rows are equal to 15
    {
        rowTotal = 0;
        for(int column = 0; column < 3; column++)
        {
            rowTotal += array[row][column];
        }
        if(rowTotal != 15)
        {
            printf("This array is not a magic square.\n");
            row = 2; //ending loop
        }
    }
    for(int column = 0; column < 3; column++) //checking if columns are equal to 15
    {
        columnTotal = 0;
        for(int row = 0; row < 3; row++)
        {
            columnTotal += array[row][column];
        }
        if(columnTotal != 15)
        {
            printf("This array is not a magic square.\n");
            column = 2; //ending loop
        }
    }
    int diagonalRow1 = array[0][0] + array[1][1] + array[2][2]; //finding sum of diagonal
    int diagonalRow2 = array[2][0] + array [1][1] + array[0][2]; //finding sum of diagonal

    if(diagonalRow1 != 15 || diagonalRow2 != 15)
    {
        printf("This array is not a magic square\n");
    }
    if(diagonalRow1 == 15 && diagonalRow2 == 15 && rowTotal == 15) 
    {
        printf("Congratulations you have a magic square!\n");
    }
    else
    {
        printf("You do not have a magic square\n");
    }
}
int *makeArray(void)
{
    int array[3][3];//2d array holding the values
    int holdPlace[9]; //making sure that no random numbers become repeated
    int recorded = 0; //recording random numbers repeated
    int conflictIndex = 100; //Index of repeated value, making it 100 because I need to test it and 0 or null will not work
    
    time_t t;
    srand((unsigned) time(&t));

    for(int row = 0; row < 3; row++)//creating a random array
    {
        for(int column = 0; column < 3; column++)
        {
            if(conflictIndex != NULL) //if there is a value repeated then we can't move on to the next column
            {
                column--; //when for loop happens again it will go back to where we substracted by one
            }
            
            int randomNumber = rand() % 9;
            int indexHoldPlace = 0; //index of array holdPlace
            conflictIndex = 100; //When value is repeated, making it 100 because I need to test it and 0 or null will not work
            while (randomNumber != holdPlace[indexHoldPlace] && indexHoldPlace < 9) //checking to see if the random number generated 
                                                                                    //has been repeated
            {
                if(holdPlace[indexHoldPlace] == randomNumber)
                {
                    conflictIndex = indexHoldPlace;
                }
                indexHoldPlace++;
            }
            if (conflictIndex == 100) //When no values are repeated then conflictIndex is 100 because it wasn't changed
            {
                randomNumber = array[row][column];
                randomNumber = holdPlace[recorded];
                recorded++;
            }
        }
        
    }
    
    return array;
}