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
    bool isSameTree(TreeNode* r1, TreeNode* r2) {
        if(r1==NULL){
           if(r2==NULL){
               return true;
           }
           return false;
       }
       else if(r2==NULL)
        return false;
       else if(r1->val!=r2->val){
           return false;
       }
       return isSameTree(r1->left,r2->left) && isSameTree(r1->right,r2->right);
    }
};