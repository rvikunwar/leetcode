// Split a String Into the Max Number of Unique Substrings.cpp
// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description//


class Solution {
public:
    int f(int index, string &s, map<string, int> mp) {
        if(index == s.size()) {
            return 0;
        }

        int ans = INT_MIN;
        string currString = "";
        for(int i=index; i<s.size(); i++) {
            currString += s[i];
            if(mp.find(currString) == mp.end()) {
                mp[currString] = 1;
                ans = max(ans, 1 + f(i+1, s, mp));
                mp.erase(currString);
            }
        }

        return ans;
    }

    int maxUniqueSplit(string s) {
        map<string, int> mp;
        return f(0, s, mp);
    }
};
