// There is a function signFunc(x) that returns:

// 1 if x is positive.
// -1 if x is negative.
// 0 if x is equal to 0.
// You are given an integer array nums. Let product be the product of all values in the array nums.

// Return signFunc(product).

class Solution {

public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for(auto it: nums){
            if(it<0) neg--;
            if(it==0) return 0;
        }        
        if(neg % 2 == 0) return 1;
        return -1;
    }
};