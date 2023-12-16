// You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the sum of scores of all the players in the team.

// However, the basketball team is not allowed to have conflicts. A conflict exists if a younger player has a strictly higher score than an older player. A conflict does not occur between players of the same age.

// Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, respectively, return the highest overall score of all possible basketball teams.

 

// Example 1:

// Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
// Output: 34
// Explanation: You can choose all the players.
// Example 2:

// Input: scores = [4,5,6,5], ages = [2,1,2,1]
// Output: 16
// Explanation: It is best to choose the last 3 players. Notice that you are allowed to choose multiple people of the same age.
// Example 3:

// Input: scores = [1,2,3,5], ages = [8,9,10,1]
// Output: 6
// Explanation: It is best to choose the first 3 players. 
 

// Constraints:

// 1 <= scores.length, ages.length <= 1000
// scores.length == ages.length
// 1 <= scores[i] <= 106
// 1 <= ages[i] <= 1000

class Solution {
public:
    int maxScoreq(int index, int size, vector<pair<int, int>> &vc, int maxScore, unordered_map<string, int> &dp) {
        if(index == size){
            return 0;
        }

        string field = to_string(index) + '_' + to_string(maxScore);

        if(dp.find(field) != dp.end()){
            return dp[field];
        }

        int score = 0;
        
        for(int i=index; i<size; i++){
            int newScore = vc[i].second;
            if(maxScore <= newScore) {
                score = max(score, newScore + maxScoreq(i+1, size, vc, newScore, dp));
            }
        }

        return dp[field]= score;
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int size = scores.size();
        unordered_map<string, int> dp;

        vector<pair<int, int>> vc;
        for(int i=0; i<size; i++){
            vc.push_back({ ages[i], scores[i] });
        }

        sort(vc.begin(), vc.end());

        return maxScoreq(0, size, vc, 0, dp);
    }
};