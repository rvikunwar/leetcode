// Maximum Multiplication Score.cpp
// https://leetcode.com/problems/maximum-multiplication-score/description/

typedef long long ll;
ll maxi = 1e12;
ll mini = -1e12;
class Solution {
public:
    // vector<vector<ll>> dp; 
    // ll helper(int index1, int index2, vector<int>& a, vector<int>& b) {
    //     if(index1 == 4) {
    //         return 0;
    //     }

    //     if(index2 == b.size()) {
    //         return mini;
    //     }

    //     if(dp[index1][index2] != -1) {
    //         return dp[index1][index2];
    //     }

    //     ll ans = mini;
    //     for(int i=index2; i<b.size(); i++) {
    //         ll val = helper(index1+1, i+1, a , b);
    //         ans = max(ans, ((ll)a[index1] * (ll)b[i]) + val);
    //     }

    //     return dp[index1][index2] = ans;
    // }

    // long long maxScore(vector<int>& a, vector<int>& b) {
    //     dp.resize(4, vector<ll> (b.size(), -1));
    //     return helper(0, 0, a, b);
    // }

    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<ll>> dp(5, vector<ll> (b.size()+1, mini));

        for(int j=0; j<b.size()+1; j++) {
            dp[0][j] = 0;
        } 

        for(int i=1; i<=4; i++) {
            for(int j=1; j<=b.size(); j++) {
                dp[i][j] = max(((ll)a[i-1] * (ll)b[j-1]) + dp[i-1][j-1], dp[i][j-1]);
            }
        }

        return dp[4][b.size()];
    }
};

