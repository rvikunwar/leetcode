// You are given an array of integers nums and an integer target.

// Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

 

// Example 1:

// Input: nums = [3,5,6,7], target = 9
// Output: 4
// Explanation: There are 4 subsequences that satisfy the condition.
// [3] -> Min value + max value <= target (3 + 3 <= 9)
// [3,5] -> (3 + 5 <= 9)
// [3,5,6] -> (3 + 6 <= 9)
// [3,6] -> (3 + 6 <= 9)
// Example 2:

// Input: nums = [3,3,6,8], target = 10
// Output: 6
// Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
// [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
// Example 3:

// Input: nums = [2,3,3,4,6,7], target = 12
// Output: 61
// Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
// Number of valid subsequences (63 - 2 = 61).
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 106
// 1 <= target <= 106


// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/


class Solution {
public:

    int power(long long a, int n, int mod){
        int res = 1;
        while(n){
            if(n%2 == 1){
                res = (res * a)%mod;
                n--;
            } else {
                a = (a*a)%mod; 
                n/=2;
            }
        }
        return res;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mod = 1000000007; 

        vector<int> powerArray;
        powerArray.push_back(1);
        for(int i=1; i<nums.size(); i++){
            powerArray.push_back((powerArray[i-1]*2)%mod);
        }

        int ptr1 = 0;
        int ptr2 = nums.size()-1;

        int count = 0;
        while(ptr1<=ptr2){
            if(nums[ptr1] + nums[ptr2] > target){
                ptr2--;
            } else {
                // cout<<(count + powerArray[ptr2-ptr1])<<endl;
                count = (count + powerArray[ptr2-ptr1])%mod;
                ptr1++;
            }
        }

        return count;
    }
};