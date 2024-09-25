// Longest Palindromic Subsequence.cpp

// Memoization
class Solution {
public:
    int helper(int index1, int index2, string &s1, string &s2, vector<vector<int>> &dp) {
        if(index1 < 0 || index2 < 0) {
            return 0;
        }

        if(dp[index1][index2] != -1) {
            return dp[index1][index2];
        }

        int ans;
        if(s1[index1] == s2[index2]) {
            ans = 1 + helper(index1-1, index2-1, s1, s2, dp);
        } else {
            ans = max(helper(index1-1, index2, s1, s2, dp), helper(index1, index2-1, s1, s2, dp));
        }

        return dp[index1][index2]= ans;
    }

    int longestPalindromeSubseq(string s) {
        int size = s.size();
        vector<vector<int>> dp(size, vector<int> (size, -1));
        string s2 = "";

        for(int i=size-1; i>=0; i--) {
            s2 += s[i];
        }

        return helper(size-1, size-1, s, s2, dp);
    }
};


// Tabular 
int longestPalindromeSubseq(string s) {
    int size = s.size();
    vector<vector<int>> dp(size+1, vector<int> (size+1, 0));
    string s2 = "";

    for(int i=size-1; i>=0; i--) {
        s2 += s[i];
    }

    for(int i=1; i<=size; i++) {
        for(int j=1; j<=size; j++) {
            if(s[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[size][size];
}