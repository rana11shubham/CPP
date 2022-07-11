// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node* rev(struct Node* head,struct Node* prev){
        if(head==NULL)
            return prev;
        struct Node* next_node = head->next;
        head->next=prev;
        prev=head;
        head=next_node;
        rev(head,prev);
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        struct Node*head1=rev(first,NULL);
        struct Node*head2=rev(second,NULL);
        struct Node* dummy=new struct Node(0);
        int carry=0;
        struct Node* temp=dummy;
        while(head1!=NULL or head2!=NULL or carry){
            int sum=0;
            if(head1!=NULL){
                
                sum+=head1->data;
                head1=head1->next;
            }
            if(head2!=NULL){
               
                sum+=head2->data;
                head2=head2->next;
            }
            sum+=carry;
           // cout<<sum<<endl;
            struct Node* temp1=new struct Node(sum%10);
            carry=sum/10;
            temp->next=temp1;
            temp=temp->next;
        }
        
        struct Node*ans=rev(dummy->next,NULL);
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends