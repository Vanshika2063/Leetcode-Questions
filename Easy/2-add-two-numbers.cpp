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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            
            int carry = 0;
            int sum;
            int size = 0;

            ListNode* answer = new ListNode();

            if(l1->val == 0 && l1->next == nullptr){
                answer = l2;
            }
            else if(l2->val == 0 && l2->next == nullptr){
                answer = l1;
            }
            else{
                while(true){

                    sum = l1->val + l2->val + carry;        
                    carry = sum/10;
                    addElementToLinkedList(answer,sum%10,size);

                    if(l1->next == nullptr && l2->next == nullptr){
                        if(carry>0){
                            addElementToLinkedList(answer,carry,100);
                        }
                        break;
                    }

                    if(l1->next != nullptr){
                        l1 = l1->next;
                    }
                    else{
                        l1->val = 0;
                    }

                    if(l2->next != nullptr){
                        l2 = l2->next;
                    }
                    else{
                        l2->val = 0;
                    }
                    size++;

                }
            }

            return answer;

        }

        void addElementToLinkedList(ListNode* head,int value,int size){

            ListNode* cur = head;
            
            if(size==0){
                head->val = value;
                return;
            }

            while(cur->next != nullptr){
                cur = cur->next;
            }
            ListNode* newNode = new ListNode(value);
            cur->next = newNode;
            return;
        }


};