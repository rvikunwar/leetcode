class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int low, high;
        int a ;
        vector<vector<int>> res;
        
        for(int i=0; i< nums.size(); i++){
            a = 0-nums[i];
            low = i+1;
            high = nums.size()-1;
            
            if( (i>0 && a == 0-nums[i-1]) || i>=nums.size()-2){
                break;
            }

            while(low<high){
                int sum = (nums[low]+nums[high]);
                if(sum == a){
                    vector<int> vc{-a, nums[low], nums[high]};
                    res.push_back(vc);
                    while(low<high && nums[low] == nums[low+1]) low++;
                    while(low<high && nums[high] == nums[high-1]) high--;
                    low++;
                    high--;

                }
                else if( sum < a){
                    low++;
                } else {
                    high --;
                }   
            }
        }
        
        return res;
    }
};
