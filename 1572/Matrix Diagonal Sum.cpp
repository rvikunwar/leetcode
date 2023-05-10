// Given a square matrix mat, return the sum of the matrix diagonals.

// Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

// https://leetcode.com/problems/matrix-diagonal-sum/description/

class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {

        // side length
        int n = mat.size();

        // mid point index
        int mid = n / 2;

        // summation of diagonal element
        int summation = 0;

        for (int i = 0; i < n; i++)
        {

            // primary diagonal
            summation += mat[i][i];

            // secondary diagonal
            summation += mat[n - 1 - i][i];
        }

        if (n % 2 == 1)
        {

            // remove center element (repeated) on odd side-length case
            summation -= mat[mid][mid];
        }

        return summation;
    }
};