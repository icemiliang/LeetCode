### 79\. [Word Search](https://leetcode.com/problems/word-search/)

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:
```
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
```

#### Solution 1

C++

```
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() or board[0].empty()) return false;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (search(board, visited, word, 0, i, j)) return true;
            }
        }
        return false;
    }
    
    bool search(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int pos, int i, int j) {
        if (pos == word.size()) return true;
        if (i < 0 or i >= board.size()) return false;
        if (j < 0 or j >= board[i].size()) return false;
        if (visited[i][j]) return false;
        if (board[i][j] != word[pos]) return false;
        visited[i][j] = true;
        bool res = search(board, visited, word, pos + 1, i - 1, j)
                or search(board, visited, word, pos + 1, i + 1, j)
                or search(board, visited, word, pos + 1, i, j - 1)
                or search(board, visited, word, pos + 1, i, j + 1);
        visited[i][j] = false;
        return res;
    }
};
```
