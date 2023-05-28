// Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:


// Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

// You should perform the cuts in order, you can change the order of the cuts as you wish.

// The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

// Return the minimum total cost of the cuts.

// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/


class Solution {
    int solveCost(int start, int end, vector<int> &cuts, int left, int right){
        if(left > right) return 0;
        if(dp[left][right]) return dp[left][right];
        int cost = INT_MAX;
        for(int i=left; i<=right; i++){
            int leftCost = solveCost(start, cuts[i], cuts, left, i-1);
            int rightCost = solveCost(cuts[i], end, cuts, i+1, right);
            int cur_cost = (end - start) + (leftCost + rightCost);
            cost = min(cost, cur_cost);
        }
        return dp[left][right] = cost;
    }
public:
    int dp[101][101];

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());

        for(int i=0; i<101; i++){
            for(int j=0; j<101; j++){
                dp[i][j] = 0;
            }
        }
        return solveCost(0, n, cuts, 0, cuts.size()-1);
    }
};