// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
map<int,int>mp;
//Function to return a tree created from postorder and inoreder traversals.
Node*helper(int post[],int post_start,int post_end,int in[],int in_start,int in_end){
    if(post_start<post_end or in_start>in_end)
        return NULL;
    Node*root=new Node(post[post_start]);
    int root_idx=mp[root->data];
    int item_left=root_idx-in_start;
    int lpostidx=post_end+item_left-1;
    root->left=helper(post,lpostidx,post_end,in,in_start,root_idx-1);
    root->right=helper(post,post_start-1,lpostidx+1,in,root_idx+1,in_end);
    return root;
    
    
}
Node *buildTree(int in[], int post[], int n) {
    if(n==0)
        return NULL;
    for(int i=0;i<n;i++)
        mp[in[i]]=i;
    return helper(post,n-1,0,in,0,n-1);
}
