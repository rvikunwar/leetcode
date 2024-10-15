// Maximal Score After Applying K Operations.cpp
// https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/


typedef long long ll;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(const auto &it: nums) {
            pq.push(it);
        }
        ll ans = 0;
        while(k--) {
            int top_val = pq.top();
            pq.pop();
            ans += (ll)top_val;
            top_val = ceil((double)top_val/3.0);
            pq.push(top_val);
        }

        return ans;
    }
};
