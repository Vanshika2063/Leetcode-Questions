public class LinkedListCycleII {

    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }
    public static ListNode detectCycle(ListNode head) {

         ListNode fast = head, slow = head;

         while(fast != null && fast.next != null){
             fast = fast.next.next;
             slow = slow.next;

             if(fast == slow){
                 fast = head;

                 while(fast != slow){
                     fast = fast.next;
                     slow = slow.next;
                 }
                 return slow;
             }

         }
         return null;
    }
    private static void printList(ListNode head){
        while(head != null){
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println("");
    }

    public static void main(String[] args) {

        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        // 1 -> 2 -> 3

        ListNode tmp = new ListNode(4);
        tmp.next = new ListNode(5);
        // 4 -> 5

        ListNode dummyHead = head;
        while(dummyHead.next != null)
            dummyHead = dummyHead.next;

        dummyHead.next = tmp;   // 1 -> 2 -> 3 (dummyHead) -> 4 -> 5

        tmp = tmp.next;
        tmp.next = head.next;   // 4 -> 5 (tmp) -> 2 -> 3 -> 4 -> 5

        ListNode node = detectCycle(head);
        System.out.println("Cycle node: " + ((node != null) ? node.val : "No Cycle detected"));

    }
}

