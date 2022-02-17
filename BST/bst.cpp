#include <iostream>

using namespace std;

class Node {
  public:
    Node* left;
    Node* right;
    Node* parent;
    int data;

    Node(int x, Node* par) {
      left = NULL;
      right = NULL;
      parent = par;
      data = x;
    }
};

class Tree {
  public:
    Node* root;

    Tree(int data) {
      root = new Node(data, NULL);
    }

    Node* insert(int key, Node* head) {
      if (key < head -> data) {
        if (head -> left == NULL) {
          Node* temp = new Node(key, head);
          head -> left = temp;
          return head;
        }
        else {
          return insert(key, head -> left);
        }
      }
      else if (key > head -> data) {
        if (head -> right == NULL) {
          Node* temp = new Node(key, head);
          head -> right = temp;
          return head;
        }
        else {
          return insert(key, head -> right);
        }
      }
      else {
        return head;
      }
    }
    void display(Node* head) {
      if(head == NULL){
        return;
      }
      display(head->left);
      cout << head->data << " ";
      display(head->right);
    }

    void displayTree() {
      display(root);
    }

    Node* search(int key, Node* head) {
      if (head -> data == key) {
        return head;
      }
      else if (head -> data > key) {
        return search(key, head -> left);
      }
      else if (head -> data < key) {
        return search(key, head -> right);
      }

      return NULL;
    }
    void replace(int key, Node* head, Node* replacement) {
      if (head -> data == key) {
        Node* par = head -> parent;
        par -> left = replacement;
        return;
      }
      else if (head -> data > key) {
        search(key, head -> left);
        return;
      }
      else if (head -> data < key) {
        search(key, head -> right);
        return;
      }

      return;
    }

    Node* minValueNode(Node* node) {
      Node* current = node;
      while (current && current -> left != NULL) {
        current = current -> left;
      }

      return current;
    }

    Node* deleteNode(Node* node, int key) {
      if (node == NULL)
        return node;

      // If the key to be deleted is
      // smaller than the root's
      // key, then it lies in left subtree
      if (key < node->data)
        node->left = deleteNode(node->left, key);

      // If the key to be deleted is
      // greater than the root's
      // key, then it lies in right subtree
      else if (key > node->data)
        node->right = deleteNode(node->right, key);

      // if key is same as root's key, then This is the node
      // to be deleted
      else {
        // node has no child
        if (node->left==NULL and node->right==NULL)
          return NULL;

        // node with only one child or no child
        else if (node->left == NULL) {
          Node* temp = node -> right;
          free(node);
          return temp;
        }
        else if (node->right == NULL) {
          Node* temp = node->left;
          free(node);
          return temp;
        }

        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        Node* temp = minValueNode(node->right);

        // Copy the inorder successor's content to this node
        node -> data = temp->data;

        // Delete the inorder successor
        node -> right = deleteNode(node->right, temp->data);
      }
      return node;
    }

    void del(int key) {
      Node* node = search(key, root);
      node = deleteNode(node, key);
      replace(key, root, node);
    }
};


int main() {
  Tree t = Tree(10);
  int choice;

MAIN:

  cout << "\n1. Insert\n2. Display\n3. Delete\n4. Exit\n";
  cout << "Enter your choice: ";
  cin >> choice;

  switch(choice) {
    case 1:
      int data;
      cout << "\nEnter the data: ";
      cin >> data;
      t.insert(data, t.root);
      goto MAIN;
      break;

    case 2:
      t.displayTree();
      goto MAIN;
      break;

    case 3:
      int key;
      cout << "\nEnter node to delete: ";
      cin >> key;
      t.del(key);
      goto MAIN;
      break;

    case 4:
      cout << "Thanks for using!";
      break;

    default:
      cout << "Wrong choice pick again";
      goto MAIN;
  }


  return 0;
}
