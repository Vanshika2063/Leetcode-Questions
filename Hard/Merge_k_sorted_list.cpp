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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int> > pq;
        int k=lists.size();
         ListNode *result=new ListNode(0);
        ListNode *ptr=result;
        if(!k)
            return NULL;
        for(int i=0;i<k;i++)
        {
            ListNode *head=lists[i];
            while(head)
            {
                pq.push(head->val);
                head=head->next;
            }
        }
        while(!pq.empty())
        {
            ListNode *temp=new ListNode(pq.top());
            ptr->next=temp;
            ptr=temp;
            pq.pop();
        }
        return result->next;
    }
};
