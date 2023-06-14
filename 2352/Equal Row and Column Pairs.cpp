// Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

// A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).


class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> mp;
        int pair = 0;
        int n = grid.size();
        for(int i=0; i<n; i++){
            string s = "";
            for(int j=0; j<n; j++){
                s += (to_string(grid[i][j]) + ",");
            }
            mp[s]++;
        }

        for(int i=0; i<n; i++){
            string s = "";
            for(int j=0; j<n; j++){
                s += (to_string(grid[j][i]) + ",");
            }
            if(mp.find(s) != mp.end()) pair+=mp[s];
        }

        return pair;

    }
};