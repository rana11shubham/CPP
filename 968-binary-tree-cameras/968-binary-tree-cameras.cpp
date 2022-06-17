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
    int camera=0;
    int solve(TreeNode*root){
        // If root is null
        if(root==NULL){
            return 1;
        }
        // find the values for left and right subtrees
        int l=solve(root->left);
        int r=solve(root->right);
        // If any one of them are not covered then we must assign a camera
        if(l==3 or r==3){
            camera++;
            return 2;
        }
        // If any one of them has camera then no need to assign camera on root
        if(l==2 or r==2)
            return 1;
        // If none of them is covreing the current node ask parent to take camera
        return 3;
    }
    int minCameraCover(TreeNode* root) {
        // These states are telling us that whether you are covered(1) / has camera on you(2) / ask to cover(3)
        if(solve(root)==3){
            return ++camera;
        }
        return camera;
    }
    
};