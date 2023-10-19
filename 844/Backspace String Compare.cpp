// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

 

// Example 1:

// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".
// Example 2:

// Input: s = "ab##", t = "c#d#"
// Output: true
// Explanation: Both s and t become "".
// Example 3:

// Input: s = "a#c", t = "b"
// Output: false
// Explanation: s becomes "c" while t becomes "b".
 

// Constraints:

// 1 <= s.length, t.length <= 200
// s and t only contain lowercase letters and '#' characters.

class Solution {
public:
    string clearString(string s) {
        string str = "";
        int hash = 0;
        int size = s.size()-1;
        while(size >= 0){
            if(s[size] == '#'){
                hash++;
            }
            else if(hash>0){
                hash--;
            }
            else {
                str += s[size];
            }
            size--;
        }
        return str;
    }

    bool backspaceCompare(string s, string t) {
        
        if(clearString(s) == clearString(t)) return true;
        return false;
    }
};