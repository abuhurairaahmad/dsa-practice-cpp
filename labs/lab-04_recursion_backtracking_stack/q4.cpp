#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool dfs(vector<vector<char>>& board, string& word, int r, int c, int index) {
    if (index == word.size()) {
        return true;
    }
    
    int m = board.size();
    int n = board[0].size();

    if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[index]) {
        return false;
    }

    char originalChar = board[r][c];
    board[r][c] = '#'; // Mark the cell as visited

    bool found = dfs(board, word, r + 1, c, index + 1) ||
                 dfs(board, word, r - 1, c, index + 1) ||
                 dfs(board, word, r, c + 1, index + 1) ||
                 dfs(board, word, r, c - 1, index + 1);

    board[r][c] = originalChar; // Restore the original character
    return found;
}


bool exist(vector<vector<char>>& board, string word) {
    if (board.empty() || board[0].empty() || word.empty()) {
        return false;
    }

    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == word[0]) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    // Example 1 Board
    vector<vector<char>> board1 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word1 = "ABCCED";
    cout << boolalpha;
    cout << "Example 1 (\"" << word1 << "\"): " 
              << exist(board1, word1) << " (Expected: true)\n";

    // Example 2 Board
    vector<vector<char>> board2 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word2 = "ABCB";
    cout << "Example 2 (\"" << word2 << "\"): " 
              << exist(board2, word2) << " (Expected: false)\n";

    return 0;
}
