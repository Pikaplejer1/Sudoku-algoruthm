// Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool isFinished = false;


bool isCandiDate(int sudoku[9][9], int currentRow, int currentCollumn, int numberCheck)
{
    int rowGrid = (currentRow / 3) * 3;
    int collumnGrid = (currentCollumn / 3) * 3;
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[currentRow][i] == numberCheck)
            return false;
        if (sudoku[i][currentCollumn] == numberCheck)
            return false;
    }
        for (int j = rowGrid; j < rowGrid + 3; j++)
            for (int k = collumnGrid; k < collumnGrid + 3; k++)
                if (sudoku[j][k] == numberCheck)
                    return false;
    return true;
}

bool solver(int sudoku[9][9])
{
    for (int currentRow = 0; currentRow < 9; currentRow++)
    {
        for (int currentCollumn = 0; currentCollumn < 9; currentCollumn++)
        {
            if (sudoku[currentRow][currentCollumn] == 0)
            {
                for (int checkedNumber = 1; checkedNumber <= 9; checkedNumber++)
                {
                    if (isCandiDate(sudoku, currentRow, currentCollumn, checkedNumber))
                    {
                        sudoku[currentRow][currentCollumn] = checkedNumber;
                        if (solver(sudoku))
                            return true;
                        else
                            sudoku[currentRow][currentCollumn] = 0;
                    }
                }
                return false;
            }
        }
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
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << " ";
            if (j == 8) cout << endl;
        }
    solver(sudoku);
    cout << endl;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << " ";
            if (j == 8) cout << endl;
        }
    cout << endl;

   
}

