class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        fi=[]
        for i in lists:
            t=i
            while t!=None:
                fi.append(t.val)
                t=t.next
        fi=sorted(fi)
        if len(fi)==0:
            return None
        p=ListNode(fi.pop(0))
        t=p
        while len(fi)>0:
            p.next=ListNode(fi.pop(0))
            p=p.next
        return t
            
