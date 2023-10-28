// Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

// Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
// Each vowel 'a' may only be followed by an 'e'.
// Each vowel 'e' may only be followed by an 'a' or an 'i'.
// Each vowel 'i' may not be followed by another 'i'.
// Each vowel 'o' may only be followed by an 'i' or a 'u'.
// Each vowel 'u' may only be followed by an 'a'.
// Since the answer may be too large, return it modulo 10^9 + 7.

 

// Example 1:

// Input: n = 1
// Output: 5
// Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
// Example 2:

// Input: n = 2
// Output: 10
// Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
// Example 3: 

// Input: n = 5
// Output: 68
 

// Constraints:

// 1 <= n <= 2 * 10^4

class Solution {
public:
    long mod = 1e9 + 7;
    // -> recursion
    // int findPermutation(int length, int lastEle) {
    //     if(length == 0) return 1;
    //     long count = 0;
    //     if(lastEle == 1) {
    //         count += findPermutation(length - 1, 2) % mod;
    //         count += findPermutation(length - 1, 5) % mod;
    //     } 
    //     if(lastEle == 2) {
    //         count += findPermutation(length - 1, 1) % mod;
    //     }
    //     if(lastEle == 3) {
    //         count += findPermutation(length - 1, 4) % mod;
    //         count += findPermutation(length - 1, 2) % mod;
    //     }
    //     if(lastEle != 0 && lastEle != 3) {
    //         count += findPermutation(length - 1, 3) % mod;
    //     }
    //     if(lastEle == 5) {
    //         count += findPermutation(length - 1, 4) % mod;
    //     }
    //     if(lastEle == 0){
    //         for(int i=1; i<=5; i++){
    //             count += findPermutation(length - 1, i) % mod;
    //         }
    //     }
    //     return count;
    // }

    // int countVowelPermutation(int n) {
    //     return findPermutation(n, 0) % mod;
    // }

    // -> memoization
    // int findPermutation(int length, int lastEle, vector<vector<int>> &dp) {
    //     if(length == 0) return 1;
    //     if(dp[lastEle][length] != -1) return dp[lastEle][length];
    //     long count = 0;
    //     if(lastEle == 1) {
    //         count += findPermutation(length - 1, 2, dp) % mod;
    //         count += findPermutation(length - 1, 5, dp) % mod;
    //     } 
    //     if(lastEle == 2) {
    //         count += findPermutation(length - 1, 1, dp) % mod;
    //     }
    //     if(lastEle == 3) {
    //         count += findPermutation(length - 1, 4, dp) % mod;
    //         count += findPermutation(length - 1, 2, dp) % mod;
    //     }
    //     if(lastEle != 0 && lastEle != 3) {
    //         count += findPermutation(length - 1, 3, dp) % mod;
    //     }
    //     if(lastEle == 5) {
    //         count += findPermutation(length - 1, 4, dp) % mod;
    //     }
    //     if(lastEle == 0){
    //         for(int i=1; i<=5; i++){
    //             count += findPermutation(length - 1, i, dp) % mod;
    //         }
    //     }

    //     return dp[lastEle][length] = count % mod;
    // }

    // int countVowelPermutation(int n) {
    //     vector<vector<int>> dp(6, vector<int> (n+1, -1));
    //     return findPermutation(n, 0, dp) % mod;
    // }

    // -> dp
    int countVowelPermutation(int n) {
        vector<vector<long>> dp(n+1, vector<long> (6, 0));

        for(int i=1; i<6; i++){
            dp[1][i] = 1;
        }
        for(int i=2; i<n+1; i++){
            for(int j=1; j<6; j++){
                if(j == 1) {
                    dp[i][j] += dp[i-1][2] % mod;
                    dp[i][j] += dp[i-1][5] % mod;
                } 
                if(j == 2) {
                    dp[i][j] += dp[i-1][1] % mod;
                }
                if(j == 3) {
                    dp[i][j] += dp[i-1][4] % mod;
                    dp[i][j] += dp[i-1][2] % mod;
                }
                if(j != 0 && j != 3) {
                    dp[i][j] += dp[i-1][3] % mod;
                }
                if(j == 5) {
                    dp[i][j] += dp[i-1][4] % mod;
                }
            }
        }

        long count = 0;
        for(int i=1; i<=5; i++){
            count += dp[n][i];
            count %= mod;
        }
        return count;
    }
};