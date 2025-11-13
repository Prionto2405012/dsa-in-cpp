#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int v) {
        val = v;
        next = nullptr;
    }
};

class List {
public:
    Node* head;
    int size;
    List() {
        head = nullptr;
        size =0;
    };
    ~List() {
        Node *x = head;
        while (x != nullptr) {
            Node *y = x;
            x = x->next;
            delete y;
        }
        cout<<"List deleted\n";
    }
    //methods
    void display();
    void add_front(int n);
    void add_after_position(int n,int idx);
    void remove(int idx);
    List reverse();
    void add_end(int n);
    void reverse_itself();
    static void recursive_display(Node* x);
    static void recursive_reverse_display(Node* x);
};

void List::display() {
    Node *x = head;
    while (x != nullptr) {
        cout<<x->val<<"->";
        x = x->next;
    }
    cout<<endl;
}
void List::add_front(int n) {
    Node *temp = new Node(n);
    temp->next = head;
    head = temp;
    size++;
}
void List::add_after_position(int n, int idx) {
    if (idx>=size) return;
    Node* temp = new Node(n);
    Node* x = head;
    for (int i=0;i<idx;i++) {
        x = x->next;
    }
    temp->next = x->next;
    x->next = temp;
}
void List::remove(int idx) {
    if (idx>=size) return;
    if (idx==0) {
        head = head->next;
        size--;
        return;
    }
    Node *x = head;
    idx = idx - 1;
    for (int i=0;i<idx;i++) {
        x = x->next;
    }
    Node *y = x->next;
    x->next = x->next->next;
    delete y;
    size--;
    return;
}
List List::reverse() {
    List revlist = List();
    Node *x = head;
    while (x != nullptr) {
        revlist.add_front(x->val);
        x = x->next;
    }
    return revlist;
}
void List::add_end(int n) {
    Node *temp = new Node(n);
    if (head == nullptr) {
        head = temp;
        return;
    }
    Node *x = head;
    while (x->next != nullptr) {
        x = x->next;
    }
    x->next = temp;
}

void List::reverse_itself() {

}

void List::recursive_display(Node * x) {
    if (x == nullptr) {
        cout<<"\n";
        return;
    }
    cout<<x->val<<"->";
    recursive_display(x->next);
}

void List::recursive_reverse_display(Node* x) {
    if (x==nullptr) {
        cout<<"\n";
        return;
    }
    recursive_reverse_display(x->next);
    cout<<x->val<<"->";
}


int main(){
    List list = List();
    list.add_front(1);
    list.add_front(2);
    list.add_front(3);
    list.add_after_position(5,1);
    list.remove(4);
    list.add_end(6);
    list.display();
    List revlist = list.reverse();
    revlist.display();
    List::recursive_display(list.head);
    List::recursive_reverse_display(list.head);
    cout<<"\nSize "<<list.size<<endl;

}