// Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size = arr.size();
        int forth = (size/4)+1;
        cout<<forth<<endl;
        unordered_map<int, int> mp;

        for(int i=0; i<size; i++){
            int value = arr[i];
            if(mp.find(value) == mp.end()){
                mp[value] = 1;
            } else {
                mp[value]++;
            }
            if(mp[value] >= forth){
                return value;
            }
        }
        return -1;
    }
};