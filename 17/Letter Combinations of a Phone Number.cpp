// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


class Solution {
    vector<string> vc = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    void getStr(int index, string &digits, vector<string> &ans, string ch){
        if(index == digits.size()){
            ans.push_back(ch);
            return;
        }
        int val  = digits[index] - '0';
        string s = vc[val];
        for(int i=0; i<s.size(); i++){
            getStr(index+1, digits, ans, ch + s[i]);
        }

    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> ans;
        string ch = "";
        getStr(0, digits, ans, ch);
        return ans;
    }
};