// You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:

// nums.length == n
// nums[i] is a positive integer where 0 <= i < n.
// abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
// The sum of all the elements of nums does not exceed maxSum.
// nums[index] is maximized.
// Return nums[index] of the constructed array.

// Note that abs(x) equals x if x >= 0, and -x otherwise.

 

// Example 1:

// Input: n = 4, index = 2,  maxSum = 6
// Output: 2
// Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
// There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].
// Example 2:

// Input: n = 6, index = 1,  maxSum = 10
// Output: 3
 

// Constraints:

// 1 <= n <= maxSum <= 109
// 0 <= index < n


class Solution {
    long long preSum(long long num){
        return (num)*(num+1)/2;
    }

    long long getSum(int val , int leftItems, int rightItems){
        long long rightSum;
        long long leftSum;
        if(val - 1 >= rightItems){
            rightSum = preSum(val-1) - preSum(val-rightItems-1);
        } else {
            rightSum = preSum(val-1) + (rightItems - (val-1));
        }

        if(val - 1 >= leftItems){
            leftSum = preSum(val-1) - preSum(val-leftItems-1);
        } else {
            leftSum = preSum(val-1) + (leftItems - (val-1));
        }

        long long total = leftSum + rightSum + val; 
        return total;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        if(n == 1) return maxSum;
        if(n == 2 && maxSum%2 == 0) return (maxSum/2);
        if(n == 2 && maxSum%2 == 1) return (maxSum/2) + 1;
        int val = maxSum;
        int leftItems = index;
        int rightItems = n - index - 1;


        int left = 1;
        int right = val;
        int res = val;
        while(right>=left){
            int mid = left + (right-left)/2;
            long long sum = getSum(mid, leftItems, rightItems);
            if(sum <= maxSum){
                left = mid+1;
                res = mid;
            } 
            else right = mid-1;
        }
        return res;
    }
};