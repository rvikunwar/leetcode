class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        set<int> index;
        unordered_map<int, int> mp;
        vector<int> ans(n, -1);
            
        for(int i=0; i<n; i++){
            if(rains[i]>0){
               if(mp.find(rains[i]) != mp.end()){
                    auto it = index.upper_bound(mp[rains[i]]);
                    if(it == index.end()){
                        return vector<int> {};
                    }
                   ans[*it] = rains[i];
                   index.erase(it);
                }
            } else {
                index.insert(i);
            }
            mp[rains[i]] = i;
        }
        
        for(int i=0; i< n;i++){
            if(rains[i]==0 && ans[i]==-1){
                ans[i] = 1;
            }
        }
        return ans;
    }
};
