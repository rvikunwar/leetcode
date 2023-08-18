// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

class Solution
{
public:
    bool isValid(int newRow, int newCol, int rows, int cols)
    {
        if (newRow >= rows || newCol >= cols || newRow < 0 || newCol < 0)
            return false;
        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, 0));

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            pair<int, int> position = q.front().first;
            int value = q.front().second;
            q.pop();
            mat[position.first][position.second] = value;

            for (int i = 0; i < 4; i++)
            {
                int newRow = delRow[i] + position.first;
                int newCol = delCol[i] + position.second;
                if (isValid(newRow, newCol, m, n) && vis[newRow][newCol] == 0)
                {
                    q.push({{newRow, newCol}, value + 1});
                    vis[newRow][newCol] = 1;
                }
            }
        }
        return mat;
    }
};