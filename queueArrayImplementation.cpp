#include <iostream>
using namespace std;
#define max_size 5
class Queue {
    int data[max_size];
    int front,rear;
    int size_;
public:
    Queue() {
        front = -1;
        rear = -1;
        size_ = 0;
    }
    void enqueue(int n) {
        if (size_ == max_size) return;
        if (size_ == 0) {
            front = rear = 0;
            data[front] = n;
        }
        else if (size_<max_size){
            rear = (rear+1)%max_size;
            data[rear] = n;
        }
        size_++;
    }
    int dequeue() {
        int n = data[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % max_size;
        }
        size_--;
        return n;
    }
    int size(){ return size_;}
    int top(){ return data[front];}
    void display() {
        if (size_ == 0 ) return;
        for (int i = 0;i<size_;i++) {
            cout<<data[(front+i)%max_size]<<" ";
        }
        cout<<endl;
    }
};

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