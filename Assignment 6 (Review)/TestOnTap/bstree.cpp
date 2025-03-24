#include <bits/stdc++.h>
using namespace std;
struct TNODE {
    int data;
    TNODE* pLeft;
    TNODE* pRight;
};
typedef TNODE* TREE
TNODE* initTNODE(int val) {
    TNODE* p = new TNODE;
    p->data = val;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
void CreateTree(TREE &t, int x) {
    TNODE* p = initTNODE(x);
    if(t == NULL) {
        t = p;
    }
    else {
        if(x < p->data) {
            CreateTree(p->pLeft, x);
        }
        else if(x > p->data) {
            CreateTree(p->pRight, x);
        }
    }
}

void CreateTree(TREE &t) {
    int x;
    while(cin >> x) {
        if (x == -1) break;
        CreateTree(T, x);
    }
}
void PrintTree(TREE t) {
    if(t != NULL) {
       if(t->pLeft != NULL) PrintTree(t->pLeft);
       cout << t->key << " ";
       if(t->pRight != NULL) PrintTree(t->pRight);
    }
    else {
        cout << "Empty Tree.";
    }
}
int main() {
    TREE T;
    T = NULL;
    CreateTree(T);
    PrintTree(T);
}
