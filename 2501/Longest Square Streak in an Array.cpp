// Longest Square Streak in an Array.cpp
// https://leetcode.com/problems/longest-square-streak-in-an-array/description/?envType=daily-question&envId=2024-10-28


typedef long long ll;
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        map<ll, int> mp;

        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]] = 1;
        }

        for(auto it=mp.rbegin(); it!=mp.rend(); it++) {
            ll sq = it->first * it->first; 
            if(mp.find(sq) != mp.end()) {
                mp[it->first] += mp[sq];
            }
        }

        int ans = 0;
        for(auto it: mp) {
            ans = max(ans, it.second);
        }

        return ans >= 2? ans: -1;
    }
};