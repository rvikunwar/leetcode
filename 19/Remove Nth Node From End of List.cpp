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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* ptr1 = new ListNode(-1);
        ptr1->next = head;
        ListNode* ptr2 = head;
        head = ptr1;
        
        while(ptr2 != nullptr){
            if(count == n){
                ptr1 = ptr1->next;
            } else {
                count++;
            }
            ptr2 = ptr2->next;
        }
        ptr1->next = ptr1->next->next;
        
        return head->next;
    }
};
