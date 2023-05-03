// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.



class Solution {
    bool isEqual(int index, int sum1, int sum2, vector<int> &nums, int N){
        if(index+1 == N){
            if(sum1 == sum2) return true;
            return false;
        }

        if(isEqual(index+1, sum1+nums[index+1], sum2 - nums[index+1], nums, N)){
            return true;
        }
        if(isEqual(index+1, sum1, sum2, nums, N)){
            return true;
        }
        return false;
    }
public:
    // bool canPartition(vector<int>& nums) {
    //     int size = nums.size();
    //     int totalSum = 0;
    //     for(auto it : nums){
    //         totalSum += it;
    //     }
    //     int index = 0;
    //     if(isEqual(index, nums[index], totalSum - nums[index], nums, size)){
    //         return true;
    //     }
    //     if(isEqual(index, 0, totalSum, nums, size)){
    //         return true;
    //     }
    //     return false;
    // }

    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        int totalSum = 0;
        for(auto it : nums){
            totalSum += it;
        }
        if(totalSum%2 == 1) return false;
        vector<vector<bool>> t(size+1, vector<bool>(totalSum/2+1, false));

        for(int i=0; i<size+1; i++){
            for(int j=0; j<(totalSum/2)+1; j++){
                if(i == 0){
                    t[i][j] = false;
                }
                if(j == 0){
                    t[i][j] = true;
                }
            }
        }

        for(int i=1; i<size+1; i++){
            for(int j=1; j<(totalSum/2)+1; j++){
                if(nums[i-1] <= j){
                    t[i][j] = (t[i-1][j] || t[i-1][j-nums[i-1]]);
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        cout<<size<<" "<<totalSum/2<<" "<<endl;
        return t[size][totalSum/2];
    }
};