class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int count = 1;
        for(int j =1; j<nums.size();j++){
            cout<<j<<"aaa"<<i<<"gg"<<count<<endl;
            if(count == 2){
                while(j<nums.size() && nums[i]==nums[j]){
                    j++;
                }
                if(j<nums.size()){
                    nums[++i] = nums[j];
                }
                                
                count = 1;
            }
            
            else if(nums[i] != nums[j]){
                nums[++i] = nums[j];
                count = 1;
            } else {
                nums[++i] = nums[j];
                count++;
            }
        }
        
        return ++i;
    }
};
