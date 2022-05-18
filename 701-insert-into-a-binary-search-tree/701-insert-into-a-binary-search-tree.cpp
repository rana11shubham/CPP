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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *cur=root;
        if(!root){
            root=new TreeNode(val);
            return root;
        }
        while(cur){
            if(cur->val>val){
                if(cur->left==NULL){
                    cur->left=new TreeNode(val);
                    return root;
                }
                cur=cur->left;
            }
            else{
                
                if(cur->right==NULL){
                    cur->right=new TreeNode(val);
                    return root;
                }
                cur=cur->right;
            }
            
        }
        return root;
    }
};