// Count Substrings That Can Be Rearranged to Contain a String I.cpp
typedef long long ll;

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> comp(26, 0);

        for(int i=0; i<word2.size(); i++) {
            int chIndex = word2[i] - 'a';
            comp[chIndex]++;
        }

        int k = word2.size();

        vector<int> ch(26, 0);
        int i = 0;
        int j = 0;

        ll ans = 0;
        int n =  word1.size();
        while(j <= word1.size()) {
            if(k == 0) {
                ans += (ll)(n-j+1);
                i++;
                int chIndex = word1[i-1] - 'a';
                if(comp[chIndex]) {
                    ch[chIndex]--;
                    if(ch[chIndex] < comp[chIndex]) {
                        k++;
                    }
                }
            } else {
                if(j == word1.size()) {
                    j++;
                    continue;
                }
                int chIndex = word1[j] - 'a';
                if(comp[chIndex]) {
                    ch[chIndex]++;
                    if(ch[chIndex] <= comp[chIndex]) {
                        k--;
                    }
                }
                j++;
            }
        }

        return ans;
    }
};