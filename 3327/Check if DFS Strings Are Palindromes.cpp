// Check if DFS Strings Are Palindromes.cpp
// https://leetcode.com/problems/check-if-dfs-strings-are-palindromes/description/

class Solution {
public:

    vector<int> manacher(string &s) {
        
        string t = "#";
        for(int i=0; i<s.size(); i++) {
            t += s[i];
            t += '#';
        }

        vector<int> p(t.size(), 0);
        int right = 0;
        int center = 0;
        int n = t.size();

        for(int i=0; i<t.size(); i++) {
            int mirror =  2*center - i;
            if(i < right) {
                p[i] = min(p[mirror], right - i);
            }

            while(i - (p[i] + 1) >= 0 && i + (p[i] + 1) < n && t[i-p[i]-1] == t[i+p[i]+1]) {
                p[i]++; 
            }

            if(i + p[i] >= right) {
                center = i;
                right = i + p[i];
            }
        }

        return p;
    }

    int dfs(int index, string &str, string &s, vector<int> &pos, vector<vector<int>> &graph, vector<int> &childs) {
        if(graph[index].size() == 0) {
            str += s[index]; 
            pos[str.size()-1] = index;
            childs[index] = 1;
            return childs[index];
        }
        int c  = 1;
        for(auto it: graph[index]) {
            c += dfs(it, str, s, pos, graph, childs);
        }
        childs[index] = c;
        str += s[index];
        pos[str.size()-1] = index;
        return childs[index];
    }

    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> graph(n);

        for(int i=0; i<n; i++) {
            int p_ = parent[i];
            if(p_ != -1) {
                graph[p_].push_back(i);
            }
        }

        for(int i=0; i<n; i++) {
            sort(graph[i].begin(), graph[i].end());
        }

        string str = "";
        vector<int> pos(n, 0);
        vector<int> childs(n, 0);
        dfs(0, str, s, pos, graph, childs);
        vector<int> p = manacher(str);
        
        vector<bool> ans(n, 0);
        cout<<str<<" ";
        for(int i=n-1; i >= 0; i--) {
            int index = pos[i]; 
            int childCount = childs[index];
            int pIndex = i*2 + 1;
            int center = pIndex - childCount + 1;
            int palindromeLength = p[center];
            if(palindromeLength >= childCount) {
                ans[index] = 1;
            } 
        }

        return ans;
    }
};

