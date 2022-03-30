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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        	vector<vector<int>>ans;
    	stack<TreeNode*>s1,s2;
    	s1.push(root);
    	bool leftToright=true;
        vector<int>level_ans;
    	while(s1.empty()!=true){
    	    TreeNode*temp=s1.top();
    	    s1.pop();
    	    level_ans.push_back(temp->val);
    	    if(leftToright){
    	        if(temp->left!=NULL)
    	            s2.push(temp->left);
    	        if(temp->right!=NULL)
    	            s2.push(temp->right);
    	    }
    	    else{
    	        if(temp->right!=NULL)
    	            s2.push(temp->right);
    	        if(temp->left!=NULL)
    	            s2.push(temp->left);
    	    }
    	    if(s1.empty()){
    	        leftToright=!leftToright;
    	        swap(s1,s2);
                ans.push_back(level_ans);
                level_ans.clear();
    	    }
    	}
    	return ans;
    }
};