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
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return true;
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast->next!=NULL and  fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode*temp=slow;
        slow=slow->next;
        ListNode*prev=NULL;
        while(slow!=NULL){
            ListNode*next_p=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next_p;
        }
        while(prev!=NULL){
            if(prev->val!=head->val)
                return false;
            prev=prev->next;
            head=head->next;
        }
        return true;
    }
    
};