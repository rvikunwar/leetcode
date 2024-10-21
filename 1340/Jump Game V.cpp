// Jump Game V.cpp
// https://leetcode.com/problems/jump-game-v/description/

class Solution {
public:
    int f(int index, vector<int>& arr, int d, vector<int> &dp) {
        int n = arr.size();
        int ans = 0;
        if(dp[index] != -1) return dp[index];
        for(int i=index+1; i<= min(n-1, (index+d)); i++) {
            if(arr[index] <= arr[i]) {
                break;
            } else {
                ans = max(ans, f(i, arr ,d, dp));
            }
        }

        for(int i=index-1; i>= max(0, (index-d)); i--) {
            if(arr[index] <= arr[i]) {
                break;
            } else {
                ans = max(ans, f(i, arr, d, dp));
            }
        }

        return dp[index] = 1 + ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int ans = 0;
        vector<int> dp(arr.size()+1, -1);
        for(int i=0; i<arr.size(); i++) {
            ans = max(ans, f(i, arr, d, dp));
        }
        return ans;
    }
};

