// Leetcode  - You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

// The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

// Return the length of the longest cycle in the graph. If no cycle exists, return -1.

// A cycle is a path that starts and ends at the same node

// https://leetcode.com/problems/longest-cycle-in-a-graph/description/


class Solution {

public:
    void dfs(int val, vector<bool> &visited, vector<bool> &route, vector<int>& edges, int& count, int& circledNode){
        if(val == -1)  return;
        if(route[val] == true){
            count++;
            circledNode = val;
            return;
        }
        if(visited[val] == true) return;
        visited[val] = true;
        route[val] = true;
        dfs(edges[val], visited, route, edges, count, circledNode);
        route[val] = false;
        if(circledNode != -1 && circledNode != val){
            count++;
        } else if(circledNode != -1 && circledNode == val){
            circledNode = -1;
        }
    }

    int longestCycle(vector<int>& edges) {
        int size = edges.size();
        vector<bool> visited(size, false); 
        vector<bool> route(size, false);
        int cycleNodes = -1;

        for(int i=0; i<size; i++){
            int count = 0;
            int circledNode = -1;
            if(!visited[i]) dfs(i, visited, route, edges, count, circledNode);
            cycleNodes = max(count, cycleNodes);
        }  
        return cycleNodes == 0? -1: cycleNodes;
    }
};