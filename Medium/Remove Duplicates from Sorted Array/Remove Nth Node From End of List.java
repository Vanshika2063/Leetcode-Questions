/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

/* Problem description : 
    Given the head of a linked list, remove the nth node from the end of the list and return its head.


    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]

    Input: head = [1,2], n = 1
    Output: [1]

    Constraints:

    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz
    
*/

    public ListNode removeNthFromEnd(ListNode head, int n) {
        if ((head == null) || (n==1 && head.next == null))
            return null;
        int size = 0;
        ListNode temp = head;
        while(temp != null){
            size++;
            temp = temp.next;
        }
        if(size == n)
            return head.next;
        int sn = size-n;
        int i = 0;
        temp = head;
        while(i < sn-1){
            temp = temp.next;
            i++;
        }
        temp.next = temp.next.next;
        return head;
    }
}