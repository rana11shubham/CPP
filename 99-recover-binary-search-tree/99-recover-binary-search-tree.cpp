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
    TreeNode *start=NULL;
    TreeNode *prev;
    TreeNode *mid=NULL;
    TreeNode *last=NULL;
    void Inorder(TreeNode*root){
        if(!root)
            return;
        Inorder(root->left);
        if(prev!=NULL and (root->val<prev->val)){
            cout<<"Hello";
            // IF this is the first violation
            if(start==NULL){
                start=prev;
                 mid=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        Inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
     
        prev=new TreeNode(INT_MIN);
        Inorder(root);
        if(start && last){
            cout<<"hell";
            swap(start->val, last->val);
        }
        else if(start && mid){
             cout<<"hell";
            swap(start->val,mid->val);
        }
    }
};