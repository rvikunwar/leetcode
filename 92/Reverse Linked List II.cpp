// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = 1;

        ListNode* node = head;
        ListNode* edgeNode = nullptr;
        ListNode* headNode;
        ListNode* newNode = nullptr;
        while(node != nullptr){

            headNode = node;
            while(count >= left && count <= right){
                ListNode* temp = node->next;
                node->next = newNode;
                newNode = node;
                node = temp;
                count++;
            }

            if(count > right){
                if(edgeNode != nullptr){
                    edgeNode->next = newNode;
                }
                headNode->next = node;
                break;
            }

            edgeNode = node;
            count++;
            node=node->next;
        }

        return (left == 1)?  newNode: head;
    }
};