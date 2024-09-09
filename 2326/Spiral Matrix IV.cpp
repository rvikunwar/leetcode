// Spiral Matrix IV.cpp
// https://leetcode.com/problems/spiral-matrix-iv/description/?envType=daily-question&envId=2024-09-09

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

typedef long long ll;
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        int current_first_row = 0;
        int current_last_col = n-1;

        int current_first_col = 0;
        int current_last_row = m-1;

        ListNode* node = head;

        ll count = 0;
        ll total_spaces = (ll)m*(ll)n;
        vector<vector<int>> ans(m, vector<int> (n, -1));

        while(count != total_spaces) {
            for(int i=current_first_col; i<=current_last_col; i++) {
                if(node != nullptr) {
                    ans[current_first_row][i] = node->val;
                    node = node->next;
                }
                count++;
            }
            
            if(count == total_spaces) break;
            current_first_row++;

            for(int i=current_first_row; i<= current_last_row; i++) {
                if(node != nullptr) {
                    ans[i][current_last_col] = node->val;
                    node = node->next;
                }
                count++;
            }

            if(count == total_spaces) break;
            current_last_col--;

            for(int i=current_last_col; i>=current_first_col; i--) {
                if(node != nullptr) {
                    ans[current_last_row][i] = node->val;
                    node = node->next;
                }
                count++;
            }

            if(count == total_spaces) break;
            current_last_row--;
            
            for(int i=current_last_row; i>=current_first_row; i--) {
                if(node != nullptr) {
                    ans[i][current_first_col]  = node->val;
                    node = node->next;
                }
                count++;
            }
            current_first_col++;
        }

        return ans;
    }
};
