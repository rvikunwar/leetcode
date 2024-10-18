// Count Number of Maximum Bitwise-OR Subsets.cpp
// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/?envType=daily-question&envId=2024-10-18

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int ans = 0;
        int size = nums.size();
        int maxi = 0;
        for(int i=0; i<(1<<size); i++) {
            int or_ = 0;
            for(int j=0; j<size; j++) {
                if(i>>j & 1) {
                    or_ |= nums[j];
                }
            }

            if(or_ > maxi) {
                maxi = or_;
                ans = 1;
            } else if(or_ == maxi) {
                ans++;
            }
        }
        return ans;
    }
};

