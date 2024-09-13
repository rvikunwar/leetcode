// XOR Queries of a Subarray.cpp
// https://leetcode.com/problems/xor-queries-of-a-subarray/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> prefix_xor(n+1, 0);

        int i = 1;
        while(i <= n) {
            prefix_xor[i] = (prefix_xor[i-1] ^ arr[i-1]);
            i++;
        }

        int q_size = queries.size();
        vector<int> ans(q_size, 0);

        for(int i=0; i<q_size; i++) {
            int k = queries[i][0];
            int l = queries[i][1];

            int val = prefix_xor[l+1] ^ prefix_xor[k];
            ans[i] = (val);
        }

        return ans;
    }
};
