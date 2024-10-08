// Minimum Number of Swaps to Make the String Balanced.cpp
// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

class Solution {
public:
    int minSwaps(string s) {
        int ans = 0;
        int b = 0;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == ']') {
                if(b == 0) {
                    b++;
                    ans++;
                } else {
                    b--;
                }
            } else {
                b++;
            }
        }

        return ans;
    }
};
