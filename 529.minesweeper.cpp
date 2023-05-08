/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */

// @lc code=start
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
            for (int i = 0; i < neighbor.size(); i++) {
                if (valid(neighbor[i],board) && board[neighbor[i][0]][neighbor[i][1]] == 'M') {
                    count++;
                }
            }
            if (count == 0) {
                for (int i = 0; i < neighbor.size(); i++) {
                    if (valid(neighbor[i],board) && board[neighbor[i][0]][neighbor[i][1]] == 'E') {
                        vector<int> vec {neighbor[i][0], neighbor[i][1]};
                        help(board, vec);
                    }
                }
            }
            else {
                board[x][y] = '0' + count;
            }
        }
    }
};
// @lc code=end

