#include <iostream>
#include<bits/stdc++.h>
using namespace std;


struct node{
	int value;
	node *left;
	node *right;
};
class btree{
private:
    void destroy(node* leaf);
    void ins(int data,node*leaf);
    void preorder(node *leaf);
    void postorder(node *leaf);
    void inorder(node *leaf);
    int height(node *leaf);
    node *root;
public:
    btree();
    ~btree();
    void ins(int data);
    void preorder();
    void postorder();
    void inorder();
    void destroy();
    int height();

};
btree::btree(){
     root=NULL;
}
btree::~btree(){
    destroy();
}
void btree::destroy(node *leaf){
    if(leaf!=NULL){
        destroy(leaf->left);
        destroy(leaf->right);
        delete leaf;
    }
}
//----------------------------------------------------------------------------------------------------------------
void btree::ins(int data,node *leaf){
    if(leaf->value>data){
        if(leaf->left!=NULL){
            ins(data,leaf->left);
        }

        else{
            leaf->left=new node;
            leaf->left->value=data;
            leaf->left->right=NULL;
            leaf->left->left=NULL;
        }
    }
        else if(leaf->value<=data){
            if(leaf->right!=NULL){
                ins(data,leaf->right);
            }
            else{
                leaf->right=new node;
                leaf->right->value=data;
                leaf->right->right=NULL;
                leaf->right->left=NULL;
            }
        }
    }

void btree::ins(int data){
    if(root!=NULL)
        ins(data,root);
    else{
        root=new node;
        root->value=data;
        root->left=NULL;
        root->right=NULL;
    }
}
void btree::destroy(){
    destroy(root);
}
//--------------------------------------------------------------------------------------------------------------------
void btree::inorder(){
    inorder(root);
    cout<<endl;
}
void btree::inorder(node *leaf){
    if(leaf!=NULL){
        inorder(leaf->left);
        cout<<leaf->value<<"\t";
        inorder(leaf->right);
    }
}
//---------------------------------------------------------------------------------------------------------------------
void btree::preorder(){
    preorder(root);
    cout<<endl;
}
void btree::preorder(node *leaf){
    if(leaf!=NULL){
        cout<<leaf->value<<"\t";
        preorder(leaf->left);
        preorder(leaf->right);
    }
}
//-----------------------------------------------------------------------------------------------------------------------
void btree::postorder(){
    postorder(root);
    cout<<endl;
}
void btree::postorder(node *leaf){
    if(leaf!=NULL){
        postorder(leaf->left);
        postorder(leaf->right);
        cout<<leaf->value<<"\t";
    }
}
//-------------------------------------------------------------------------------------------------------------------------
int btree::height(){
    return height(root);
}
int btree::height(node *leaf){
    if(leaf==NULL) return 0;
    else if(leaf!=NULL){
        return(1+max(height(leaf->left),height(leaf->right)));
    }
}
int main(){
    //btree b;
    btree *tree = new btree();
	tree->ins(10);
	tree->ins(6);
	tree->ins(14);
	tree->ins(5);
	tree->ins(8);
	tree->ins(11);
	tree->ins(18);
    cout<<"PreOrder of given tree\n";
	tree->preorder();
	cout<<"InOrder of given tree\n";
	tree->inorder();
	cout<<"PostOrder of given tree\n";
	tree->postorder();
	cout<<"The height is :"<<tree->height();

	delete tree;

}
