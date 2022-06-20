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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr1 = new ListNode(-1);
        ListNode* ptr2 = head;
        head = ptr1;
        while(ptr2 != nullptr){
                if(ptr2->next != nullptr && ptr2->val == ptr2->next->val){
                    while(ptr2->next != nullptr && ptr2->val == ptr2->next->val){
                        ptr2 = ptr2->next;
                    }
                    ptr2 = ptr2->next;
                } else {
                    ptr1->next = ptr2;
                    ptr1 = ptr2;
                    ptr2 = ptr2->next;
                }

        }
        ptr1->next = nullptr;
        
        return head->next;
    }
};
