#include <iostream>
#include <queue>
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
private:
    static Node* insert_helper(int n,Node* x);
    static void infix_helper(Node* x);
    static bool search_helper(int n,Node* x);
    static int height_helper(Node* x);
    static bool bst_inrange(Node* x,int min,int max);
    static Node* Del(Node* current_root,int n);
public:
    Node* root;
    Tree() {
        root = nullptr;
    }
    void insert_lp(int n);
    void insert_rec(int n);
    void infix();
    bool search_lp(int n);
    bool search_rec(int n);
    int max();
    int min();
    int height();
    void level_order();//BFS
    bool is_bst();
    void Delete(int n);
    static Node* GetSuccessor(Node* x, int n);
};

void Tree::insert_lp(int n) {
    Node* temp = new Node(n);
    if (root == nullptr) {
        root = temp;
        return;
    }
    Node* x = root;
    while (x != nullptr) {
        if (n < x->val) {
            if (x->left == nullptr) {
                x->left = temp;
                return;
            }
            x = x->left;
        }
        else if (n > x->val) {
            if (x->right == nullptr) {
                x->right = temp;
                return;
            }
            x = x->right;
        }
    }
}
void Tree::insert_rec(int n) {
    root = insert_helper(n,root);
}
Node* Tree::insert_helper(int n,Node* x) {
    if (x == nullptr) {
        x = new Node(n);
    }
    else if (n<x->val) {
        x->left = insert_helper(n,x->left);
    }
    else {
        x->right = insert_helper(n,x->right);
    }
    return x;
}
void Tree::infix() {
    infix_helper(root);
    cout<<endl;
}
void Tree::infix_helper(Node *x) {
    if (x==nullptr) return;
    infix_helper(x->left);
    cout<<x->val<<" ";
    infix_helper(x->right);
}
bool Tree::search_rec(int n) {
    return search_helper(n,root);
}
bool Tree::search_helper(int n, Node *x) {
    if (x == nullptr) return false;
    else if (n == x->val) return true;
    else if (n < x->val) return  search_helper(n,x->left);
    else if (n>x->val) return search_helper(n,x->right);
}
bool Tree::search_lp(int n) {
    Node* x = root;
    while (x!=nullptr) {
        if (n == x->val) return true;
        else if (n < x->val) x = x->left;
        else if (n > x->val) x = x->left;
    }
    if (x==nullptr) return false;
}
int Tree::max() {
    Node* x = root;
    if (x == nullptr) throw "vag shalar put";
    while (x->right != nullptr) {
        x = x->right;
    }
    return x->val;
}
int Tree::min() {
    Node* x = root;
    if (x == nullptr) throw "vag shalar put";
    while (x->left != nullptr) {
        x = x->left;
    }
    return x->val;
}
int Tree::height() {
    return height_helper(root);
}
int Tree::height_helper(Node *x) {
    if (x == nullptr) return -1;
    int lh = height_helper(x->left);
    int rh = height_helper(x->right);
    return ((lh>rh)?lh:rh)+1;
}
void Tree::level_order() {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (q.size()) {
        Node* x = q.front();
        cout<<x->val<<" ";
        if (x->left) q.push(x->left);
        if (x->right) q.push(x->right);
        q.pop();
    }
    cout<<endl;
}
bool Tree::is_bst() {
    int MAX = ~(1<<(sizeof(int)*8-1));//2^31-1
    int MIN = (1<<(sizeof(int)*8-1));//-2^31
    return bst_inrange(root,MIN,MAX);
}
bool Tree::bst_inrange(Node* x,int min, int max) {
    if (x == nullptr) return true;
    return (min < x->val && x->val < max && bst_inrange(x->left,min,x->val) && bst_inrange(x->right, x->val,max));
}
void Tree::Delete(int n) {
    root = Del(root, n);
}
//baldao bujhi nai
Node *Tree::Del(Node *current_root, int n) {
    if (current_root == nullptr) return current_root;
    if (n < current_root-> val) current_root->left = Del(current_root->left,n);
    else if (n > current_root-> val) current_root->right = Del(current_root->right,n);
    else if (n == current_root->val) {
        //case 1: no child
        if (current_root->left == nullptr && current_root->right == nullptr) {
            delete current_root;
            current_root = nullptr;
        }
        //case 2: one child
        else if (current_root->left == nullptr) {
            Node* addressOfNext = current_root->right;
            delete current_root;
            current_root = addressOfNext;

        }
        else if (current_root->right == nullptr) {
            Node* addressOfNext = current_root->left;
            delete current_root;
            current_root = addressOfNext;
        }
        //case 3: 2 child
        else {
            //finding min in right subtree
            Node* x = current_root->right;
            while (x->left != nullptr) {
                x = x->left;
            }
            current_root->val = x->val;
            current_root->right = Del(current_root->right,current_root->val);

        }
    }
    return current_root;
}
Node* Tree::GetSuccessor(Node* subtree_root, int n) {
    if (subtree_root == nullptr) return nullptr;
    //finding n
    Node* x = subtree_root;
    while (true) {
        if (x == nullptr) throw "Vag shalarput";
        if (x->val == n) break;
        if (x->val > n) x = x->left;
        else x = x->right;
    }
    //now x->val == n
    //if it has right node, then the leftest node of the right node will be successor;
    if (x->right) {
        x = x->right;
        while (x->left!=nullptr) {
            x = x->left;
        }
        return x;
    }
    else {
        //it doesnt have right child,
    }

}


int main() {
    Tree t;
    t.insert_lp(5);
    t.insert_lp(3);
    t.insert_lp(7);
    t.insert_lp(1);
    t.insert_lp(9);
    t.infix();
    Tree t2;
    t2.insert_rec(5);
    t2.insert_rec(3);
    t2.insert_rec(7);
    t2.insert_rec(9);
    t2.insert_rec(1);
    t2.insert_rec(-1);
    t2.infix();
    cout<<t2.search_rec(4)<<"\n";
    cout<<t2.search_rec(3)<<"\n";
    cout<<t2.search_lp(4)<<"\n";
    cout<<t2.search_lp(3)<<"\n";
    cout<<t2.max()<<"\n";
    cout<<t2.min()<<"\n";
    cout<<t2.height()<<'\n';
    t2.infix();
    //cout<<t2.is_bst();
    t2.Delete(5);
    t2.infix();
    t2.level_order();
}

