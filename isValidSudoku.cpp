#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    map<char, char> checkingRow;
    map<char, char> checkingCol;
    vector<int> vect;

    for(int v : vect){
        
    }

    // checking on row and col
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; i < 9; j++)
        {
            char current = board[i][j];

            if(current == '.') continue;

            if(checkingRow.count(current) == 0){
                checkingRow[current] = current;
            } 

            if (board[i][j] != '.')
            {
                if (checkingRow.count(board[i][j]) == 0)
                {
                    checkingRow[board[i][j]] = board[i][j];
                }
                else
                {
                    return false;
                }
            }

            if (board[j][i] != '.')
            {
                if (checkingCol.count(board[j][i]) == 0)
                {
                    checkingCol[board[j][i]] = board[j][i];
                }
                else
                {
                    return false;
                }
            }
        }

        checkingRow.clear();
        checkingCol.clear();
    }

    return true;
}

int main()
{

    return 0;
}