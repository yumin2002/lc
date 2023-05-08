// debug log
//  for loop i
// when pushed to the queue mark as discoverd
// distinguish between discovered and visited
/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
public:
    bool valid(int first, int second, vector<vector<int>> & grid){
        return first < grid.size() && first >= 0 
            && second < grid[0].size() && second >= 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_size = 0;
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]){
                    // perform  for the island
                    cout << i << " " << j << endl;
                    stack<pair<int,int>> s;
                    s.push({i,j});
                    int curr_size = 1;
                    grid[i][j] = 0;
                    while (!s.empty()){
                        pair<int,int> curr = s.top();
                        s.pop();
                        // cout << 9;
                        if (valid(curr.first, curr.second+1, grid) && grid[curr.first][curr.second+1]){
                            // cout << 1;
                            curr_size++;
                            grid[curr.first][curr.second+1] = 0;
                            s.push({curr.first, curr.second+1});
                            // cout << 2;
                        }
                        cout << 10;
                        if (valid(curr.first, curr.second-1, grid) && grid[curr.first][curr.second-1]){
                            // cout << 3;
                            curr_size++;
                            grid[curr.first][curr.second-1] = 0;
                            s.push({curr.first, curr.second-1});
                            // cout << 4;
                        }
                        cout << 11;
                        if (valid(curr.first+1, curr.second, grid) && grid[curr.first+1][curr.second]){
                            // cout << 5;
                            curr_size++;
                            grid[curr.first+1][curr.second] = 0;
                            s.push({curr.first+1, curr.second});
                            // cout << 6;
                        }
                        cout << 12;
                        if (valid(curr.first-1, curr.second, grid) && grid[curr.first-1][curr.second]){
                            // cout << 7;
                            curr_size++;
                            grid[curr.first-1][curr.second] = 0;
                            s.push({curr.first-1, curr.second});
                            // cout << 8;
                        }
                        // cout << 13;
                    }
                    // update max size if found larger island
                    if (curr_size > max_size) {
                        max_size = curr_size;
                    }
                }
            }
        }
        return max_size;
    }
};
// @lc code=end

