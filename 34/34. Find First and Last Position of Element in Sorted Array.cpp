// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.


// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]


class Solution {
public:

    int binarySearch(vector<int>& nums, int target, bool param) {
        int left = 0;
        int right = nums.size()-1;
        int ans = -1;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(nums[mid] == target){
                if(param == true){
                    if(mid != 0 && nums[mid-1] == target) {
                        right = mid-1; 
                    } else {
                        ans = mid;
                        left = mid + 1;
                    }
                } else {
                    if(mid != nums.size() - 1 && nums[mid+1] == target) {
                        left = mid+1; 
                    } else {
                        ans = mid;
                        right = mid - 1;
                    }
                }
            } else if(nums[mid] < target){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        int last = binarySearch(nums, target, false);

        if(first == -1 && last == -1){
            return {-1, -1};
        }
        else if(first != -1 && last != -1){
            return {first, last};
        } 
        else if(first != -1){
            return {first, first};
        } 
        return {last, last};
    }
};

