// Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>



bool isFinished = false;

bool isCanditate(int row, int collumn, int checkedNumber, int sudoku[9][9])
{
    for (int i = 0; i < 9; i++)
        if (sudoku[row][i] == checkedNumber) return false;
    for (int i = 0; i < 9; i++)
                if (sudoku[i][row] == checkedNumber) return false;
    return true;
}

bool isEmpty(int sudoku)
{
    if (sudoku == 0);
        return true;
}

void solver(int sudoku[9][9],int row, int collumn)
{
    int checkedNumber = 0;
    if (isFinished == true) return;
    while(!isEmpty(sudoku[row][collumn]))
    {
        if (collumn<9)
        {
            collumn++;
        }
        row++;
        collumn = 0;
    }
    for (int i = 0; i < 9; i++)
    {
        checkedNumber = i;
        if (isEmpty(sudoku[row][collumn]) && isCanditate(row, collumn,checkedNumber, sudoku));
        sudoku[row][collumn] = checkedNumber;
    }

}

int main()
{
    const int rows = 9, collumns = 9;
    int sudoku[9][9] =
    {
        {0,0,4,0,5,0,0,0,0},
        {9,0,0,7,3,4,6,0,0},
        {0,0,3,0,2,1,0,4,9},
        {0,3,5,0,9,0,4,8,0},
        {0,9,0,0,0,0,0,3,0},
        {0,7,6,0,1,0,9,2,0},
        {3,1,0,9,7,0,2,0,0},
        {0,0,9,1,8,2,0,0,3},
        {0,0,0,0,6,0,1,0,0}
    };
    for(int i=0;i<9;i++)
        for (int j = 0; j < 9; j++)
        {
            solver(sudoku, i, j);
        }

}

