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
public:
    ListNode* node = nullptr;
    bool flag = true;
    bool flag1 = false;
    ListNode* temp = nullptr;
    void traverse(ListNode* node1){
        if(node1 == nullptr) return;
        traverse(node1->next);
        
        if(flag1 == true){
            node1->next = nullptr;
            flag1 = false;
        }
        if((node->next == node1|| node == node1)){
            flag = false;
        }

        if(flag){
            temp = node->next;
            node->next = node1;
            node1->next = temp;
            node = temp;
            flag1 = true;
        }
    }
    
    void reorderList(ListNode* head) {
        node = head;
        traverse(node);
    }
};
