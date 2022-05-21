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
class BSTIterator{
    public:
    stack<TreeNode*>st;
    int reverse;
    BSTIterator(TreeNode*root,int rev){
        reverse=rev;
        if(reverse){
            while(root){
                st.push(root);
                root=root->right;
            }
        }
        else{
            while(root){
                st.push(root);
                root=root->left;
            }
        }
    }
    
    int next(){
        TreeNode*temp;
        int data;
        if(reverse){
            temp=st.top();
            st.pop();
            data=temp->val;
            temp=temp->left;
            if(temp){
            st.push(temp);
            while(temp){
                st.push(temp);
                temp=temp->right;
            }
        }
    }
        else{
            temp=st.top();
            st.pop();
            data=temp->val;
            temp=temp->right;
            if(temp){
            st.push(temp);
            while(temp){
                st.push(temp);
                temp=temp->left;
            }
        }
    }
        return data;
    }
    
    
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        BSTIterator incBST(root,false);
        BSTIterator decBST(root,true);
        int l=incBST.next();
        int r=decBST.next();
        while(l<r){
            if(l+r==k){
                return true;
            }
            else if(l+r>k){
                r=decBST.next();
            }
            else{
                l=incBST.next();
            }
        }
        return false;
    }
};