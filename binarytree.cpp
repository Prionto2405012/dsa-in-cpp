#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int n) {
        val = n;
        left = right = nullptr;
    }
};

class Tree {
public:
    Node* root;
    Tree() {
        root = nullptr;
    }
    void insert_lp(int n);
    Node* insert_rec(int n);
    bool search_lp();

};