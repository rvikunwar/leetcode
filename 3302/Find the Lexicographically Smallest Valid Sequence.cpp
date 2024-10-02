// Find the Lexicographically Smallest Valid Sequence.cpp

// Greedy + recursion
typedef pair<int, int> pii;
class Solution {
    public:
        string word1_; 
        string word2_;
        vector<int> sol;
        set<pair<int, pii>> st; 
        bool helper(int i, int j, int flag) {
            if(j >= word2_.size()) return 1;
            if(i >= word1_.size()) return 0;
            if(st.find({i, {j, flag}}) != st.end()) return 0;
            int ans;
            if(word1_[i] == word2_[j]) {
                ans = helper(i+1, j+1, flag);
                if(ans) {
                    sol.push_back(i);
                    return 1;
                }
            } else {
                if(flag) {
                    ans = helper(i+1, j+1, !flag);
                    if(ans) {
                        sol.push_back(i);
                        return 1;
                    }
                }

                while(i+1 < word1_.size()) {
                    ans = helper(i+1, j, flag);
                    if(ans) {
                        return 1;
                    }
                    i++;
                }
            }
            st.insert({i, {j, flag}});
            return 0;
        }

        vector<int> validSequence(string word1, string word2) {
            vector<int> ans;
            word1_ = word1;
            word2_ = word2;
            helper(0, 0, 1);
            for(int i=sol.size()-1; i>=0; i--) {
                ans.push_back(sol[i]);
            }

            return ans;
        }

};

// Linear solution

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n =  word1.size();
        int m = word2.size();
        vector<int> last(m, -1);
        int skip = 0;
        int j = m-1;
        for(int i=n-1; i>=0; i--) {
            if(j >= 0 && word1[i] == word2[j]) {
                last[j]= i;
                j--;
            }
        }

        int i = 0;
        j = 0;
        vector<int> res;
        while(i < n) {
            if(word1[i] == word2[j]) {
                res.push_back(i);
                i++;
                j++;
            } else {
                if(!skip && ((j < m-1 && i < last[j+1]) || j == m-1)) {
                    res.push_back(i);
                    skip = 1;
                    i++;
                    j++;
                } else {
                    i++;
                }
            }
        }

        return (res.size() == m)? res: vector<int>();
    }
};
