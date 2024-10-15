// Smallest Range Covering Elements from K Lists.cpp
// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

int int_mini = -1e6;
int int_maxi = 1e6;
typedef pair<int, int> pii;
struct smRange {
    int left;
    int right;
    
    smRange(int l, int r) {
        left = l;
        right = r;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
        smRange rangeEntity(int_mini, int_maxi);
        int maxi = int_mini;
        int minRange = int_maxi;
        for(int i=0; i<nums.size(); i++) {
            int val = nums[i][0];
            pq.push({ val, { i, 0 } });
            maxi = max(maxi, val);
        }      

        while(!pq.empty()) {
            pair<int, pii> minEntity = pq.top();
            pq.pop();
            int row = minEntity.second.first;
            int col = minEntity.second.second;
            int minVal = minEntity.first;
            if(maxi - minVal < minRange) {
                rangeEntity.left = minVal;
                rangeEntity.right = maxi;
                minRange = maxi - minVal;
            }
            col++;
            if(col >= nums[row].size()) {
                break;
            }

            int val = nums[row][col];
            pq.push({ val, { row, col } });
            maxi = max(maxi, val);
        }

        return { rangeEntity.left, rangeEntity.right };
    }
};

