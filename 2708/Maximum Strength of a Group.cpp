// You are given a 0-indexed integer array nums representing the score of students in an exam. The teacher would like to form one non-empty group of students with maximal strength, where the strength of a group of students of indices i0, i1, i2, ... , ik is defined as nums[i0] * nums[i1] * nums[i2] * ... * nums[ik​].

// Return the maximum strength of a group the teacher can create.

 

// Example 1:

// Input: nums = [3,-1,-5,2,5,-9]
// Output: 1350
// Explanation: One way to form a group of maximal strength is to group the students at indices [0,2,3,4,5]. Their strength is 3 * (-5) * 2 * 5 * (-9) = 1350, which we can show is optimal.
// Example 2:

// Input: nums = [-4,-5,-4]
// Output: 20
// Explanation: Group the students at indices [0, 1] . Then, we’ll have a resulting strength of 20. We cannot achieve greater strength.
 

// Constraints:

// 1 <= nums.length <= 13
// -9 <= nums[i] <= 9

// https://leetcode.com/problems/maximum-strength-of-a-group/description/

class Solution {
    
public:
    long long maxStrength(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int max_neg = INT_MIN;
        int count_neg = 0, count_zero = 0;
        long long prod = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count_zero++;
                continue;
            }

            if (nums[i] < 0) {
                count_neg++;
                max_neg = max(max_neg, nums[i]);
            }

            prod = prod * nums[i];
        }

        if (count_zero == nums.size())
            return 0;

        if (count_neg & 1) {

            if (count_neg == 1 &&
                count_zero > 0 &&
                count_zero + count_neg == nums.size())
                return 0;

            prod = prod / max_neg;
        }

        return prod;
    }
};


class Solution {

    int maxProduct(int val, int index, vector<int> &nums){
        if(index == nums.size()) return val;
        return max(maxProduct(val*nums[index], index+1, nums), maxProduct(val, index+1, nums));
    }
    
public:
    long long maxStrength(vector<int>& nums) {
        
        int ans1 = maxProduct(nums[0], 1, nums);
        int ans2 = maxProduct(1, 1, nums);
        return max(ans1, ans2);
    }
};