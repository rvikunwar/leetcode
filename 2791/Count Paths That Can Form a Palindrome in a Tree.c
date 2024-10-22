// Count Paths That Can Form a Palindrome in a Tree.cpp
// https://leetcode.com/problems/count-paths-that-can-form-a-palindrome-in-a-tree/description/

typedef long long ll;
class Solution {
public:

    ll f(int node, int mask, map<int, int> &have, string &s, vector<vector<int>> &graph) {

        ll res = 0;
        if(node) {
            mask = (mask ^ 1 << s[node] - 'a');
            for(int j=25; j>=0; j--) {
                int i = 1 << j;
                if(have.find(mask ^ i) != have.end()) {
                    res += have[mask ^ i];
                }
            }
            res += have[mask];
            have[mask]++;
        }

        for(auto it: graph[node]) {
            res += f(it, mask, have, s, graph);
        }

        return res;
    }

    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> graph(n);
        for(int i=0; i<parent.size(); i++) {
            int p_ = parent[i];
            if(p_ == -1) continue;
            graph[p_].push_back(i);
        }

        map<int, int> have;
        have[0] = 1;
        return f(0, 0, have, s, graph);
    }
};

