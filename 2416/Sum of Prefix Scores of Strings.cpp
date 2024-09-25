// Sum of Prefix Scores of Strings.cpp
// https://leetcode.com/problems/sum-of-prefix-scores-of-strings


class TrieNode {
    public:
        unordered_map<int, TrieNode*> child;
        // vector<TrieNode*> child;
        int count;
        TrieNode() {
            count = 0;
        }
};


class Trie{
    private:
        TrieNode* root;
    public:
        Trie() {
            root = new TrieNode();
        }

        void insert(string &word) {
            TrieNode* node = root;

            for(char ch: word) {
                int chIndex = ch - 'a';
                if(node->child.find(chIndex) == node->child.end()) {
                    node->child[chIndex] = new TrieNode();
                } 
                node->child[chIndex]->count += 1;
                node = node->child[chIndex];
            }
        }

        int searchPrefixCount(string &word) {
            TrieNode* node = root;
            int count = 0;

            for(char ch: word) {
                int chIndex = ch - 'a';
                if(node->child[chIndex] != nullptr) {
                    count += node->child[chIndex]->count;
                } else {
                    break;
                }
                node = node->child[chIndex];
            } 

            return count;
        }

};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie();

        for(auto word: words) {
            trie->insert(word);
        }

        vector<int> ans;
        for(auto word: words) {
            int count = trie->searchPrefixCount(word);
            ans.push_back(count);
        }

        return ans;
    }
};

