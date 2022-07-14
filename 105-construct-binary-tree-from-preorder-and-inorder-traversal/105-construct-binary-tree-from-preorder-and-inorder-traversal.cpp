/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     unordered_map<int,int>mp;
    TreeNode* helper(vector<int>&preorder,int preS,int preE,vector<int>&inorder,int inS,int inE){
        if(preS>preE)
            return NULL;
        int root_node=preorder[preS];
        int root_inpos=mp[root_node];
        int left_nodes=root_inpos-inS;
        int right_nodes=inE-root_inpos;
        TreeNode* root=new TreeNode(root_node);
        root->left=helper(preorder,preS+1,preS+left_nodes,inorder,inS,root_inpos-1);
        root->right=helper(preorder,preS+left_nodes+1,preE,inorder,root_inpos+1,inE);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();    
        if(n==0)
            return NULL;
        int i=0;
        for(auto it:inorder){
            mp[it]=i;
            i++;
        }
        TreeNode* root=helper(preorder,0,n-1,inorder,0,n-1);
        return root;
    }
};