// Count of Integers
// You are given two numeric strings num1 and num2 and two integers max_sum and min_sum. We denote an integer x to be good if:

// num1 <= x <= num2
// min_sum <= digit_sum(x) <= max_sum.
// Return the number of good integers. Since the answer may be large, return it modulo 109 + 7.

// Note that digit_sum(x) denotes the sum of the digits of x.


// class Solution {
//     int mod = 1000000007;
//     void countNumber(int index, int tight, int sum, string &digit, int min_sum, int max_sum, int &count){
//         if(index == digit.size()){
//             if(sum<=max_sum && sum>=min_sum){
//                 count++;
//                 count %=  mod;
//             }
//             return;
//         } else {
//             if(tight == 1){
//                 for(int i=0; i<=(digit[index] - '0'); i++){
//                     if(i == (digit[index] - '0')){
//                         countNumber(index+1, 1, sum+i, digit, min_sum, max_sum, count);
//                     } else {
//                         countNumber(index+1, 0, sum+i, digit, min_sum, max_sum, count);
//                     }
//                 }
//             } else {
//                 for(int i=0; i<=9; i++){
//                     countNumber(index+1, 0, sum+i, digit, min_sum, max_sum, count);
//                 }
//             }  
//         }
//     }
    
// public:
//     int count(string num1, string num2, int min_sum, int max_sum) {
//         int count1 = 0;
//         int sm1 = 0;
//         int count2 =0;
//         int sm2 = 0;
//         countNumber(0, 1, 0, num2, min_sum, max_sum, count1);
//         string num3 = num1;
//         num3[num1.size()-1] = '0' + (num3[num1.size()-1] - '0' - 1);
//         countNumber(0, 1, 0, num3, min_sum, max_sum, count2);
//         return count1 - count2;
        
//     }
// };

#define ll long long
class Solution {
    int mod = 1000000007;
    int dp[23][2][401];
    int countNumber(int index, int tight, int sum, string &digit, int min_sum, int max_sum){
        if(index == digit.size()){
            if(sum<=max_sum && sum>=min_sum){
                return 1;
            }
            return 0;
        } 
        if(dp[index][tight][sum] != -1) return dp[index][tight][sum]; 
        else {
            if(tight == 1){
                ll res = 0;
                for(int i=0; i<=(digit[index] - '0'); i++){
                    if(i == (digit[index] - '0')){
                        res = (res) + countNumber(index+1, 1, sum+i, digit, min_sum, max_sum);
                    } else {
                        res = (res) + countNumber(index+1, 0, sum+i, digit, min_sum, max_sum);
                    }
                }
                dp[index][tight][sum] = res%mod;
                return res%mod;
            } else {
                ll res = 0;
                for(int i=0; i<=9; i++){
                    res = (res) + countNumber(index+1, 0, sum+i, digit, min_sum, max_sum);
                }
                dp[index][tight][sum] = res%mod;
                return res%mod;
            }  
        }
    }
    
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        ll count1 = countNumber(0, 1, 0, num2, min_sum, max_sum);
        memset(dp, -1, sizeof(dp));
        ll count2 = countNumber(0, 1, 0, num1, min_sum, max_sum);

        int sum  = 0;
        for(auto i: num1){
            sum += (i -'0');
        }
        cout<<count1<<" "<<count2<<endl;
        if(sum>=min_sum && sum<=max_sum) count2--;
        return (count1 - count2 + mod)%mod;
    }
};