// Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

// answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
// answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
// Note that the integers in the lists may be returned in any order.

 

// Example 1:

// Input: nums1 = [1,2,3], nums2 = [2,4,6]
// Output: [[1,3],[4,6]]
// Explanation:
// For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
// For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].

// https://leetcode.com/problems/find-the-difference-of-two-arrays/description/


class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, bool> mp1;
        unordered_map<int, bool> mp2;
        vector<int> vc1;
        vector<int> vc2;

        for (auto it : nums1)
        {
            mp1[it] = true;
        }

        for (auto it : nums2)
        {
            if (mp1.find(it) == mp1.end())
            {
                vc2.push_back(it);
                mp1[it] = true;
            }
            mp2[it] = true;
        }

        for (auto it : nums1)
        {
            if (mp2.find(it) == mp2.end())
            {
                vc1.push_back(it);
                mp2[it] = true;
            }
        }

        return {vc1, vc2};
    }
};