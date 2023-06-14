// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.


#define pr pair<int, int>
class Solution {
public:
    bool isValid(int rows, int cols, int i, int j){
        if(i < 0 || j< 0 || i >= rows || j >= cols) return false;
        return true;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        int delRows[] = {1, 0, -1, 0};
        int delCols[] = {0, 1, 0, -1};

        vector<vector<int>> dist(rows, vector<int> (cols,1e9));
        priority_queue<pair<int, pr>, vector<pair<int, pr>>, greater<pair<int, pr>>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            pair<int, pr> p = pq.top();
            pr pd = p.second;
            int i = pd.first;
            int j = pd.second;
            int cost = p.first;
            pq.pop();
            for(int k=0; k<4; k++){
                int newRow = delRows[k] + i;
                int newCol = delCols[k] + j;
                if(isValid(rows, cols, newRow, newCol)){
                    int newCost = max(cost, abs(heights[newRow][newCol] - heights[i][j]));
                    if(newCost < dist[newRow][newCol]){
                        pq.push({newCost, {newRow, newCol}});
                        dist[newRow][newCol] = newCost;
                    }
                }
            }
        }

        return dist[rows-1][cols-1];
    }
};