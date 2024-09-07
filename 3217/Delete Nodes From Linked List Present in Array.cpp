// Delete Nodes From Linked List Present in Array.cpp

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
class Solution {
    private:
        set<int> mp;
public:
    
    void remove_node(ListNode* prev_node, ListNode* cur_node) {
        if(cur_node == nullptr){
            return;
        }
        int value = cur_node->val;
        if(mp.find(value) != mp.end()) {
            prev_node->next = cur_node->next;
            cur_node = prev_node->next;
        } else {
            prev_node = cur_node;
            cur_node = cur_node->next;
        }
        remove_node(prev_node, cur_node);
    }

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        for(auto it: nums) {
            mp.insert(it);
        }

        ListNode* new_head = new ListNode(0);
        new_head->next = head;

        ListNode* prev_node = new_head;
        ListNode* cur_node = head;

        while(cur_node != nullptr) {
            int value = cur_node->val;
            if(mp.find(value) != mp.end()) {
                prev_node->next = cur_node->next;
                cur_node = prev_node->next;
            } else {
                prev_node = cur_node;
                cur_node = cur_node->next;
            }
        }

        return new_head->next;
    }
};

