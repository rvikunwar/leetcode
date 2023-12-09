// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000


class Solution {
public:
    // int findMaxAmount(vector<int>& nums, int index, int firstRobbed, int lastRobbed, int size) {
    //     if(index == (size-1)) {
    //         if(firstRobbed || lastRobbed) {
    //             return 0;
    //         } else {
    //             return nums[index];
    //         }
    //     }
    //     if(lastRobbed) {
    //         return findMaxAmount(nums, index+1, firstRobbed, 0, size);
    //     } 
    //     return max(nums[index] + findMaxAmount(nums, index+1, firstRobbed, 1, size), 
    //         findMaxAmount(nums, index+1, firstRobbed, 0, size));
    // }

    // int rob(vector<int>& nums) {
    //     int size = nums.size();
    //     if(size == 1) {
    //         return nums[0];
    //     }
    //     return max(nums[0] + findMaxAmount(nums, 1, 1, 1, size), findMaxAmount(nums, 1, 0, 0, size));
    // }

    int findMaxAmount(vector<int>& nums, int index, int firstRobbed, int lastRobbed, int size, vector<vector<vector<int>>> &dp) {
        if(index == (size-1)) {
            if(firstRobbed || lastRobbed) {
                return 0;
            } else {
                return nums[index];
            }
        }

        if(dp[index][lastRobbed][firstRobbed] != -1){
            return dp[index][lastRobbed][firstRobbed];
        }

        if(lastRobbed) {
            return dp[index][lastRobbed][firstRobbed] = findMaxAmount(nums, index+1, firstRobbed, 0, size, dp);
        } 
        return dp[index][lastRobbed][firstRobbed] = max(nums[index] + findMaxAmount(nums, index+1, firstRobbed, 1, size, dp), 
            findMaxAmount(nums, index+1, firstRobbed, 0, size, dp));
    }

    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<vector<vector<int>>> dp(size, vector<vector<int>> (2, vector<int> (2, -1)));
        if(size == 1) {
            return nums[0];
        }
        return max(nums[0] + findMaxAmount(nums, 1, 1, 1, size, dp), findMaxAmount(nums, 1, 0, 0, size, dp));
    }
};