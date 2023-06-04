// /*
//  * @lc app=leetcode id=529 lang=cpp
//  *
//  * [529] Minesweeper
//  */

// // @lc code=start
class Solution {
public:
    bool valid(vector<int> & vec, vector<vector<char>> & board) {
        return vec[0] >= 0 && vec[0] < board.size() && vec[1] >= 0 && vec[1] < board[0].size();
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        help(board, click);
        return board;
    }
    void help(vector<vector<char>> & board, vector<int> & click) {
        int x = click[0];
        int y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }
        else if (board[x][y] == 'E'){
            board[x][y] = 'B';
            vector<vector<int>> neighbor{
                {x+1,y-1}, {x+1,y}, {x+1,y+1}, 
                {x,y+1}, {x,y-1}, 
                {x-1,y+1}, {x-1,y-1}, {x-1,y}
            };
            int count = 0;
            for (int i = 0; i < 8; i++) {
                int first = neighbor[i][0];
                int second = neighbor[i][1];
                if (valid(neighbor[i],board) && board[first][second] == 'M') {
                    count++;
                }
            }
            if (count != 0) {
                board[x][y] = '0' + count;
            }
            else {
                for (int i = 0; i < 8; i++) {
                    int first = neighbor[i][0];
                    int second = neighbor[i][1];
                    if (valid(neighbor[i],board) && board[first][second] == 'E') {
                        vector<int> vec {first, second};
                        help(board, vec);
                    }
                }
            }
        }
    }
};
// class Solution {
//     vector<vector<int>> dir = {{-1,-1}, {0,-1}, {1, -1}, {-1,0}, {1, 0}, {-1, 1}, {0, 1}, {1,1}};

//     void dfs(vector<vector<char>>& board, int row, int col) {
//         // current cell must be 'E'
//         int mine = 0;
//         // Get number of mines first.
//         for (int i = 0; i < 8; ++i) {
//             int x = row+dir[i][0], y = col+dir[i][1];
//             if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
//                 if (board[x][y] == 'M') ++mine;
//             }

//         }
//         if (mine) board[row][col] = mine+'0';
//         else {
//             board[row][col] = 'B';
//             for (int i = 0; i < 8; ++i) {
//                 int x = row+dir[i][0], y = col+dir[i][1];
//                 if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == 'E')
//                     dfs(board, x, y);
//             }

//         }
//     }
// public:
//     vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
//         int row = click[0], col = click[1];
//         if (board[row][col] == 'M') {
//             board[row][col] = 'X';
//             return board;
//         }
//         // click 'E'
//         dfs(board, click[0], click[1]);
//         return board;
//     }
// };

// // @lc code=end
//https://xiaoguan.gitbooks.io/leetcode/content/LeetCode/529-minesweeper-medium.html