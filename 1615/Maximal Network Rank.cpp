// There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.

// The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.

// The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.

// Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<unordered_set<int>> vc(n);

        for(int i=0; i<roads.size(); i++){
            vc[roads[i][0]].insert(roads[i][1]);
            vc[roads[i][1]].insert(roads[i][0]);
        }

        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int value = vc[i].size() + vc[j].size();
                if(vc[i].find(j) != vc[i].end()){
                    value--;
                }

                ans = max(ans, value);
            }
        }

        return ans;
    }
};