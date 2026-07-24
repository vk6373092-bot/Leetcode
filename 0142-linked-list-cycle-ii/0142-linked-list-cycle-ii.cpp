/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // this is again hare and turtoise 
        ListNode * slow=head;
        ListNode * fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;// because fast take 2 steps
            if(slow==fast){


                ListNode * temp=head;
                while(temp!=slow){
                    temp=temp->next;
                    slow=slow->next;
                }
                return temp;
            }
        }
        return NULL;
    }
};