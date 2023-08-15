// You are given a 0-indexed integer array nums. You have to find the maximum sum of a pair of numbers from nums such that the maximum digit in both numbers are equal.

// Return the maximum sum or -1 if no such pair exists.


class Solution {
public:
    int findMaxDigit(int value){
        int maxi = 0;
        int mod;
        while(value > 0){
            mod = value % 10;
            value /= 10;
            maxi = max(maxi, mod);
        }
        return maxi;
    }
    
    
    int maxSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = -1;
        
        for(auto it: nums){
            int maxDigit = findMaxDigit(it);
            if(mp[maxDigit]){
                ans = max(ans, it+mp[maxDigit]);
            }
            mp[maxDigit] = max(mp[maxDigit], it);
        }
        
        return ans;
    }
};