// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return false;
        ListNode* ptr1 = head->next;
        ListNode* ptr2 = head->next->next;

        while(ptr1 != nullptr && ptr2 != nullptr && ptr2->next != nullptr){
            if(ptr1 == ptr2) return true;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }

        return false;
    }
};