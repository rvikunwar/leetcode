// You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

// Return the head of the linked list after doubling it.

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
    void traversal(ListNode* node, int &carry, stack<int> &st){
        if(node == nullptr){
            return;
        }
        int value = node->val;
        st.push(value);
        traversal(node->next, carry, st);
        int topStValue = (st.top() * 2) + carry;
        st.pop();
        if(topStValue >= 10){
            topStValue = topStValue % 10;
            carry = 1;
        } else {
            carry = 0;
        }
        node->val = topStValue;
    }
    
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        stack<int> st;
        traversal(head, carry, st);
        
        if(carry){
            ListNode* node = new ListNode(carry);
            node->next = head;
            head = node;
        }
        return head;
    }
};