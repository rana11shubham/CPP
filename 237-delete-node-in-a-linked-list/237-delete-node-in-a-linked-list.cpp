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
    void deleteNode(ListNode* node) {
        if(node==NULL)
            return;
        int next_val=node->next->val;
        node->val=next_val;
        node->next=node->next->next;
        
    }
};