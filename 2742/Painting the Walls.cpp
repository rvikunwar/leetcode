// Painting the Walls.cpp
// https://leetcode.com/problems/painting-the-walls/description/?envType=problem-list-v2&envId=dynamic-programming&difficulty=HARD

int int_max = 1e9;
typedef pair<int, int> pii;
class Solution {
public:
    vector<int> cost_;
    vector<int> time_;
    int n_;
    int f(int index, int tr, map<pii, int> &dp) {
        if(tr >= 0) return 0;
        if(index >= n_) return int_max;

        if(dp.find({index, tr}) != dp.end()) return dp[{index, tr}];

        int ans = min(cost_[index] + f(index+1, tr + 1 + time_[index], dp), f(index+1, tr, dp));
        return dp[{index, tr}] = ans;
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        cost_ = cost;
        time_ = time;
        n_ = cost.size();
        map<pii, int> dp;
        return f(0, -1*n_, dp);
    }
};

