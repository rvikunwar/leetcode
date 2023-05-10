// Given an m x n matrix, return all elements of the matrix in spiral order.
// https://leetcode.com/problems/spiral-matrix/description/


class Solution
{
public:
    // vector<int> spiralOrder(vector<vector<int>>& matrix) {

    //     int j=0, i=0;
    //     int colLimit, rowLimit = matrix.size()-1;
    //     int colStart = 0, rowStart=0;
    //     vector<int> vc;
    //     if(rowLimit >= 0){
    //         colLimit = matrix[i].size()-1;

    //         while(rowStart <= rowLimit && colStart <= colLimit){

    //             while(j <= colLimit && rowStart <= rowLimit && colStart <= colLimit){
    //                 vc.push_back(matrix[i][j]);
    //                 j++;
    //             }

    //             j--;
    //             rowStart += 1;
    //             i += 1;

    //             while(i <= rowLimit && rowStart <= rowLimit){
    //                 if(matrix[i][j] == 6) cout<<"1";
    //                 vc.push_back(matrix[i][j]);
    //                 i++;
    //             }

    //             i--;
    //             colLimit -= 1;
    //             j -= 1;

    //             while(j >= colStart && rowStart <= rowLimit && colStart <= colLimit){
    //             if(matrix[i][j] == 6) cout<<"2";

    //                 vc.push_back(matrix[i][j]);
    //                 j--;
    //             }
    //             j++;
    //             rowLimit -= 1;
    //             i -= 1;

    //             while(i >= rowStart && rowStart <= rowLimit && colStart <= colLimit){
    //                 if(matrix[i][j] == 6) cout<<"";

    //                 vc.push_back(matrix[i][j]);
    //                 i--;
    //             }

    //             i++;
    //             j += 1;
    //             colStart += 1;
    //         }
    //     }

    //     return vc;
    // }

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m - 1, top = 0, bottom = n - 1;
        while (ans.size() < n * m)
        {
            for (int i = left; i <= right && ans.size() < n * m; i++)
            {
                ans.push_back(matrix[top][i]);
            }

            for (int i = top + 1; i <= bottom - 1 && ans.size() < n * m; i++)
            {
                ans.push_back(matrix[i][right]);
            }

            for (int i = right; i >= left && ans.size() < n * m; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }

            for (int i = bottom - 1; i >= top + 1 && ans.size() < n * m; i--)
            {
                ans.push_back(matrix[i][left]);
            }

            left++;
            right--;
            top++;
            bottom--;
        }

        return ans;
    }
};