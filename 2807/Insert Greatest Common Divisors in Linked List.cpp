// Insert Greatest Common Divisors in Linked List.cpp
// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/?envType=daily-question&envId=2024-09-10

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
    int gcd(int a, int b) {
        while(b != 0) {
            int remainder = a % b;
            a = b;
            b = remainder;
        }

        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* node = head;
        while(node->next != nullptr) {
            int a = node->val;
            int b = node->next->val;
            int gcd_ = gcd(a, b);
            ListNode* new_node = new ListNode(gcd_);
            new_node->next = node->next;
            node->next = new_node;
            node = new_node->next;  
        }    

        return head;
    }
};