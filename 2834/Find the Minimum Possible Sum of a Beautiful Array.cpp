// You are given positive integers n and target.

// An array nums is beautiful if it meets the following conditions:

// nums.length == n.
// nums consists of pairwise distinct positive integers.
// There doesn't exist two distinct indices, i and j, in the range [0, n - 1], such that nums[i] + nums[j] == target.
// Return the minimum possible sum that a beautiful array could have.

 
//  Input: n = 2, target = 3
// Output: 4
// Explanation: We can see that nums = [1,3] is beautiful.
// - The array nums has length n = 2.
// - The array nums consists of pairwise distinct positive integers.
// - There doesn't exist two distinct indices, i and j, with nums[i] + nums[j] == 3.
// It can be proven that 4 is the minimum possible sum that a beautiful array could have.

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        unordered_set<int> st;
        int length = 0;
        long long sum = 0;
        int first = 1;
        while(length != n){
            if(st.find(first) != st.end()){
                first++;
                continue;
            }
            sum += first;
            int diff = target - first;
            st.insert(diff);
            first++;
            length++;
        }
        return sum;
    }
};