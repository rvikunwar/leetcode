// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0;
        int right = (rows * cols) - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int valueAtMid = matrix[mid / cols][mid % cols];

            if (valueAtMid == target)
            {
                return true;
            }
            else if (valueAtMid < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return false;
    }
};