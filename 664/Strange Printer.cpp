// There is a strange printer with the following two special properties:

// The printer can only print a sequence of the same character each time.
// At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
// Given a string s, return the minimum number of turns the printer needed to print it.

class Solution
{
public:
    int findMinimumTurns(int i, int j, string &s, vector<vector<int>> &dp)
    {

        if (i == j)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int minTurns = 1e9;
        for (int k = i; k < j; k++)
        {
            minTurns = min(minTurns, findMinimumTurns(i, k, s, dp) + findMinimumTurns(k + 1, j, s, dp));
        }

        if (s[i] == s[j])
            minTurns--;

        return dp[i][j] = minTurns;
    }

    int strangePrinter(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        vector<vector<int>> dp(j + 1, vector<int>(j + 1, -1));
        return findMinimumTurns(i, j, s, dp);
    }
};