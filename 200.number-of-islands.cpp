/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
bool validCoord(int x, int y, vector<vector<char>>& grid) {
    return x >= 0 && y >= 0 && x <= grid.size() - 1 && y <= grid[0].size() - 1;
}
public:
    struct Coord{
        int x;
        int y;
    };
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size()==0) return 0;
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != '0'){
                    count++;
                    // mark all land of this island as visited
                    queue<Coord> myQueue;
                    Coord first;
                    first.x = i;
                    first.y = j;
                    myQueue.push(first);
                    grid[i][j] = '0';
                    // cout << i << " " << j << endl;
                    while (!myQueue.empty()) {
                        Coord curr = myQueue.front();
                        myQueue.pop();
                        // cout << "value of coord" << curr.x << " " << curr.y << endl;
                        if (validCoord(curr.x-1, curr.y, grid) && grid[curr.x-1][curr.y] != '0') {
                            Coord neighbor = {curr.x-1, curr.y};
                            grid[curr.x-1][curr.y] = '0';
                            myQueue.push(neighbor);
                            // cout << "value of neighbor" << neighbor.x << " " << neighbor.y << endl;
                        }
                        // if (validCoord(curr.x+1, curr.y, grid)) {
                        //     cout << grid[curr.x+1][curr.y]<< endl;
                        // }
                        if (validCoord(curr.x+1, curr.y, grid) && grid[curr.x+1][curr.y] != '0') {
                            Coord neighbor = {curr.x+1, curr.y};
                            grid[curr.x+1][curr.y] = '0';
                            myQueue.push(neighbor);
                            // cout << "value of neighbor" << neighbor.x << " " << neighbor.y << endl;
                        }
                        if (validCoord(curr.x, curr.y+1, grid) && grid[curr.x][curr.y+1] != '0') {
                            Coord neighbor = {curr.x, curr.y+1};
                            grid[curr.x][curr.y+1] = '0';
                            myQueue.push(neighbor);
                            // cout << "value of neighbor" << neighbor.x << " " << neighbor.y << endl;
                        }
                        if (validCoord(curr.x, curr.y-1, grid) && grid[curr.x][curr.y-1] != '0') {
                            Coord neighbor = {curr.x, curr.y - 1};
                            grid[curr.x][curr.y-1] = '0';
                            myQueue.push(neighbor);
                            // cout << "value of neighbor" << neighbor.x << " " << neighbor.y << endl;
                        }
                    }
                }
            }
        }
        return count;

    }
};
// @lc code=end

// strucuture initialization
// address temp_addres = {
//   0,  // street_no
//   nullptr,  // street_name
//   "Hamilton",  // city
//   "Ontario",  // prov
//   nullptr,  // postal_code
// };
