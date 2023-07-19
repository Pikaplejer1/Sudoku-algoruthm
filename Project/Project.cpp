// Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool isFinished = false;

/*
void solver(int sudoku[9][9],int row, int collumn,int changedNumber,int checkedNumbers[9])
{
    int checkedNumber = 0;
    sudoku[row][collumn] = changedNumber;
    if (isFinished == true) return;
    if (sudoku[row][collumn] == 0)
    {
        if (collumn==9)
        {
            solver(sudoku, row + 1, 0,changedNumber,checkedNumbers);
        }
        if (row == 9 && collumn == 9)
            return;
        solver(sudoku, row, collumn + 1,changedNumber, checkedNumbers);
    }
    for (int i = 0; i < 9; i++)
    {
        if (i != checkedNumbers[i])
        {
            checkedNumber = i;
            checkedNumbers[i] = i;
            solver(sudoku, row, collumn, checkedNumber, checkedNumbers);
        }    

    }

}
*/

bool stockSolver(int currentRow, int currentCollumn)
{
    int isStock[9][9] = {};
    if (isStock[currentRow][currentCollumn] == 0)
        return false;
    else return true;
}

bool isCanditate(int sudoku[9][9], int currentRow, int currentCollumn, int numberCheck)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[currentRow][i] == numberCheck)
            return false;
        else if (sudoku[i][currentCollumn] == numberCheck)
            return false;
        else return true;
    }
}

bool solver(int sudoku[9][9], int currentRow, int currentCollumn, int checkedNumbers[9], int numberCheck, bool isStock[9][9])
{
    bool isFinished = false;
    int checkedNumber = 0;
    /*
    if (sudoku[currentRow][currentCollumn] != 0)
    {
        if (currentCollumn == 8)
        {
            currentCollumn = 0;
            currentRow++;
        }
        currentCollumn++;
    }
   
    for (int i = 0; i < 9; i++)
    {
        if (isCanditate(sudoku, currentRow, currentCollumn, i))
        {
            checkedNumbers[i] = i;
            checkedNumber = i;
            sudoku[currentRow][currentCollumn] = i;
            solver(sudoku, currentRow, currentCollumn, checkedNumbers, i, isStock);
        }
    }
    */
    
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[currentRow][currentCollumn] == 0)
            {
                for (checkedNumber = 0; checkedNumber < 9; i++)
                {
                    if (isCanditate(sudoku, currentRow, currentCollumn, checkedNumber))
                    {
                        sudoku[currentRow][currentCollumn] = checkedNumber;
                        if (isFinished)
                            return true;
                        else
                            sudoku[i][j] = 0;
                    }
                }
            }
            return false;

        }
    return true;
   
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
            //solver(sudoku, i, j,0,0);
        }
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            stockSolver(i, j);
        }
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j]<< " ";
            if (j == 8) cout << endl;   
        }
    
}

