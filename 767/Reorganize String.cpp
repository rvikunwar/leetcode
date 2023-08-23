// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.

 

// Example 1:

// Input: s = "aab"
// Output: "aba"
// Example 2:

// Input: s = "aaab"
// Output: ""
 

// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters.

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        int size = s.size();

        for(auto it: s){
            mp[it]++;
            if(size%2 == 0 && mp[it] > size/2) return ""; 
            if(mp[it] > (size/2+1)) return "";
        }

        for(auto it: mp){
            pq.push({ it.second, it.first });
        }

        string value = "";
        while(pq.size() > 1){
            auto pr1 = pq.top();
            pq.pop();
            auto pr2 = pq.top();
            pq.pop();
            mp[pr1.second]--;
            mp[pr2.second]--;
            value += pr1.second;
            value += pr2.second;
            if(mp[pr1.second] != 0){
                pq.push({mp[pr1.second], pr1.second});
            }

            if(mp[pr2.second] != 0){
                pq.push({mp[pr2.second], pr2.second});
            }
        }

        if(pq.size() == 1){
            value += pq.top().second;
        }

        return value;
    }
};