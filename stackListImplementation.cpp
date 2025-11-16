#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node(int n) {
        next = nullptr;
        val = n;
    }
};
class Stack {
    Node* top_node;
public:
    int size;
    Stack() {
        top_node = nullptr;
        size = 0;
    }
    int top() {
        return top_node->val;
    }
    void pop() {
        if (top_node == nullptr) return;
        Node* x = top_node;
        top_node = top_node->next;
        delete x;
        size--;
    }
    void push(int n) {
        Node* temp =new Node(n);
        temp->next = top_node;
        top_node = temp;
        size++;
    }
    int& operator[](int idx) {
        if (idx >= size) throw std::out_of_range("Error");
        Node* x = top_node;
        for (int i=0;i<size-1-idx;i++) {
            x = x->next;
        }
        return x->val;
    }
    void display_helper(Node* x) {
        if (x==nullptr) return;
        display_helper(x->next);
        cout<<x->val<<" ";
    }
    void display() {
        display_helper(top_node);
        cout<<endl;
    }
};
int main() {
    Stack stackarr = Stack();
    stackarr.push(3);
    stackarr.push(5);
    stackarr.push(1);
    stackarr.push(3);
    stackarr.push(7);
    stackarr.pop();
    stackarr.pop();
    stackarr[2]++;
    stackarr.display();
}


/*
 *idx=size-1        2              1             0
 * +------+      +------+      +------+      +------+
 * |      | ---> |      | ---> |      | ---> |      | ---> nullptr
 * +------+      +------+      +------+      +------+
 *     ^
 *     |
 *   top_node
 *   here, the head node acts as top node as insertion and deletion is O(1)
 */