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

    
    
unordered_map<int,int>mp;
Node* helper(int in[],int in_s,int in_e,int post[],int post_s,int post_e){
    if(in_s>in_e or post_s<post_e)
        return NULL;
    int root_val=post[post_s];
    int root_idx=mp[root_val];
    int ele=root_idx-in_s+1;
    Node* root=new Node(root_val);
    root->right=helper(in,root_idx+1,in_e,post,post_s-1,post_e+ele-1);
    root->left=helper(in,in_s,root_idx-1,post,post_e+ele-2,post_e);
    return root;
}
Node *buildTree(int in[], int post[], int n) {
  for(int i=0;i<n;i++)
    mp[in[i]]=i;
  Node*root=helper(in,0,n-1,post,n-1,0);
}
