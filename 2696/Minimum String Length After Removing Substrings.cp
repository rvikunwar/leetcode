// Minimum String Length After Removing Substrings.cpp
// https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/

// Don't use s[i] + s[i+1] for concatenating two chars
// this will add numerical values
// s.substr(position, length) -> this can be used . . . 
// and for removing s.erase(position, length)/by reference . . .
// also don't use to_string(character) -> this will update character to number 
class Solution {
public:
    int minLength(string s) {
        int i = 0;
        int n = s.size();
        while(i+1 < n) {
            string cur = s.substr(i, 2);
            if(cur == "AB" || cur == "CD") {
                s.erase(i, 2);
                i--;
            } else {
                i++;
            }
            n = s.size();
            i = max(0, i);
        }

        return s.size();
    }
};