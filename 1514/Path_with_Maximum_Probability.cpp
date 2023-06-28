// Path with Maximum Probability
// You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
// Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
// If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.


#include <bits/stdc++.h>

#define pb push_back
#define pr pair<int, int>

// solution 1 - dfs (time exceeded)
class Solution {
public:

	void dfs(int node, vector<vector<pr>> &adj,
		vector<bool> &route, double prob, double &ans, int dest){
		if(node == dest){
			ans = max(ans, prob);
			return;
		}
		if(route[node]) return;
		route[node] = true;
		for(auto it: adj[node]){
			int newNode = it.first;
			dfs(newNode, adj, route, prob*it.second, ans, dest);	
		}

		route[node] = false;
	}

    double maxProbability(int n, vector<vector<int>>& edges, 
    	vector<double>& succProb, int start, int end) {

    	// creating adjacency list
    	vector<vector<pr>> adj(n);
    	for(int i=0; i<edges.size(); i++){
    		int node1 = edges[i][0];
    		int node2 = edges[i][1];
    		double probability = succProb[i];
    		adj[node1].pb({ node2, probability });
    		adj[node2].pb({ node1, probability });
    	}

    	// for checking visited nodes
    	vector<bool> route(n);
    	double ans = 0;
    	double prob = 1;
    	dfs(start, adj, route, prob, ans, end);
    	return ans;
	}  
};




// solution 2 - dfs (time exceeded)
class Solution {
public:

    double maxProbability(int n, vector<vector<int>>& edges, 
    	vector<double>& succProb, int start, int end) {

    	// creating adjacency list
    	vector<vector<pr>> adj(n);
    	for(int i=0; i<edges.size(); i++){
    		int node1 = edges[i][0];
    		int node2 = edges[i][1];
    		double probability = succProb[i];
    		adj[node1].pb({ node2, probability });
    		adj[node2].pb({ node1, probability });
    	}

    	vector<double> dist(n, 0.0);

    	dist[start] = 1.0;

    	queue<int> q;
    	q.push(start);
    	while(!q.empty()){
    		int curr = q.front();
    		q.pop();

    		for(auto it: adj[curr]){
    			int node = it.first;
    			double prob = it.second;
    			double newProb = prob * dist[curr];

    			if(dist[node]<newProb){
    				dist[node] = newProb;
    				q.push(node);
    			}
    		}
    	}
    	return dist[end];
	}  
};