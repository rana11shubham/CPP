// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000
#define MAX_SIZE 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

 // } Driver Code Ends
/*Complete the function below
Node is as follows
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class BSTIterator{
    public:
    stack<Node*>st;
    int reverse;
    BSTIterator(Node*root,int rev){
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
        Node*temp;
        int data;
        if(reverse){
            temp=st.top();
            st.pop();
            data=temp->data;
            temp=temp->left;
            if(temp){
                pushAll(temp);
            }
        }

        else{
            temp=st.top();
            st.pop();
            data=temp->data;
            temp=temp->right;
            if(temp){
            pushAll(temp);
        }
    }
        return data;
    }
    void pushAll(Node *root)
    {
        while(root)
        {
            st.push(root);
            if(!reverse) root = root->left;
            else root = root->right;
        }
    }
    
    
};
class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int k)
    {
         if(!root)
            return 0;
        BSTIterator incBST(root,false);
        BSTIterator decBST(root,true);
        int l=incBST.next();
        int r=decBST.next();
        while(l<r){
            if(l+r==k){
                return 1;
            }
            else if(l+r>k){
                r=decBST.next();
            }
            else{
                l=incBST.next();
            }
        }
        return 0;
    }
    
};

// { Driver Code Starts.
int main() {
    
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

       getline(cin, s);
       int k = stoi(s);
        //getline(cin, s);
       Solution obj;    
       cout << obj.isPairPresent(root, k) << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}
  // } Driver Code Ends