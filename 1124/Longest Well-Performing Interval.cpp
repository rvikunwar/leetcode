class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int,int> mp;
        
        int result = 0, sum = 0;
        
        for(int i=0; i<hours.size(); i++){
            sum += hours[i]>8?1:-1;
            
            if(sum>0){
                result = i+1;
            }
            else {
                if(mp.find(sum-1) != mp.end()){
                    result = max(result, i-mp[sum-1]);
                }
            }
            
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        
        return result;
    }
};
