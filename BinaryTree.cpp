#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define COUNT 10

class Node{
  public:
    int data;
    Node *left, *right;
    Node(int data) {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
    }
};

void printTree(Node *root,int space) {
  if(root==NULL)
    return;
  space+=COUNT;

  printTree(root->right,space);

  for(int i=COUNT;i<space;i++) {
    cout<<" ";
  }

  cout<<root->data<<"\n";
  printTree(root->left,space);
}

int height(Node *node){
  if(node==NULL){
    return 0;
  }
  else {
    int lDepth = height(node->left);
    int rDepth = height(node->right);
    if(lDepth>rDepth){
      return(lDepth+1);
    }
    else{
      return (rDepth+1);
    }
  }
}
void findleafnode(Node *root){
  if (!root){
    return;
  }
  if (!root->left && !root->right ){
    cout<<root->data<<"\t";
    return;
  }
  if(root->right){
    findleafnode(root->right);
  }
  if(root->left){
    findleafnode(root->left);
  }
}

void convertTreeToItsMirror(struct Node *node){
  if(node==NULL)
    return;
  else{
    struct Node *temp;
    convertTreeToItsMirror(node->left);
    convertTreeToItsMirror(node->right);
    temp= node->left;
    node->left=node->right;
    node->right=temp;
  }
}
int main(){
  Node *root= new Node(43);
  root->left= new Node(25);
  root->right= new Node(67);
  root->left->left= new Node(14);
  root->left->right= new Node(51);
  root->right->left= new Node(26);
  root->right->right= new Node(97);
  root->left->left->left= new Node(81);
  root->left->left->right= new Node(49);
  root->left->right->left= new Node(07);
  root->left->right->right= new Node(31);
  root->right->left->left= new Node(29);
  root->right->left->right= new Node(13);
  root->right->right->left= new Node(59);
  root->right->right->right= new Node(16);
  printTree(root,0);
  cout<<"\nThe height of the given binary tree is "<<height(root)<<endl;
  cout<<"\nLeaf nodes of the tree from right to left are \n";
  findleafnode(root);
  cout<<endl;
  convertTreeToItsMirror(root);
  cout<<"\nMirror of the tree: "<<endl;
  printTree(root,0);
  cout<<endl;
  return 0;
}

