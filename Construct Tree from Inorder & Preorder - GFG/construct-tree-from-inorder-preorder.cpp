// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    map<int,int>mp;
    Node*helper(int pre[],int pre_start,int pre_end,int in[],int in_start,int in_end){
        if(pre_start>pre_end or in_start>in_end)
            return NULL;
        Node*root=new Node(pre[pre_start]);
        int in_root= mp[pre[pre_start]];
        root->left=helper(pre,pre_start+1,in_root-in_start+pre_start,in,in_start,in_root-1);
        root->right=helper(pre,in_root-in_start+1+pre_start,pre_end,in,in_root+1,in_end);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {  

       for(int i=0;i<n;i++)
            mp[in[i]]=i;
        Node*root=helper(pre,0,n-1,in,0,n-1);
        return root;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends