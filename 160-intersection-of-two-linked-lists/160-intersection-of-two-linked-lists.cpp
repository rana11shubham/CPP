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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1=headA;
        ListNode *temp2=headB;
        ListNode*temp=NULL;
        int n=0,m=0;
        while(temp1!=NULL){
            n++;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            m++;
            temp2=temp2->next;
        }
        int bigger=1;
        if(n<m){
            bigger=2;
        }
        int count=0,skip=max(n,m)-min(m,n);
        if(bigger==1){
            while(headA!=NULL){
                if(skip==0)
                    break;
                skip--;
                headA=headA->next;
            }
        }
        else if(bigger==2){
            while(headB!=NULL){
                if(skip==0)
                    break;
                skip--;
                headB=headB->next;
            }
        }
        while(headA!=NULL and headB!=NULL){
            if(headA==headB){
                temp=headA;
                break;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return temp;
    }
};