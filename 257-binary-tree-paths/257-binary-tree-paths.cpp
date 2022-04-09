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
    vector<string>ans;
    void helper(TreeNode*root,string temp){
        if(root==NULL){
            return;
        }
        if(root->left==NULL and root->right==NULL)
        {   temp+=to_string(root->val);
            ans.push_back(temp);
            return;
        }
        
        helper(root->left,temp+to_string(root->val)+"->");
        helper(root->right,temp+to_string(root->val)+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
       helper(root,"");
        return ans;
    }
};