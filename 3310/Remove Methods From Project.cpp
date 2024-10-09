// Remove Methods From Project.cpp
// https://leetcode.com/problems/remove-methods-from-project/description/

class Solution {
public:
    void dfs(int method, vector<int> &visited, vector<vector<int>> &graph) {
        if(visited[method]) {
            return;
        }
        
        visited[method] = 1;
        
        for(int i=0; i<graph[method].size(); i++) {
            dfs(graph[method][i], visited, graph);
        }
    }
    
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> visited(n, 0);
        vector<vector<int>> graph;
        graph.resize(n+1);
        for(int i=0; i<invocations.size(); i++) {
            int first = invocations[i][0];
            int second = invocations[i][1];
            graph[first].push_back(second);
        }

        dfs(k, visited, graph);
        bool none = true;
        for(int i=0; i<invocations.size(); i++) {
            int first = invocations[i][0];
            int second = invocations[i][1];
            if(visited[first] == 0 && visited[second] == 1) {
                none = false;
                break;
            }
        }
        
        vector<int> ans;
        
        for(int i=0; i<n; i++) {
            if(none == false) {
                ans.push_back(i);
                continue;
            }
            
            if(visited[i] == 0) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};

