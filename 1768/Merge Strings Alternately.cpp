// You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
// Return the merged string.

// https://leetcode.com/problems/merge-strings-alternately/description/


class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string s = "";
        int length = min(word1.size(), word2.size());
        int i = 0;
        while (i < length)
        {
            s += word1[i];
            s += word2[i];
            i++;
        }

        while (i < word1.size())
        {
            s += word1[i];
            i++;
        }

        while (i < word2.size())
        {
            s += word2[i];
            i++;
        }
        return s;
    }
};