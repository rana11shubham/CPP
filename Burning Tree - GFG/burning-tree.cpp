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
        if(root==NULL)
            return 0;
        queue<Node*>q;
        q.push(root);
        Node*tar_ref=NULL;
        map<Node*,Node*>par;
        par[root]=NULL;
        while(q.empty()!=true){
            auto it=q.front();
            q.pop();

            if(tar_ref==NULL and it->data==target)
                tar_ref=it;
            if(it->left){
                par[it->left]=it;
                q.push(it->left);
            }
            if(it->right){
                par[it->right]=it;
                q.push(it->right);
            }
        }
        int total_time=-1;
        map<Node*,bool>mp;
        q.push(tar_ref);
        mp[tar_ref]=true;
        while(q.empty()!=true){
            
            int n=q.size();
            for(int i=0;i<n;i++){
                auto it=q.front();
                    q.pop();
                if(it->left && !mp[it->left]){
                    mp[it->left]=true;
                    q.push(it->left);
                    }
                    if(it->right && !mp[it->right]){
                    mp[it->right]=true;
                    q.push(it->right);
                    }
                    if(par[it]!=NULL && !mp[par[it]]){
                    mp[par[it]]=true;
                    q.push(par[it]);
                    }
                }
                    total_time++;
            
        }
        return total_time;
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