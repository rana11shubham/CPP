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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode*temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        temp=head;
        int del_pos=len-n;
        if(del_pos==0){
            return head->next;
        }
        if(del_pos<0)
            return head;
        while(del_pos>1){
            temp=temp->next;
            del_pos--;
        }
        temp->next=temp->next->next;
        return head;
    }
};