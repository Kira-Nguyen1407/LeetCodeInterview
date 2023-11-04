#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int size = 9;
        bool col[size][size] = {false};
        bool row[size][size] = {false};
        bool box[size][size] = {false};

        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j){

                if(board[i][j] == '.'){
                    continue;
                }

                int index = board[i][j] - '0' - 1;

                if(row[i][index] || col[j][index] || box[(i/3)*3 + j/3][index]){
                    return false;
                }

                row[i][index] = true;
                col[j][index] = true;
                box[(i/3)*3 + j/3][index] = true;
            }
        }

        return true;
    }
};

int main(){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'}
                                ,{'6','.','.','1','9','5','.','.','.'}
                                ,{'.','9','8','.','.','.','.','6','.'}
                                ,{'8','.','.','.','6','.','.','.','3'}
                                ,{'4','.','.','8','.','3','.','.','1'}
                                ,{'7','.','.','.','2','.','.','.','6'}
                                ,{'.','6','.','.','.','.','2','8','.'}
                                ,{'.','.','.','4','1','9','.','.','5'}
                                ,{'.','.','.','.','8','.','.','7','9'}};

    
    Solution *s = new Solution();
    cout << s->isValidSudoku(board) << endl;

    return 0;
}