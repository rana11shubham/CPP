/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node*temp=head;
        Node* dummy=new Node(0);
        // Created dummy nodes with respect to the original ones.
        while(temp){
            Node* node=new Node(temp->val);
            Node* next_ptr=temp->next;
            temp->next=node;
            node->next=next_ptr;
            temp=temp->next->next;
        }
        temp=head;
        // Assigned random pointers to dummy nodes
        while(temp){
            Node* node=temp->next;
            if(temp->random!=NULL){
            node->random=temp->random->next;
            }
            else
                node->random=NULL;
            temp=temp->next->next;
        }
       dummy->next=head->next;
        temp=head;
        while(temp){
            Node* copy=temp->next;
            temp->next=copy->next;
            temp=temp->next;
            if(temp!=NULL)
                copy->next=temp->next;
            else copy->next=NULL;
        }
        return dummy->next;
    }
};