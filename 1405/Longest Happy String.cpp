// Longest Happy String.cpp
// https://leetcode.com/problems/longest-happy-string/description/?envType=daily-question&envId=2024-10-16


typedef long long ll;
typedef pair<int, int> pii;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pii> pq;
        if(a > 0) pq.push({ a, 0 });
        if(b > 0) pq.push({ b, 1 });
        if(c > 0) pq.push({ c, 2 });

        string s = "";
        int i = 0;

        // Run this loop until the point where priority queue gets empty 
        // or it violates three contiguous same character condition (aaa, bbb, ccc)
        while(!pq.empty()) {
            // If last two characters are same 
            // and current character with highest count is also 
            // same as the last one, then  
            // take the second highest count character if available
            // If not available - break the code;
            // there is no point in going ahead.
            pii top = pq.top();
            pq.pop();
            if(i >= 2 && s[i-1] == s[i-2] && top.second == (s[i-1] - 'a')) {
                if(pq.empty()) {
                    break;
                }
                pii top_second = pq.top();
                s += ('a' + top_second.second);
                pq.pop();
                top_second.first--;
                if(top_second.first != 0) {
                    pq.push(top_second);
                }
            } else {
                // simply take character with highest count
                s += ('a' + top.second);
                top.first--;
            }

            // comparing with zero is must otherwise it will turn
            // into infinite loop
            if(top.first != 0) {
                pq.push(top);
            }
            i++;
        }

        return s;
    }
};

