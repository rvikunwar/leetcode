// Leetcode - You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

 

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

// https://leetcode.com/problems/target-sum/description/


class Solution
{

public:
    void sumdiff(int index, int val, int target, int N, int &count, vector<int> &nums)
    {
        if (index + 1 == N)
        {
            if (val == target)
            {
                count++;
            }
            return;
        }

        sumdiff(index + 1, val + nums[index + 1], target, N, count, nums);
        sumdiff(index + 1, val - nums[index + 1], target, N, count, nums);
    }

    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int N = nums.size();
    //     int count = 0;
    //     sumdiff(0, nums[0], target, N, count, nums);
    //     sumdiff(0, -nums[0], target, N, count, nums);
    //     return count;
    // }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int N = nums.size();
        vector<unordered_map<int, int>> dp(N + 1);
        dp[0][0] = 1;

        for (int i = 0; i < N; i++)
        {
            for (auto &it : dp[i])
            {
                dp[i + 1][it.first + nums[i]] += it.second;
                dp[i + 1][it.first - nums[i]] += it.second;
            }
        }

        return dp[N][target];
    }
};