// Make Sum Divisible by P.cpp
// https://leetcode.com/problems/make-sum-divisible-by-p/


typedef long long ll;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        ll sum = 0;
        for(int i=0; i<n; i++) {
            nums[i] = nums[i]%p;
            sum += nums[i];
        }

        ll rem = sum%p;
        unordered_map<ll, int> mp;
        int ans = n;
        mp[0] = 0;
        ll tmp = 0;
        for(int i=1; i<n+1; i++) {
            tmp = (tmp + nums[i-1] + p)%p;
            mp[tmp] = i;
            ll rest = ( tmp - rem + p )% p;
            if(mp.find(rest) != mp.end()) {
                ans = min(ans, i - mp[rest]);
            }
        }

        return (ans == n) ? -1: ans;

    }
};
