// Given an integer array nums of unique elements, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

class Solution {
    void subset(int index, vector<int> vc, vector<vector<int>> &ans, vector<int>& nums){
        if(index == nums.size()){
            ans.push_back(vc);
            return;
        }
        
        subset(index+1, vc, ans, nums);
        vc.push_back(nums[index]);
        subset(index+1, vc, ans, nums);  
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 1) return  { {} ,nums };
        vector<vector<int>> ans;
        vector<int> vc;
        subset(0, vc, ans, nums);
        return ans;
    }
};