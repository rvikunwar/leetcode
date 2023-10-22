// You are given an array of integers nums (0-indexed) and an integer k.

// The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.

// Return the maximum possible score of a good subarray.

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left=k, right=k;
        int minVal = nums[k];
        int ans = nums[k];

        while(left > 0 || right < nums.size()-1){
            if(left == 0 || (right < nums.size()-1 && nums[right+1] > nums[left-1])){
                right++;
            } else {
                left--;
            }

            minVal = min(minVal, min(nums[left], nums[right]));
            ans = max(ans, (right-left+1)*minVal);
        }

        return ans;
    }
};