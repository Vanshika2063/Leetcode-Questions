public class DeleteNodeLinkedList {

    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x){
            val = x;
        }
    }

    public static void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
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
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        System.out.print("Given Linked List: ");
        printList(head);

        ListNode node = head;
        int n = 2; // n should be smaller than list length
        while(n-- > 0){
            node = node.next;
        }

        System.out.println("Delete node: " + node.val);
        deleteNode(node);

        System.out.print("After delete: ");
        printList(head);
    }
}
