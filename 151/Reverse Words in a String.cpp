class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.length();
        
        for(int i=0; i < n; i++){
            string temp = "";
            if(s[i] == ' '){
                continue;
            }
            while(s[i] != ' ' && i<n){
                temp += s[i];
                i++;
            }
            st.push(temp);
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
            if(!st.empty()){
                ans += ' ';
            }
        }
        return ans;
    }
};
