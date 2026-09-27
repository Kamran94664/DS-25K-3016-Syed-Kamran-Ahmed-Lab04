#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertEnd(Node*& head, int value) {
    Node* n = new Node;
    n->data = value;

    if (head == NULL) {
        head = n;
        n->next = head;
        n->prev = head;
        return;
    }

    Node* last = head->prev;

    n->next = head;
    n->prev = last;
    last->next = n;
    head->prev = n;
}

void insertBeginning(Node*& head, int value) {
    insertEnd(head, value);

    if (head != NULL)
        head = head->prev;
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
    n->prev = temp;

    temp->next->prev = n;
    temp->next = n;
}

void deleteNode(Node*& head, int value) {
    if (head == NULL)
        return;

    Node* temp = head;

    do {
        if (temp->data == value) {
            if (temp->next == temp) {
                delete temp;
                head = NULL;
                return;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            if (temp == head)
                head = temp->next;

            delete temp;
            return;
        }

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
        cout << temp->data << "<->";
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
            cout << "Enter value to delete: ";
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
