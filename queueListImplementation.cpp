#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node(int n) {
        val = n;
        next = nullptr;
    }
};

class Queue{
    Node *rear,*front;
    int size_;
public:
    Queue() {
        front = rear = nullptr;//front is like head and rear is like tail
        size_=0;//removing from front, adding in the rear
    }
    void enqueue(int n);
    int dequeue();
    int top();
    int size();
    void display();
};
void Queue::enqueue(int n) {
    Node* temp = new Node(n);
    if (size_ == 0) {
        front = rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
    size_++;
}
int Queue::dequeue() {
    Node* x = front;
    int v = front->val;
    front = front->next;
    delete x;
    size_--;
    return v;
}
int Queue::size() {
    return size_;
}
int Queue::top() {
    return front->val;
}
void Queue::display() {
    Node* x = front;
    while (x) {
        cout<<x->val<<" ";
        x = x->next;
    }
    cout<<endl;
}

int main() {
    Queue q;
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(2);
    q.enqueue(12);
    q.enqueue(0);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    cout<<q.size()<<endl;
    q.enqueue(13);
    q.display();
    cout<<q.size()<<endl;
}