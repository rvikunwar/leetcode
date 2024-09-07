// Find Missing Observations.cpp

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = (n+m)*mean;

        int sum = 0;
        for(auto it: rolls) {
            sum += it;
        }

        int x = total - sum;

        if(x > n*6 || x < n) {
            return {};
        }

        vector<int> ans(n, 0);

        int p = (x/n);
        int i = 0;
        int extra = x % n;
        while(i < n) {
            ans[i] = p + (extra > 0 ? 1: 0);
            extra--;
            i++;
        }

        return ans;
    }
};