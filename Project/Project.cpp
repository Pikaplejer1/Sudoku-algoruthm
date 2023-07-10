// Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
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
    bool IsFinished = false;
    bool IsCandidat[9][9];
    while (!IsFinished)
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                if (sudoku[i][j] == 0 && IsCandidat[i][j] == true)
                {
                   
                }

            }
    }


}

