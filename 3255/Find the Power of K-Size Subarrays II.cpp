// Find the Power of K-Size Subarrays II.

// You are given an array of integers nums of length n and a positive integer k.

// The power of an array is defined as:

// Its maximum element if all of its elements are consecutive and sorted in ascending order.
// -1 otherwise.
// You need to find the power of all 
// subarrays
//  of nums of size k.

// Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].


class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == 1) {
            return nums;
        }
        
        int t=0;
        vector<int> results;
 
        for(int i=0; i<(k-1); i++){
            if((nums[i+1] - nums[i]) == 1) t++;
        }

        int i=1, j=k;
        while(j<n) {
            if(t == (k-1)) {
                results.push_back(nums[j-1]);
            } else {
                results.push_back(-1);
            }

            if(nums[i] - nums[i-1] == 1) {
                t--;
            }

            if(nums[j] - nums[j-1] == 1) {
                t++;
            }
            i++;
            j++;
        }

        if(t == (k-1)) {
            results.push_back(nums[n-1]);
        } else {
            results.push_back(-1);
        }
        return results;
    }
};
