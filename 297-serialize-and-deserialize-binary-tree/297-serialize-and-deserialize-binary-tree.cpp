/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
   
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         string ans="";
       if(root==NULL)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty()!=true){
            auto it=q.front();
            q.pop();
            if(it==NULL){
                ans.append("#,");
            }
            else ans.append(to_string(it->val)+",");
            if(it!=NULL){
            q.push(it->left);
            q.push(it->right);
        }
        }
        cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n=data.length();
        if(n==0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode*root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(q.empty()!=true){
            auto it=q.front();
            q.pop();
            getline(s,str,',');
            if(str!="#"){
                it->left=new TreeNode(stoi(str));
                q.push(it->left);
            }
            else{
                it->left=NULL;
            }
            getline(s,str,',');
            if(str!="#"){
                it->right=new TreeNode(stoi(str));
                q.push(it->right);
            }
            else{
                it->right=NULL;
            
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));