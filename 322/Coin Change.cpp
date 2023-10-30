// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0
 

// Constraints:

// 1 <= coins.length <= 12
// 1 <= coins[i] <= 231 - 1
// 0 <= amount <= 104


class Solution {
public:
    // int calculateMinCoins(vector<int>& coins, int amount, int index) {
    //     if(amount == 0) return 0;
    //     if(index >= coins.size() || amount < 0) return INT_MAX-1;

    //     if(coins[index] <= amount) {
    //         return min(1 + calculateMinCoins(coins, amount-coins[index], index), 
    //             calculateMinCoins(coins, amount, index+1));
    //     }
    //     return calculateMinCoins(coins, amount, index+1);
    // }

    // int coinChange(vector<int>& coins, int amount) {
    //     int value = calculateMinCoins(coins, amount, 0);
    //     return value == INT_MAX-1 ? -1: value;
    // }

    int calculateMinCoins(vector<int>& coins, int amount, int index, vector<vector<int>> &dp) {
        if(amount == 0) return 0;
        if(index >= coins.size() || amount < 0) return INT_MAX-1;
        if(dp[amount][index] != -1) return dp[amount][index];

        if(coins[index] <= amount) {
            return dp[amount][index] = min(1 + calculateMinCoins(coins, amount-coins[index], index, dp), 
                calculateMinCoins(coins, amount, index+1, dp));
        }
        return dp[amount][index] = calculateMinCoins(coins, amount, index+1, dp);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(10000+1, vector<int> (13, -1));
        int value = calculateMinCoins(coins, amount, 0, dp);
        return value == INT_MAX-1 ? -1: value;
    }

};