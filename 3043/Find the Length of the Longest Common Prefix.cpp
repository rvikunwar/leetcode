// Find the Length of the Longest Common Prefix.cpp
// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/?envType=daily-question&envId=2024-09-24


class Solution {
public:
    void findPrefix(int val, set<int> &st) {
        while(val > 0)  {
            st.insert(val) ;
            val /= 10;
        }
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int> st;
        for(int i=0; i<arr1.size(); i++) {
            findPrefix(arr1[i], st);
        }

        int maxi = 0;

        for(int i=0; i<arr2.size(); i++) {
            int val = arr2[i];
            while(val > 0)  {
                if(st.find(val) != st.end()) {
                    maxi = max(maxi, val);
                }
                val /= 10;
            }
        }
        int ans = 0;

        while(maxi > 0) {
            ans++;
            maxi /= 10;
        }
        return ans;
    }
};