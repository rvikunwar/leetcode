// Divide Players Into Teams of Equal Skill.cpp
// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/


typedef long long ll;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<int, int> mp;
        int n = skill.size();
        int sum = 0;
        for(auto it: skill) {
            sum += it;
        }
        sum = (sum/(n/2));

        ll ans = 0;
        int p = 0;
        for(auto it: skill) {
            int diff = sum - it;
            if(mp.find(diff) != mp.end() && mp[diff] > 0) {
                ans += ((ll)it*(ll)diff);
                mp[diff]--;
                p++;
            } else {
                mp[it]++;
            }
        }

        return p == (n/2) ? ans: -1;
    }
};

