// Leetcode - Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

// Example 1:

// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.
// Example 2:

// Input: s = "aeiou", k = 2
// Output: 2
// Explanation: Any substring of length 2 contains 2 vowels.
// Example 3:

// Input: s = "leetcode", k = 3
// Output: 2
// Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.
// 1 <= k <= s.length

// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/


class Solution {
public:
    int maxVowels(string s, int k) {
        // char vowels[] = {'a', 'e', 'i', 'o', 'u'};
        // int ptr1 = 0;
        // int ptr2 = 0;
        // int count = 0;
        // int maximum = 0;
        // while(ptr2 < s.size()){
        //     if(ptr2-ptr1 == k){
        //         for(int i=0; i<5; i++){
        //             if(vowels[i] == s[ptr1]){
        //                 count--;
        //                 break;
        //             }
        //         }
        //         ptr1++;
        //     }
        //     for(int i=0; i<5; i++){
        //         if(vowels[i] == s[ptr2]){
        //             count++;
        //             break;
        //         }
        //     }
        //     maximum = max(count, maximum);
        //     ptr2++;
            char vowels[] = {'a', 'e', 'i', 'o', 'u'};

            int count = 0;
            for(int i=0, vow=0; i<s.size(); i++){
                if(i>=k){
                    for(int j=0; j<5; j++){
                        if(vowels[j] == s[i-k]){
                            vow--;
                        }
                    }
                }
                
                for(int j=0; j<5; j++){
                    if(vowels[j] == s[i]){
                        vow++;
                    }
                }
                count = max(vow, count);
            }
        

        return count;
    }
};