// Walking Robot Simulation.cpp

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
        int y = 0;
        int dx = 0;
        int dy = 1;

        vector<int> a = {-10, -7, -6, 1, 4};

        unordered_map<int, set<int>> x_set, y_set;

        for(int i=0; i<obstacles.size(); i++) {
            int x_ = obstacles[i][0];
            int y_ = obstacles[i][1];
            x_set[x_].insert(y_);
            y_set[y_].insert(x_);
        }

        int distance  = 0;

        for(auto it: commands) {
            if(it > 0) {
                if(dy == 0) {
                    if(dx > 0) {
                        auto obs = upper_bound(y_set[y].begin(), y_set[y].end(), x);
                        if(obs != y_set[y].end() && *obs <= (x + it)) {
                            x = *obs - 1; 
                        } else{
                            x += (dx*it);
                        }
                    } else {
                        auto obs = upper_bound(y_set[y].rbegin(), y_set[y].rend(), x, greater<>());
                        if(obs != y_set[y].rend() && *obs >= (x - it)) {
                            x = *obs + 1; 
                        } else{
                            x += (dx*it);
                        }
                    }
                } else {
                    if(dy > 0) {
                        auto obs = upper_bound(x_set[x].begin(), x_set[x].end(), y);
                        if(obs != x_set[x].end() && *obs <= (y + it)) {
                            y = *obs - 1; 
                        } else{
                            y += (dy*it);
                        }
                    } else {
                        auto obs = upper_bound(x_set[x].rbegin(), x_set[x].rend(), y, greater<>());
                        if(obs != x_set[x].rend() && *obs >= (y - it)) {
                            y = *obs + 1; 
                        } else{
                            y += (dy*it);
                        }
                    }
                }
                distance  = max(distance, x*x + y*y);
            } else {
                if(dy == 0) {
                    if(dx == -1) {
                        dy = (it == -1) ? 1: -1;
                    } else {
                        dy = (it == -1) ? -1: 1;
                    }
                    dx = 0;
                } else {
                    if(dy == -1) {
                        dx = (it == -1) ? -1: 1;
                    } else {
                        dx = (it == -1) ? 1: -1;
                    }
                    dy = 0;
                }
            }
        }

        
        return distance;
    }
};

