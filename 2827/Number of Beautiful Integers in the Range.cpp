// Number of Beautiful Integers in the Range.cpp
// https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/


class Solution {
public:
    int dp[10][21][2][2][20];
    int f(int index, int notEqual, int isLeading, int isSmaller, int remainder, int k, string num) {
        if(index == num.size()) {
            return (notEqual == 0 && remainder == 0);
        }
        if(dp[index][10 + notEqual][isLeading][isSmaller][remainder] != -1) {
            return dp[index][10 + notEqual][isLeading][isSmaller][remainder];
        }

        int ub = (isSmaller ? 9: num[index] - '0');
        cout<<index<<" "<<ub<<endl;
        int res = 0;
        for(int i=0; i<=ub; i++) {
            int notEqual_ = (isLeading && i==0) ? 0: (notEqual + ((i%2 == 0) ? 1: -1));
            int remainder_ = ( remainder*10 + i )%k;
            res += f(index+1, notEqual_, isLeading & (i == 0), isSmaller?isSmaller: (i!=ub), remainder_, k, num );
        }
        return dp[index][10 + notEqual][isLeading][isSmaller][remainder] = res;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        
        string high_ = "";
        while(high){
            high_ = to_string(high%10) + high_;
            high /= 10;
        }

        string low_ = "";
        low--;
        while(low){
            low_ = to_string(low%10) + low_;
            low /= 10;
        }
        memset(dp, -1, sizeof(dp));
        int r = f(0, 0, 1, 0, 0, k, high_);
        memset(dp, -1, sizeof(dp));
        int l = f(0, 0, 1, 0, 0, k, low_);
        return r - l;

    }
};

