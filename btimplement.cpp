#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;
};

Node* InsertNode(Node* node, int key) {
  if(node == NULL) {
    node = new Node;
    node -> data = key;
    node -> left = NULL;
    node -> right = NULL;
  }

  else if(node -> left == NULL) {
    Node* temp = new Node;
    temp -> data = key;
    node -> left = temp;
  }

  else {
    Node* temp = new Node;
    temp -> data = key;
    node -> right = temp;

  }


  return node;
}

void ViewTree(Node* node) {
  cout << node -> data;
  cout << node -> left -> data;
  cout << node -> right -> data;

}

int main() {
  Node* root = NULL;
  root = InsertNode(root, 10);
  root = InsertNode(root, 20);
  root = InsertNode(root, 30);

  ViewTree(root);
  return 0;
}
