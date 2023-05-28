// Design a special dictionary that searches the words in it by a prefix and a suffix.

// Implement the WordFilter class:

// WordFilter(string[] words) Initializes the object with the words in the dictionary.
// f(string pref, string suff) Returns the index of the word in the dictionary, which has the prefix pref and the suffix suff. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.
 

// Example 1:

// Input
// ["WordFilter", "f"]
// [[["apple"]], ["a", "e"]]
// Output
// [null, 0]
// Explanation
// WordFilter wordFilter = new WordFilter(["apple"]);
// wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = "e".
 

// Constraints:

// 1 <= words.length <= 104
// 1 <= words[i].length <= 7
// 1 <= pref.length, suff.length <= 7
// words[i], pref and suff consist of lowercase English letters only.
// At most 104 calls will be made to the function f.


// https://leetcode.com/problems/prefix-and-suffix-search/description/

struct Node{
    Node* links[26];
    bool flag = false;
    vector<int> vc;

    bool containKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    bool isEnd(){
        return flag;
    }

    void end(){
        flag = true;
    }
};

class WordFilter {
private:
    Node* forwardRoot;
    Node* backwardRoot;
public:
    void insert(string word, Node* node, int index){
        for(int i=0; i<word.length(); i++){
            if(!node->containKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->vc.push_back(index);
        }
    }

    WordFilter(vector<string>& words) {
        forwardRoot = new Node();
        backwardRoot = new Node();
        unordered_set<string> wordSet;

        int index = words.size();
        for(int i=index-1; i>=0; i--){
            string word = words[i];
            if (wordSet.find(word) != wordSet.end())
                continue;
            wordSet.insert(word);
            insert(word, forwardRoot, i);
            reverse(word.begin(), word.end());
            insert(word, backwardRoot, i);
        }
    }

    vector<int>* find(string &word, Node* node){
        for(int i=0; i<word.length(); i++){
            if(!node->containKey(word[i])){
                return nullptr;
            } else {
                node = node->get(word[i]);
            }
        }
        return &node->vc;
    }
    
    int f(string pref, string suff) {
        vector<int> *forward = find(pref, forwardRoot);
        reverse(suff.begin(), suff.end());
        vector<int> *backward = find(suff, backwardRoot);

        if(forward == NULL || backward == NULL) return -1;

        int f_ = 0, b_ = 0;

        while(f_ != (*forward).size() && b_ != (*backward).size()){
            int fVal = (*forward)[f_];
            int bVal = (*backward)[b_];
            if(fVal == bVal) return fVal;
            if(fVal > bVal) f_++;
            else b_++;
        }

        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */