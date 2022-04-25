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
     TreeNode*helper(vector<int>& pre,int pre_start,int pre_end,vector<int>& in,int in_start,int in_end){
        if(pre_start>pre_end or in_start>in_end)
            return NULL;
         int root_val=pre[pre_start];
        int in_root=-1;
        TreeNode*root=new TreeNode(root_val);
         for(int i=in_start;i<=in_end;i++)
            if(root_val==in[i])
                in_root=i;
       
         int item_left=in_root-in_start;
        root->left=helper(pre,pre_start+1,pre_start+item_left,in,in_start,in_root-1);
        root->right=helper(pre,item_left+pre_start+1,pre_end,in,in_root+1,in_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        if(n==0)
            return NULL;
       // map<int,int>mp;
       // for(int i=0;i<n;i++)
       //      mp[inorder[i]]=i;
       TreeNode*root=helper(preorder,0,n-1,inorder,0,n-1);
        return root;
    }
};