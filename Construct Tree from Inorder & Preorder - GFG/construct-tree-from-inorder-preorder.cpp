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
    unordered_map<int,int>mp;
    Node* helper(int in[],int in_s,int in_e,int pre[],int pre_s,int pre_e){
            // Base case
            if(pre_s>pre_e or in_s>in_e)
                return NULL;
            int root_val=pre[pre_s];
            Node*root=new Node(root_val);
            int root_idx=mp[root_val];
            int ele=root_idx-in_s+1;
            root->left=helper(in,in_s,root_idx-1,pre,pre_s+1,pre_s+ele-1);
            root->right=helper(in,root_idx+1,in_e,pre,pre_s+ele,pre_e);
            return root;
            
    }
    Node* buildTree(int in[],int pre[], int n)
    {  
        for(int i=0;i<n;i++)
            mp[in[i]]=i;
        Node*root=helper(in,0,n-1,pre,0,n-1);
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