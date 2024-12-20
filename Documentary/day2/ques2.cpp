#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> rowSet;
            unordered_set<char> colSet;
            unordered_set<char> boxSet;
            
            for (int j = 0; j < 9; ++j) {
                // Check row
                if (board[i][j] != '.' && !rowSet.insert(board[i][j]).second) {
                    return false;
                }
                // Check column
                if (board[j][i] != '.' && !colSet.insert(board[j][i]).second) {
                    return false;
                }
                // Check 3x3 box
                int rowIndex = 3 * (i / 3) + j / 3;
                int colIndex = 3 * (i % 3) + j % 3;
                if (board[rowIndex][colIndex] != '.' && !boxSet.insert(board[rowIndex][colIndex]).second) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution sol;
    cout << sol.isValidSudoku(board) << endl; // Output will be 1 (true) or 0 (false)
    return 0;
}
