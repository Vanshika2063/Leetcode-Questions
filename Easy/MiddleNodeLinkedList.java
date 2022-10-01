public class MiddleNodeLinkedList {

     public static class ListNode {
          int val;
          ListNode next;
          ListNode() {}
          ListNode(int val) {
              this.val = val;
          }
          ListNode(int val, ListNode next) {
              this.val = val; this.next = next;
          }
     }

      public static ListNode middleNode(ListNode head) {

         if(head == null)
             return null;

         ListNode fast = head, slow = head;

         while(fast != null && fast.next != null){
             fast = fast.next.next;
             slow = slow.next;
         }

         return slow;
     }

     private static void printList(ListNode head){
         while(head != null){
             System.out.print(head.val + " ");
             head = head.next;
         }
         System.out.println("");
     }

    public static void main(String[] args) {

         ListNode head = new ListNode(1, null);
         head.next = new ListNode(2);
         head.next.next = new ListNode(3);
         head.next.next.next = new ListNode(4);
         head.next.next.next.next = new ListNode(5);

        System.out.print("Given Linked List: ");
        printList(head);

        ListNode mid = middleNode(head);

        System.out.print("Middle elements: ");
        printList(mid);
    }
}
