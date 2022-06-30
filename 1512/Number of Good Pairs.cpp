class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int res = 0;
        
        for(int i=0; i<n; i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = 1;
            } else {
                res += mp[nums[i]];
                mp[nums[i]]++;
            }
        }
        
        return res;
    }
};
