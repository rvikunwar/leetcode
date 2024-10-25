// Count Stepping Numbers in Range.cpp
// https://leetcode.com/problems/count-stepping-numbers-in-range/description/


typedef long long ll;
int mod = 1000000000 + 7;
class Solution {
public:
    ll dp[101][2][2][11];
    ll f(int index, int last, int isLeading, int isSmaller, string &nums) {
        if(index == nums.size()) return 1;
        
        if(dp[index][isLeading][isSmaller][last+1] != -1) {
            return dp[index][isLeading][isSmaller][last+1];
        }
        ll res = 0;
        int ub = !isSmaller ? nums[index] - '0' : 9;

        for(int i=0; i<=ub; i++) {
            if(last != -1 && !isLeading) {
                if(abs(last - i) == 1) {
                    res = (res + f(index+1, i, isLeading & (i == 0), isSmaller? isSmaller: i != ub, nums))%mod;
                }
                continue;
            }
            res = (res + f(index+1, i, isLeading & (i == 0), isSmaller? isSmaller: i != ub, nums))%mod;
        }

        return dp[index][isLeading][isSmaller][last+1] = res%mod;
    }

    bool isStepping(string word) {
        int n = word.size();
        
        for(int i=0; i<n-1; i++) {
            if(abs(word[i] - word[i+1]) == 1) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }

    int countSteppingNumbers(string low, string high) {
        memset(dp, -1, sizeof(dp));
        ll h = f(0, -1, 1, false, high);
        h =  (mod + h)%mod;
        memset(dp, -1, sizeof(dp));
        ll l = f(0, -1, 1, false, low);
        l = (mod + l)%mod;
        return ((mod + h - l)%mod + isStepping(low))%mod;
    }
};

