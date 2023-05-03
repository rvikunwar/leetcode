// You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

// Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.

 

// Example 1:

// Input: salary = [4000,3000,1000,2000]
// Output: 2500.00000
// Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
// Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500

class Solution {
public:
    double average(vector<int>& salary) {
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        double sum = 0;

        for(auto it: salary){
            maximum = max(it, maximum);
            minimum = min(it, minimum);
            sum += it;
        }

        return (sum-maximum-minimum)/(salary.size() - 2);
    }
};