// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

# include<bits/stdc++.h>

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int zeroPos = -1;

        int pos1 = 0;
        int pos2 = 0;
        int size = nums.size();
        int maxCount = 0;
        while (pos2 < size)
        {
            if (nums[pos2] == 0)
            {
                if (zeroPos == -1)
                {
                    zeroPos = pos2;
                }
                else
                {
                    maxCount = max(maxCount, pos2 - pos1 - 1);
                    pos1 = zeroPos + 1;
                    zeroPos = pos2;
                }
            }
            pos2++;
        }
        maxCount = max(maxCount, pos2 - pos1 - 1);

        return maxCount == 0 ? 0 : maxCount;
    }
};