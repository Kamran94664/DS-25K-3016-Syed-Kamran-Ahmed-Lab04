#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertEnd(Node*& head, int value) {
    Node* n = new Node;
    n->data = value;

    if (head == NULL) {
        head = n;
        n->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head)
        temp = temp->next;

    temp->next = n;
    n->next = head;
}

void insertBeginning(Node*& head, int value) {
    Node* n = new Node;
    n->data = value;

    if (head == NULL) {
        head = n;
        n->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head)
        temp = temp->next;

    n->next = head;
    temp->next = n;
    head = n;
}

void insertPosition(Node*& head, int value, int pos) {
    if (pos <= 1) {
        insertBeginning(head, value);
        return;
    }

    if (head == NULL)
        return;

    Node* temp = head;

    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;

        if (temp == head)
            return;
    }

    Node* n = new Node;
    n->data = value;
    n->next = temp->next;
    temp->next = n;
}

void deleteNode(Node*& head, int value) {
    if (head == NULL)
        return;

    Node* temp = head;
    Node* prev = NULL;

    do {
        if (temp->data == value) {
            if (temp == head) {
                Node* last = head;

                while (last->next != head)
                    last = last->next;

                if (head->next == head) {
                    delete head;
                    head = NULL;
                } else {
                    head = head->next;
                    last->next = head;
                    delete temp;
                }
            } else {
                prev->next = temp->next;
                delete temp;
            }
            return;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != head);
}

void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty";
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);

    cout << "HEAD";
}

int main() {
    Node* head = NULL;
    int choice, value, pos;

    do {
        cout << "\n1. Insert at end";
        cout << "\n2. Insert at beginning";
        cout << "\n3. Insert at position";
        cout << "\n4. Delete node";
        cout << "\n5. Display";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            insertEnd(head, value);
        }
        else if (choice == 2) {
            cout << "Enter value: ";
            cin >> value;
            insertBeginning(head, value);
        }
        else if (choice == 3) {
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> pos;
            insertPosition(head, value, pos);
        }
        else if (choice == 4) {
            cout << "Enter value: ";
            cin >> value;
            deleteNode(head, value);
        }
        else if (choice == 5) {
            display(head);
            cout << endl;
        }

    } while (choice != 6);

    return 0;
}
