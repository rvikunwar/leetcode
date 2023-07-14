// Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

// A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: arr = [1,2,3,4], difference = 1
// Output: 4
// Explanation: The longest arithmetic subsequence is [1,2,3,4].

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        unordered_map<int,int> lengths;
        int result=1;
        for(int &i:arr)
            result=max(result,lengths[i]=1+lengths[i-difference]); //Length of AP ending with 'i' with difference of 'difference' will be 1 + length of AP ending with 'i-difference'. result stores Max at each end
        return result;
    }
};