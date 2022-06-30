class Solution {
public:
    vector<string> split(string s){
        string t="";
        vector<string> vc;
        
        for(int i=0; i<s.size(); i++){
            if(s[i] != ','){
                t += s[i];
            } else {
                vc.emplace_back(t);
                t = "";
            }
        }
        if(t.size()>0){
            vc.emplace_back(t);
        }
        return vc;
    }
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, vector<vector<string>>> mp;
        int n = transactions.size();
        vector<string> tc;
        
        for(int i=0; i<n; i++){
            vector<string> vc = split(transactions[i]);
            mp[vc[0]].push_back(vc);
        }
        
         for(int i=0; i<n; i++){
            vector<string> vc = split(transactions[i]);
            
            if(stoi(vc[2]) > 1000){
                tc.emplace_back(transactions[i]);   
                continue;
            }
             
            if(mp.find(vc[0]) != mp.end()){
                for(auto it: mp[vc[0]]){
                    if(abs(stoi(vc[1]) - stoi(it[1])) <= 60 && it[3]!=vc[3]){
                        tc.emplace_back(transactions[i]);
                        break;
                    }
                }    
            }
        }
        
        
        return tc;
    }
};
