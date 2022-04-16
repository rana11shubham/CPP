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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long int>>q;
        q.push({root,0});
        unsigned long long int ans=0;
        while(q.empty()!=true){
            int n=q.size();
            auto it=q.front();
            
            unsigned long long int cur_idx=it.second;
            unsigned long long int idx_min,idx_max;
            for(int i=0;i<n;i++){
                auto des=q.front();
                unsigned long long int idx=des.second-cur_idx;
                q.pop();
                
                if(i==n-1){
                    idx_max=idx;
                }
                if(des.first->left!=NULL)
                    q.push({des.first->left,2*idx+1});
                if(des.first->right!=NULL)
                    q.push({des.first->right,2*idx+2});
            }
            ans=max(ans,idx_max+1);
        }
        return ans;
    }
};