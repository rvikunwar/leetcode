// Divide Intervals Into Minimum Number of Groups.cpp
// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/

class Solution {
public:
    int minGroups(vector<vector<int>>& \intervals) {
        map<int, int> mp;

        for(int i=0; i<intervals.size(); i++) {
            int s =  intervals[i][0];
            int e = intervals[i][1];
            mp[s]++;
            mp[e+1]--;
        } 


        int count = 0;
        int ans = 0; 
        for(auto &it: mp) {
            count += it.second;
            ans = max(ans, count); 
        }

        return ans;
    }
};

