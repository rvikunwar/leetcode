// The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

// For example, "ACGAATTCCG" is a DNA sequence.
// When studying DNA, it is useful to identify repeated sequences within the DNA.

// Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order

#define pb push_back
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<=10) return {};
        vector<string> vc;
        int ptr1 = 0;
        int ptr2 = 0;

        unordered_map<string, int> mp;
        string s1 = "";
        while(ptr2<=s.size()){
            if(ptr2-ptr1 == 10){
                mp[s1]++;
                if(mp[s1] == 2) vc.pb(s1);
                s1 = s1.substr(1, 9);
                s1 += s[ptr2]; 
                ptr1++;
                ptr2++;
            } else {
                s1 += s[ptr2];
                ptr2++;
            }
        }

        return vc;
    }
};