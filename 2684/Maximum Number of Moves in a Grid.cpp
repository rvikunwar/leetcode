// Maximum Number of Moves in a Grid.cpp
// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/?envType=daily-question&envId=2024-10-29

class Solution {
public:

    bool isValid(int r, int c, int rSize, int cSize) {
        if(r >= 0 && c >= 0 && r < rSize && c < cSize) return true;
        return false;
    }

    int dfs(int r, int c, int rSize, int cSize, vector<vector<int>>& grid, vector<vector<int>> &vc) {
        int row[] = { -1, 0, 1};
        int col[] = {  1, 1, 1};
        int ans = 0;
        if(vc[r][c] != -1) return vc[r][c];
        for(int k=0; k<3; k++) {
            int newR = r + row[k];
            int newC = c + col[k];
            if(isValid(newR, newC, rSize, cSize) && grid[newR][newC] > grid[r][c]) {
                ans = max(ans, dfs(newR, newC, rSize, cSize, grid, vc));
            }
        }
        return vc[r][c] = 1 + ans;
    }
    

    int maxMoves(vector<vector<int>>& grid) {

        int rSize = grid.size();
        int cSize = grid[0].size();
        int ans = 0;
        vector<vector<int>> vc(rSize, vector<int> (cSize, -1));
        
        for(int i=0; i<rSize; i++) {
            ans = max(ans, dfs(i, 0, rSize, cSize, grid, vc));
        }
        
        return ans-1;
    }
};

