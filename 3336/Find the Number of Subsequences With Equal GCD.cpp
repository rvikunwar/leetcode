// Find the Number of Subsequences With Equal GCD.cpp
// https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/description/


int mod = 1000000000+7;
class Solution {
public:
    int f(int index, int gcd1, int gcd2, int dp[201][202][202], vector<int>& nums) {
        if(index == nums.size()) {
            return gcd1 == gcd2 && gcd1 != -1;
        }
        if(dp[index][gcd1+1][gcd2+1] != -1) return dp[index][gcd1+1][gcd2+1];
        int ans = 0;
        ans = (ans + f(index+1, gcd1 == -1? nums[index]:gcd(gcd1, nums[index]), gcd2, dp, nums))%mod;
        ans = (ans + f(index+1, gcd1, gcd2 == -1? nums[index]: gcd(gcd2, nums[index]), dp, nums))%mod;
        ans = (ans + f(index+1, gcd1 , gcd2, dp, nums))%mod;

        return dp[index][gcd1+1][gcd2+1] = ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        int dp[201][202][202];
        memset(dp, -1, sizeof(dp));
        return f(0, -1, -1, dp, nums);
    }
};
