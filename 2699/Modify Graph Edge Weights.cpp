// Modify Graph Edge Weights.cpp

// You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

// Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

// If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.


typedef pair<double, double> pdd;
class Solution {
private:
    unordered_map<int, vector<pdd>> graph;

    double dijkstra(int n, int source, int dest) {
        vector<double> dist(n, 0);
        priority_queue<pdd> pq;
        dist[source] = 1;
        pq.push({ 1, source });

        while(!pq.empty()) {
            int node = pq.top().second;
            double weight = pq.top().first;
            pq.pop();

            if(node == dest) {
                return dist[node];
            }

            for(auto& edge: graph[node]) {
                if(weight * edge.second > dist[edge.first]) {
                    dist[edge.first] = weight * edge.second;
                    pq.push({ dist[edge.first], edge.first });
                }
            }
        }

        return 0;
    }

public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        double prob = dijkstra(n, start_node, end_node);

        return prob;
    }
};