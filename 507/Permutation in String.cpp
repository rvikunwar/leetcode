// Permutation in String.cpp
// https://leetcode.com/problems/permutation-in-string/

class Solution {
public:

    bool check(vector<int> &char1, vector<int> &char2) {
        for(int i=0; i<26; i++) {
            if(char1[i] != char2[i]){
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        vector<int> char1(26, 0);

        for(auto it: s1) {
            int index = it - 'a';
            char1[index]++;
        }

        vector<int> char2(26, 0);

        int i = 0;
        int j = 0;
        int size1 = s1.size();
        int size2 = s2.size();
        while(j < size2) {
            if(j - i + 1 == size1) {
                int indexJ = s2[j] - 'a';
                char2[indexJ]++;
                if(check(char1, char2)) {
                    return true;
                }
                int indexI = s2[i] - 'a';
                char2[indexI]--;
                i++;
                j++;
            } else {
                int index = s2[j] - 'a';
                char2[index]++;
                j++;
            }
        }

        return false;
    }
};

