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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL ||head->next==NULL || k==0)
            return head;
        int len=0;
        ListNode* temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        k=k%len;
        k=len-k;
        if(k==0 || k==len)
            return head;
        ListNode* target_node=NULL;
        temp=head;
        while(temp->next!=NULL){
            if(k==1){
                target_node=temp;
            }
            k--;
            len++;
            temp=temp->next;
        }
       // target_node=target_node->next;
        temp->next=head;
        head=target_node->next;
        target_node->next=NULL;
        return head;
    }
};