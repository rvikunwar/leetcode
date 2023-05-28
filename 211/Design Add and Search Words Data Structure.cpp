// Design a data structure that supports adding new words and finding if a string matches any previously added string.

// Implement the WordDictionary class:

// WordDictionary() Initializes the object.
// void addWord(word) Adds word to the data structure, it can be matched later.
// bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

// Example:

// Input
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
// [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
// Output
// [null,null,null,null,false,true,true,true]

// Explanation
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("bad");
// wordDictionary.addWord("dad");
// wordDictionary.addWord("mad");
// wordDictionary.search("pad"); // return False
// wordDictionary.search("bad"); // return True
// wordDictionary.search(".ad"); // return True
// wordDictionary.search("b.."); // return True
 

// Constraints:

// 1 <= word.length <= 25
// word in addWord consists of lowercase English letters.
// word in search consist of '.' or lowercase English letters.
// There will be at most 2 dots in word for search queries.
// At most 104 calls will be made to addWord and search.


// https://leetcode.com/problems/design-add-and-search-words-data-structure/description/


struct Node{
    Node* links[26];
    bool flag = false;

    bool containKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void end(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class WordDictionary{
    private:
        Node* root;
    public:
        WordDictionary(){
            root = new Node();
        }

        void addWord(string word){
            Node* node = root;
            for(int i=0; i<word.length(); i++){
                if(!node->containKey(word[i])){
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
            }
            node->end();
        }

        bool recSearch(int index, Node* node, string& word){
            if(index == word.length()){
                return node->isEnd();
            }
            if(word[index] == '.'){
                for(int i=0; i<26; i++){
                    if(node->links[i] != NULL){
                        if(recSearch(index+1, node->links[i], word)){
                            return true;
                        }
                    }
                }
                return false;
            } else {
                if(!node->containKey(word[index])){
                    return false;
                }
                node = node->get(word[index]); 
            }

            return recSearch(index+1, node, word);
        }

        bool search(string word){
            Node* node = root;

            return recSearch(0, node, word);
        }
};