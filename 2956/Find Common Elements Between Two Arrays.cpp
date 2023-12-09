// You are given two 0-indexed integer arrays nums1 and nums2 of sizes n and m, respectively.

// Consider calculating the following values:

// The number of indices i such that 0 <= i < n and nums1[i] occurs at least once in nums2.
// The number of indices i such that 0 <= i < m and nums2[i] occurs at least once in nums1.
// Return an integer array answer of size 2 containing the two values in the above order.


class Solution {
public:
    
    int findCommon(unordered_map <int, bool> &mp, vector<int>& nums) {
        int k = 0;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()) {
                k++;
            }
        }
        return k;
    }
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int, bool> mp1;
        unordered_map <int, bool> mp2;
        int n = nums1.size();
        int m = nums2.size();
        for(int i=0; i<n; i++){
            mp1[nums1[i]] = true;
        }
        for(int i=0; i<m; i++){
            mp2[nums2[i]] = true;
        }
        
        vector<int> ans(2, 0);
        
        ans[0] = findCommon(mp2, nums1);
        ans[1] = findCommon(mp1, nums2);

        return ans;
    }
};