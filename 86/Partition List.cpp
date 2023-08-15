// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

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
class Solution
{
public:
    void valueHandler(ListNode *&node, int value)
    {
        node->next = new ListNode(value);
        node = node->next;
    }
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *before = new ListNode();
        ListNode *after = new ListNode();

        ListNode *before_head = before;
        ListNode *after_head = after;
        while (head != nullptr)
        {
            int value = head->val;
            if (value < x)
            {
                valueHandler(before, value);
            }
            else
            {
                valueHandler(after, value);
            }
            head = head->next;
        }

        before->next = after_head->next;
        return before_head->next;
    }
};