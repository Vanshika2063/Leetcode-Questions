class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *headnode = new ListNode();
        ListNode *result = headnode ;
        
        int carry = 0 , sum = 0   ; 
        
        while(l1 || l2){
            
             sum = 0 ; 
            
            if(l1){
                sum += l1->val; 
                l1 = l1->next ;
            }
            
            if(l2){
                sum += l2->val; 
                l2 = l2->next ; 
            }
            
            sum += carry ; 
            
            carry = sum > 9 ? 1: 0; 
            sum %= 10 ; 
            
            ListNode *dNode = new ListNode(sum);
            headnode->next = dNode ; 
            headnode = dNode ;
            
        }
        
        if(carry){
            ListNode *dNode = new ListNode(carry);
            headnode->next = dNode; 
            return result->next ;
        }
        return result->next ; 
    }
};
