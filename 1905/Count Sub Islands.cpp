// Count Sub Islands.cpp

// You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

// An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

// Return the number of islands in grid2 that are considered sub-islands.

class Solution {
public:
    vector<vector<int>> grid1_;
    vector<vector<int>> grid2_;
    vector<vector<int>> visited;
    int m;
    int n;
    bool is_valid(int i, int j) {
        if(i >= m || j >= n || i < 0 || j < 0) {
            return false;
        }
        return true;
    }

    void dfs(int i, int j, int &is) {
        int row[4] = {1, 0, -1, 0};
        int col[4] = {0, -1, 0, 1};

        if(grid1_[i][j] == 0) {
            is = 0;
        }
        visited[i][j] = 1;
        
        for(int k=0; k<4; k++) {
            int new_row = row[k] + i; 
            int new_col = col[k] + j;
            if(is_valid(new_row, new_col) && !visited[new_row][new_col] && grid2_[new_row][new_col]) {
                dfs(new_row, new_col, is);
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        grid1_ = grid1;
        grid2_ = grid2;
        m = grid1.size();
        n = grid1[0].size();
        int ans = 0;
        visited.resize(m, vector<int> (n, 0));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int is = 1;
                if(!visited[i][j] && grid2[i][j] == 1) {
                    dfs(i, j, is);
                    ans += is;
                }
            }
        }

        return ans;
    }
};
