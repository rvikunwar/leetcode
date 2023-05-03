// Leetcode -  You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

 

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2

// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;

        while(start<=end){
            int mid = start + (end - start)/2;
            int prev = mid - 1;
            int next = mid+1;
            int count = 1;
            if(prev >= start && nums[prev] == nums[mid]){
                if((end - mid) % 2 != 0 ){
                    start = mid+1; 
                } else {
                    end = mid;
                }
                count++;
            } else if(next <= end &&  nums[next] == nums[mid]){
                if((end - mid + 1) % 2 != 0 ){
                    start = mid; 
                } else {
                    end = mid -1;
                }
                count++;
            }
            if(count == 1) return nums[mid];
        }

        return -1;
    } 
};