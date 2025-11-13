#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int v) {
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};
Node *head,*tail;

void insertAtHead(int n) {
    Node* temp = new Node(n);
    if (head == nullptr) {
        head = temp;
        tail = temp;
    }
    else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtEnd(int n) {
    Node* temp = new Node(n);
    if (tail==nullptr) {
        tail = temp;
        head = temp;
    }
    else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void forwardPrint() {
    Node* x = head;
    while (x!=nullptr) {
        cout<<x->val<<"->";
        x = x->next;
    }

    cout<<endl;
}
void backwardPrint() {
    Node* x = tail;
    while (x!=nullptr) {
        cout<<"<-"<<x->val;
        x = x->prev;
    }
    cout<<endl;
}
int main() {
    cout<<"hii"<<endl;
    insertAtHead(10);
    insertAtHead(20);
    insertAtHead(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(60);
    forwardPrint();
    backwardPrint();
}