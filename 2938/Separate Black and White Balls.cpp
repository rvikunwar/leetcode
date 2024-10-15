// Separate Black and White Balls.cpp
// https://leetcode.com/problems/separate-black-and-white-balls/description/?envType=daily-question&envId=2024-10-15

typedef long long ll;
class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();

        ll swapsR = 0;
        int zeros = 0;
        for(int i=n; i>=1; i--) {
            if(s[i-1] == '1') {
                swapsR += zeros;
            } else {
                zeros++;
            }
        }

        return swapsR;
    }
};

