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
    TreeNode* helper(TreeNode*root){
        if(root->left==NULL)
            return root->right;
        else if(root->right==NULL)
            return root->left;
        TreeNode*cur=root;
        cur=cur->left;
        while(cur->right){
            cur=cur->right;
        }
        cur->right=root->right;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        else if(root->val==key)
            return helper(root);
        TreeNode*cur=root;
        while(cur){
            if(cur->val>key){
                if(cur->left and cur->left->val==key){
                    cur->left=helper(cur->left);
                    return root;
                }
                cur=cur->left;
            }
            else{
                    if(cur->right and cur->right->val==key){
                    cur->right=helper(cur->right);
                    return root;
                }
                cur=cur->right;
            }            
        }
        return root;
    }
};