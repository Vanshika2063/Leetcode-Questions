/*
    Intuition: Better be understood with an exmaple 

    1->2->3->4->5->6->7->8, and k = 3

    1) First we will traverse the list till k nodes and reverse the first k nodes.Meanwhile we will also 
       store the k+1 node in a variable tempNext.

       Let's take temp node as a dummy node and store the head node in it.
       after forloop temp->next will point to 4 and temp will point to 3.

    2) Now we will break the link between the kth node and the k+1th node and make the kth node point to NULL.
        tempNext = temp->next;
        temp->next = NULL;

    3) We will reverse the first k nodes and store the new head in a variable newHead and connect previous head to the tempNext node.
        newHead = reverseList(head);

        3->2->1->4->5->6->7->8
    4) Now we will call the recursion to make the remaining list.
        3->2->1->6->5->4->7->8
*/


class Solution {
    // a function to reverse the node and return the head of the reversed list
    ListNode* rev(ListNode* root)
    {
        ListNode* curr = root, *prev = NULL, *currNext = NULL;
        
        while(curr)
        {
            currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
        }
        
        return prev;
    }
   
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return head;
        
        ListNode* temp = head;
        
        // Note: (i<k && temp) ensure that if the remaining nodes are less than k then we will not reverse the list and return the head as it is. 
       for(int i=1; i<k && temp; i++)
           temp = temp->next;
        
        if(!temp)
            return head;
        
        ListNode* tempNext = temp->next;
        temp->next = NULL;
        
        ListNode* h = rev(head);
        head->next = reverseKGroup(tempNext, k);
        
        return h;
    }
};
