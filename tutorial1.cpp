// Write a program to make a singly linked list
// Insert a new node and display the linked list
// Maximum no. of elements is 10

#include <iostream>
using namespace std;

class Node {
        public:
                Node* next;
                int data;

                Node(int data) {
                        next = NULL;
                        this->data = data;
                }
};

class List {
public:
        Node* head = NULL;

        void insertNode(int data) {
                Node* newNode = new Node(data);

                if (head == NULL) {
                        head = newNode;
                        return;
                }

                Node* temp = head;
                while (temp -> next != NULL) {
                        temp = temp -> next;
                }

                temp->next = newNode;
        }

        void deleteNode(int nodeOffSet) {
                Node *temp = head, *temp2 = NULL;



        }

        void printList() {
                Node* temp = head;
                if (head == NULL) {
                        cout << "List Empty" << endl;
                        return;
                }

                while (temp != NULL) {
                        cout << temp->data << " ";
                        temp = temp->next;
                }
        }
};

int main() {
        int choice;
        List l;

        RETURNLOOP:
        cout << "\nMENU" << endl;
        cout << "1. Insert Element" << endl;
        cout << "2. Display List" << endl;
        cout << "3. Exit" << endl;

        cin >> choice;

        switch (choice){
                case 1:
                        int data;
                        cout << "Enter the data of the new node: ";
                        cin >> data;
                        l.insertNode(data);
                        goto RETURNLOOP;
                        break;

                case 2:
                        l.printList();
                        goto RETURNLOOP;
                        break;

                case 3:
                        break;

                default:
                        goto RETURNLOOP;
                        break;
        }

       return 0; 
}
