// Minimum Time Difference.cpp
// https://leetcode.com/problems/minimum-time-difference/

class Solution {
public:

    int parse(string s) {
        int h = 0;
        int m = 0;
        h += (s[0] - '0')*10;
        h += (s[1] - '0');

        m += (s[3] - '0')*10;
        m += (s[4] - '0');
        return (h)*60 + m;
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int> vc;
        for(auto it: timePoints) {
            vc.push_back(parse(it));
        } 

        sort(vc.begin(), vc.end());

        int diff = INT_MAX;
        int i=0;
        int j=1;
        int n = vc.size();
        while(j < n) {
            diff = min(diff, (vc[j] - vc[i]));
            i++;
            j++;
        }
        diff = min(diff, 1440 - vc[n-1] + vc[0]);
        return diff;
    }
};