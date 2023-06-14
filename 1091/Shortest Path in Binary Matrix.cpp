// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

#define pr pair<int, int>
class Solution
{

    bool isValid(int i, int j, int rows, int cols)
    {
        if (i < 0 || j < 0 || i >= rows || j >= cols)
            return false;
        return true;
    }

private:
    int dijkstra(int n, vector<vector<int>> &dist, vector<vector<int>> &grid)
    {
        queue<pair<int, pr>> q;
        dist[0][0] = 1;
        q.push({1, {0, 0}});

        int delRow[] = {1, 1, 0, -1, -1, -1, 0, 1};
        int delCol[] = {0, -1, -1, -1, 0, 1, 1, 1};

        while (!q.empty())
        {
            pair<int, pr> p = q.front();
            q.pop();
            int dis = p.first;
            int i = p.second.first;
            int j = p.second.second;

            for (int k = 0; k < 8; k++)
            {
                int newRow = i + delRow[k];
                int newCol = j + delCol[k];
                if (isValid(newRow, newCol, n, n) && grid[newRow][newCol] == 0)
                {
                    if (dis + 1 < dist[newRow][newCol])
                    {
                        if (newRow == n - 1 && newCol == n - 1)
                            return dis + 1;
                        q.push({dis + 1, {newRow, newCol}});
                        dist[newRow][newCol] = dis + 1;
                    }
                }
            }
        }
        return -1;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[n - 1][n - 1] == 1 || grid[0][0] == 1)
            return -1;
        if (n == 1)
            return 1;

        vector<vector<int>> dist(n, vector<int>(n, 10001));
        return dijkstra(n, dist, grid);
    }
};