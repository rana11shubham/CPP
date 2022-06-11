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
    ListNode* reverse(ListNode* prev, ListNode* cur){
        if(cur==NULL)
            return prev;
        ListNode*next_node=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next_node;
        return reverse(prev,cur);
    }
    ListNode* reverseList(ListNode* head) {
    // ListNode* prev=NULL;
    // ListNode*temp=head;
    // while(temp!=NULL){
    //     ListNode*cur=temp->next;
    //     temp->next=prev;
    //     prev=temp;
    //     temp=cur;
    // }
    //     head=prev;
    //     return prev;
    // }
     ListNode* prev=NULL;
     head=reverse(prev,head);
     return head;   
    }
};