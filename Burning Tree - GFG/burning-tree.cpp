// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // First find the target node pointer in the binary tree
       if(root==NULL)
            return 0;
        queue<Node*>q;
        Node* target_ptr=NULL;
        q.push(root);
        unordered_map<Node*,Node*>par;
        while(q.empty()!=true){
            Node* it=q.front();
            q.pop();
            if(target_ptr==NULL and it->data==target){
                target_ptr=it;
            }
            if(it->left){
                par[it->left]=it;
                q.push(it->left);
            }
            if(it->right){
                par[it->right]=it;
                q.push(it->right);
            }
        }
        int time=-1;
        unordered_map<Node*,bool>vis;
        q.push(target_ptr);
        vis[target_ptr]=true;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto v=q.front();
                q.pop();
                if(v->left!=NULL and vis.find(v->left)==vis.end()){
                    q.push(v->left);
                    vis[v->left]=true;
                }
                if(v->right!=NULL and vis.find(v->right)==vis.end()){
                    q.push(v->right);
                    vis[v->right]=true;
                }
                if(par[v]!=NULL and vis.find(par[v])==vis.end()){
                    q.push(par[v]);
                    vis[par[v]]=true;
                }
            }
            time++;
        }
        return time;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends