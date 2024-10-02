// Rank Transform of an Array.cpp
// https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2024-10-02

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        int n = arr.size();
        vector<int> copy = arr;

        sort(arr.begin(), arr.end());
        int rank = 1;
        for(int i=0; i<n; i++) {
            if(mp.find(arr[i]) == mp.end()) {
                mp[arr[i]] = rank;
                rank++;
            }
        }

        
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++) {
            int rank = mp[copy[i]];
            ans[i] = rank;
        }

        return ans;
    }
};

