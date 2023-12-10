// You are given an array of binary strings strs and two integers m and n.

// Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

// A set x is a subset of a set y if all elements of x are also elements of y.


class Solution {
public:
    void countOneAndZero(vector<int> &v0, vector<int> &v1, string str, int index) {
        int zeros = 0;
        int ones = 0;
        int size = str.size();
        for(int i=0; i<size; i++){
            if(str[i] == '0'){
                zeros++;
            } else {
                ones++;
            }
        }
        cout<<zeros<<" "<<ones<<endl;
        v0[index] = zeros;
        v1[index] = ones;
    }

    int findSubsetCount(int index, int m, int n, vector<int> &v0, vector<int> & v1, unordered_map<string ,int> &mp){
        int zeros = v0[index];
        int ones = v1[index];
        if(index == v1.size() - 1){
            if(m >= zeros && n >= ones) {
                return 1;
            } else {
                return 0;
            }
        }

        string dpField = to_string(m) + "_" + to_string(n) + "_" + to_string(index);
        if(mp.find(dpField) != mp.end()){
            return mp[dpField];
        }

        if(m < zeros || n < ones){
            return mp[dpField] = findSubsetCount(index+1, m , n, v0, v1, mp);
        }
        
        return mp[dpField] = max(1+findSubsetCount(index+1, m-zeros, n-ones, v0, v1, mp), 
            findSubsetCount(index+1, m, n, v0, v1, mp));
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<int> v0(size, 0);
        vector<int> v1(size, 0);

        unordered_map<string ,int> mp;
        for(int i=0; i<size; i++){
            countOneAndZero(v0, v1, strs[i], i);
        }

        return findSubsetCount(0, m, n, v0, v1, mp);

    }
};