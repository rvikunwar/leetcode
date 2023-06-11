// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

class Solution {
    int p[2] = { ')', '('};

    void generate(int index, int open, vector<string> &ans, string s, int n, int openP){
        if(index == n){
            ans.push_back(s);
            return;
        }

        if(open && open < n/2){
            s[index] = p[1];
            generate(index+1, open+1, ans, s, n, openP+1);
            s[index] = p[0];
            if(openP>0) generate(index+1, open, ans, s, n, openP-1);
        } else {
            s[index] = p[0];
            if(openP>0) generate(index+1, open, ans, s, n, openP-1);
        }
    }
public:
    // vector<string> generateParenthesis(int n) {
    //     vector<string> ans;
    //     string s = "(";
    //     for(int i=0; i<(n*2)-1; i++){
    //         s+=" ";
    //     }
    //     int openP = 1;
    //     generate(1, 1, ans, s, 2*n, openP);
    //     return ans;
    // }

    void add(int n, int m, vector<string> &ans, string s){
        if(n == 0 && m == 0){
            ans.push_back(s);
            return;
        }
        if(n > 0) add(n-1, m+1, ans, s+'(');
        if(m > 0) add(n, m-1, ans, s+')');
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        add(n, 0, ans, "");
        return ans;
    }
};