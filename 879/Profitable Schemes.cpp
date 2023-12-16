// There is a group of n members, and a list of various crimes they could commit. The ith crime generates a profit[i] and requires group[i] members to participate in it. If a member participates in one crime, that member can't participate in another crime.

// Let's call a profitable scheme any subset of these crimes that generates at least minProfit profit, and the total number of members participating in that subset of crimes is at most n.

// Return the number of schemes that can be chosen. Since the answer may be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: n = 5, minProfit = 3, group = [2,2], profit = [2,3]
// Output: 2
// Explanation: To make a profit of at least 3, the group could either commit crimes 0 and 1, or just crime 1.
// In total, there are 2 schemes.
// Example 2:

// Input: n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
// Output: 7
// Explanation: To make a profit of at least 5, the group could commit any crimes, as long as they commit one.
// There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).
 

// Constraints:

// 1 <= n <= 100
// 0 <= minProfit <= 100
// 1 <= group.length <= 100
// 1 <= group[i] <= 100
// profit.length == group.length
// 0 <= profit[i] <= 100


class Solution {
    int mod = 1000000000 + 7;
    int minSchemes(int index, int currentProfit, int currentMembers, vector<int>& group, vector<int>& profit, int n, int minProfit, int minMembers, unordered_map<string, int> &dp) {
        if(n == index){
            if(currentProfit >= minProfit && currentMembers <= minMembers){
                return 1;
            } else {
                return 0;
            }
        }

        int val = 0;

        string field = to_string(index) + "_" + to_string(currentProfit) + "_" + to_string(currentMembers);

        if(dp.find(field) != dp.end()){
            return dp[field];
        }

        for(int i=index; i<=n; i++){
            if(i == n){
                val += minSchemes(i, currentProfit, currentMembers, group, profit, n, minProfit, minMembers, dp);
            } else {
            int profitVal = profit[i];
            int memberVal = group[i];
                val += minSchemes(i+1, profitVal+currentProfit, memberVal + currentMembers, group, profit, n, minProfit, minMembers, dp);
            }
        }


        return dp[field] = (val%mod);
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int size = group.size();
        // unordered_map<string, int> dp;
        // return minSchemes(0, 0, 0, group, profit, size, minProfit, n, dp);

        vector<vector<vector<int>>> dp(size+1, vector<vector<int>> (n+1, vector<int> (minProfit+1, 0)));
        dp[0][0][0] = 1;

        for(int i=1; i <= size; i++){
            int members = group[i-1];
            int profitVal = profit[i-1];
            for(int j=0; j <= n; j++){
                for(int k=0; k <= minProfit; k++) {
                    dp[i][j][k] = dp[i-1][j][k] % mod;
                    if(members <= j) {
                        dp[i][j][k] += (dp[i-1][j-members][max(0, k-profitVal)] % mod);
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0; i<=n; i++){
            ans += (dp[size][i][minProfit] % mod);
            ans %= mod;
        }

        return ans;
    }
};