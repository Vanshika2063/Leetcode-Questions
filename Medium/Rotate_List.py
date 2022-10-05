class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head==None:
            return None
        if head.next==None:
            return head
        c=0
        t=head
        while t:
            c+=1
            t=t.next
        k=k%c
        while k>0:
            p=head
            t=head
            while head.next.next!=None:
                head=head.next
            l=head.next
            head.next=None
            l.next=p
            head=l
            k-=1
        return head
