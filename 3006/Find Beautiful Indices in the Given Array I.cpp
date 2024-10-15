// Find Beautiful Indices in the Given Array I.cpp
// https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/description/


void compute_lps(string pattern, vector<int> & lps) {
    int length = 0;
    int i = 1;
    lps[0] = 0;

    while(i < pattern.size()) {
        if(pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if(length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(const string& text, const string& pattern, vector<int> &pos) {
    int n = text.size();
    int m = pattern.size();

    vector<int> lps(m);
    compute_lps(pattern, lps);

    int i = 0;
    int j = 0;

    while(i < n) {
        if(pattern[j] == text[i]) {
            i++;
            j++;
        }

        if(j == m) {
            pos.push_back(i-j);
            j = lps[j-1];
        } else if(i < n && pattern[j] != text[i]) {
            if(j != 0) {
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
}

void stringMatch(const string &s, string text, vector<int> &pos) {
    for(int i=0; i<=s.size() - text.size(); i++) {
        int count = 0;
        for(int j=0; j<text.size(); j++) {
            if(s[i + j] == text[j]) {
                count++;
            } else {
                break;
            }
        }
        if(count == text.size()) {
            pos.push_back(i);
        }
    }
}

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {

        if(s.size() < a.size() || s.size() < b.size()) {
            return {};
        }
            
        vector<int> posA;
        vector<int> posB;
        stringMatch(s, a, posA);
        stringMatch(s, b, posB);
        vector<int> ans;


        for(auto it: posA) {
            int new_pos = it - k;
            auto valPosition = lower_bound(posB.begin(), posB.end(), new_pos);
            if(valPosition != posB.end()) {
                int positionB = valPosition - posB.begin();
                int valB = posB[positionB];

                if(valB <= it + k) {
                    ans.push_back(it);
                }
            }
        }

        return ans;
    }
};
