public class AddTwoNumbersLinkedList {

     public static class ListNode {
          int val;
          ListNode next;
          ListNode() {}
          ListNode(int val){
              this.val = val;
          }
          ListNode(int val, ListNode next){
              this.val = val;
              this.next = next;
          }
     }

     public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
         ListNode dummyHead = new ListNode(0, null);
         ListNode cur = dummyHead;

         int sum = 0, carry = 0;

         while(l1 != null || l2 != null || carry == 1){

             if(l1 != null){
                 sum += l1.val;
                 l1 = l1.next;
             }

             if(l2 != null){
                 sum += l2.val;
                 l2 = l2.next;
             }

             sum += carry;
             carry = sum / 10;

             cur.next = new ListNode(sum % 10);
             cur = cur.next;
             sum = 0;
         }

         cur.next = l1 != null ? l1 : l2;

         return dummyHead.next;
     }

    private static void printList(ListNode head){
        while(head != null){
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println("");
    }

    public static void main(String[] args) {

        ListNode l1 = new ListNode(5);
        l1.next = new ListNode(4);
        l1.next.next = new ListNode(3);
        l1.next.next.next = new ListNode(2);
        l1.next.next.next.next = new ListNode(1);

        System.out.print("Linked List 1: ");
        printList(l1);

        ListNode l2 = new ListNode(4);
        l2.next = new ListNode(3);
        l2.next.next = new ListNode(8);
        l2.next.next.next = new ListNode(1);
        l2.next.next.next.next = new ListNode(5);

        System.out.print("Linked List 2: ");
        printList(l2);

        ListNode sum = addTwoNumbers(l1, l2);
        System.out.print("Sum of Linked List l1 + l2: ");
        printList(sum);
    }
}
