// Count of Substrings Containing Every Vowel and K Consonants II.cpp
// https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/

typedef long long ll;
class Solution {
public:
    unordered_map<int, int> mp;
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }

    bool isConditionSatisfied(int k) {
        if(mp['k'] == k && mp['a'] > 0 && mp['e'] > 0 && mp['i'] > 0 && mp['o'] > 0 && mp['u'] > 0) return true;
        return false;
    }

    void update(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            mp[ch]++;
        } else {
            mp['k']++;
        }
    }

    void remove(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            mp[ch]--;
        } else {
            mp['k']--;
        }
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        vector<ll> pre(n, n);

        int last = n;
        for(int i=n-1; i>=0; i--) {
            pre[i] = last;
            if(!isVowel(word[i])) last = i;
        }


        int i = 0;
        int j = 0;
        ll ans = 0;
        while(j < n) {
            while(mp['k'] > k) {
                remove(word[i]);
                i++;
            }
            if(isConditionSatisfied(k)) {
                ans += (pre[j-1] - j + 1);
                remove(word[i]);
                i++;
            } else {
                update(word[j]);
                j++;
            }
        }

        while(i < n && isConditionSatisfied(k)) {
            ans++;
            remove(word[i]);
            i++;
        }

        return ans;
    }
};
