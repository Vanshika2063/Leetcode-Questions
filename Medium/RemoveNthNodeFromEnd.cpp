/*

Problem 19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
*/
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
        ListNode *fast = head, *slow = head;//Declare two pointers
        for (int i = 0; i < n; i++) fast = fast->next;//Move fast pointer n steps ahead
        if (!fast) return head->next;//If fast pointer reaches the end, remove the head
        while (fast->next) fast = fast->next, slow = slow->next;//Move both pointers until fast reaches the end
        slow->next = slow->next->next;//Remove the nth node from the end
        return head;//Return the head
    }
};