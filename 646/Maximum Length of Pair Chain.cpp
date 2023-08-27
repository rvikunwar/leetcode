// You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

// A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

// Return the length longest chain which can be formed.

// You do not need to use up all the given intervals. You can select pairs in any order.

class Solution
{
public:
    static bool compareFirstColumn(const vector<int> &vc1, const vector<int> &vc2)
    {
        if (vc1[1] < vc2[1])
            return true;
        return false;
    }
    // int findLongestChain(vector<vector<int>>& pairs) {
    //     sort(pairs.begin(), pairs.end(), compareFirstColumn);
    //     int ans = 1;
    //     int currentMax = pairs[0][1];
    //     for(int i=1; i<pairs.size(); i++){
    //         if(currentMax < pairs[i][0]){
    //             ans++;
    //             currentMax = pairs[i][1];
    //         }
    //     }
    //     return ans;
    // }

    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), compareFirstColumn);
        int size = pairs.size();
        vector<int> dp(size, 1);
        int ans = 1;
        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs[i][0] > pairs[j][1])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
                else
                {
                    dp[i] = max(dp[i], dp[j]);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};