#include <iostream>
using namespace std;
class Stack {
    int data[10];
    int Top;
public:
    Stack() {
        Top = -1;
    }
    int top() {
        if (Top>-1) return data[Top];
    }
    void pop() {
        Top--;
    }
    void push(int n) {
        if (Top == 9) {
            cout<<"no can't do"<<endl;
            return;
        }
        Top++;
        data[Top] = n;
    }
    int size() {
        return (Top+1);
    }
    int& operator[](int n) {
        return data[n];
    }
    void display() {
        for (int i=0;i<=Top;i++) {
            cout<<data[i]<<" ";
        }
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
 *
    +----+----+----+----+----+
    |    |    |    |    |    |
    +----+----+----+----+----+
      0    1    2    3    4
                ^
                |
                top
                size = top-1
 *
 *
 */