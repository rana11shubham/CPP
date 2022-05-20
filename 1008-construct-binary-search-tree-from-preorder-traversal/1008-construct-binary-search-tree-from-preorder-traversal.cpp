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
    TreeNode*solve(vector<int>&preorder,int& idx,int limit){
        if(idx==preorder.size() || limit<preorder[idx])
            return NULL;
        int root_val=preorder[idx];
        idx++;
        TreeNode*root=new TreeNode(root_val);
        root->left=solve(preorder,idx,root_val);
        root->right=solve(preorder,idx,limit);
        return root;
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int id=0;
        return solve(preorder,id,INT_MAX);
        
    }
};