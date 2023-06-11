// You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

// Return the minimum number of extra characters left over if you break up s optimally.

// Example 1:

// Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
// Output: 1
// Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

// Example 2:

// Input: s = "sayhelloworld", dictionary = ["hello","world"]
// Output: 3
// Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.

// Constraints:

// 1 <= s.length <= 50
// 1 <= dictionary.length <= 50
// 1 <= dictionary[i].length <= 50
// dictionary[i] and s consists of only lowercase English letters
// dictionary contains distinct words

class Solution
{
    int checkForWord(int index, string s, unordered_map<string, bool> &mp, vector<int> &dp)
    {
        if (index >= s.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int mini = 100;
        for (int i = index; i < s.size(); i++)
        {
            int count;
            string substr = s.substr(index, i - index + 1);
            if (mp.find(substr) == mp.end())
            {
                count = (i - index + 1) + checkForWord(i + 1, s, mp, dp);
            }
            else
            {
                count = checkForWord(i + 1, s, mp, dp);
            }
            mini = min(mini, count);
        }
        return dp[index] = mini;
    }

public:
    // int minExtraChar(string s, vector<string>& dictionary) {
    //     unordered_map<string, bool> mp;
    //     for(int i=0; i<dictionary.size(); i++){
    //         mp[dictionary[i]] = true;
    //     }

    //     int n = s.size();
    //     vector<int> dp(n+1, -1);
    //     return checkForWord(0, s, mp, dp);
    // }

    int minExtraChar(string s, vector<string> &dictionary)
    {
        unordered_map<string, bool> mp;
        for (int i = 0; i < dictionary.size(); i++)
        {
            mp[dictionary[i]] = true;
        }

        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0;

        for (int index = n - 1; index >= 0; index--)
        {
            int mini = 100;
            for (int k = index; k < n; k++)
            {
                int count;
                string substr = s.substr(index, k - index + 1);
                if (mp.find(substr) == mp.end())
                {
                    count = (k - index + 1) + dp[index + 1];
                }
                else
                {
                    count = dp[k + 1];
                }
                mini = min(mini, count);
            }
            dp[index] = mini;
        }
        return dp[0];
    }
};