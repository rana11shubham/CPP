/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         vector<int>ans;
        if(root==NULL)
            return ans;
        map<TreeNode*,TreeNode*>par;
        queue<TreeNode*>q;
        par[root]=NULL;
        q.push(root);
        while(q.empty()!=true){
            auto it=q.front();
            q.pop();
            if(it->left){
                q.push(it->left);
                par[it->left]=it;
            }
            if(it->right){
                q.push(it->right);
                par[it->right]=it;
            }
        }
        //cout<<target_ref->data<<"NELL";
        // Lets find out all the nodes whose distance is k from the target nodes
        TreeNode*target_ref=target;
        q.push(target_ref);
        map<TreeNode*,bool>vis;
        int dist=0;
        vis[target_ref]=true;
        while(q.empty()!=true){
            if(dist==k){
                break;
            }
            int n=q.size();
            for(int i=0;i<n;i++){
                auto it=q.front();
            q.pop();
            if(it->left && !vis[it->left]){
                q.push(it->left);
                vis[it->left]=true;
            }
            if(it->right && !vis[it->right]){
                q.push(it->right);
                vis[it->right]=true;
            }
            TreeNode* temp=par[it];
            if(temp!=NULL and !vis[temp]){
                q.push(temp);
                vis[temp]=true;
                }    
            }
            
            dist++;
        }
        while(q.empty()!=true){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};