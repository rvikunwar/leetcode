// Given a 0-indexed integer array nums of length n and an integer target, return the number of pairs (i, j) where 0 <= i < j < n and nums[i] + nums[j] < target.

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> vc;
        int ans = 0;
        
        for(int i=0; i<size; i++){
            int diff = target - (nums[i]);
            for(int j=0; j<vc.size(); j++){
                if(vc[j] > nums[i]) {
                    ans++;
                }
            }
            vc.push_back(diff);
        }
        
        return ans;
    }
};