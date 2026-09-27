#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int value) {
    Node* n = new Node;
    n->data = value;
    n->next = NULL;

    if (head == NULL) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
 		   temp->next = n;
}

void arrange(Node*& head) {
    Node *eHead = NULL, *eTail = NULL;
    Node *ohead = NULL, *oddTail = NULL;

    Node* temp = head;

    while (temp != NULL) {
        Node* n = new Node;
        n->data = temp->data;
        n->next = NULL;

        if (temp->data % 2 == 0) {
            if (ehead == NULL)
                ehead = eTail = n;
            else {
                eTail->next = n;
                eTail = n;
            }
        } 
		else {
            if (ohead == NULL){
		     ohead = oddTail = n;
    }
		    else {
                oddTail->next = n;
                oddTail = n;
            }
        }
        temp = temp->next;
    }

    if (ehead == NULL || ohead == NULL)
        return;

    eTail->next = ohead;
    head = ehead;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL";
}

int main() {
    Node* head = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(head, value);
    }
    arrange(head);
    cout << "Output: ";
    display(head);

    return 0;
}
