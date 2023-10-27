// Given a string s, return the longest 
// palindromic
 
// substring
//  in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.

class Solution {
public:
    string expandingFunction(string &s, int left, int right) {
        while(left>=0 && right<s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }

    string longestPalindrome(string s) {
        string palindromeStr = "";

        for(int i=0; i<s.size(); i++){
            string longestStr;
            string oddLenStr = expandingFunction(s, i, i);
            string evenLenStr = expandingFunction(s, i, i+1);
            if(oddLenStr.size() > evenLenStr.size()){
                longestStr = oddLenStr;
            } else {
                longestStr = evenLenStr;
            }
            if(palindromeStr.size() < longestStr.size()){
                palindromeStr = longestStr;
            }
        }
        return palindromeStr;
    }
};