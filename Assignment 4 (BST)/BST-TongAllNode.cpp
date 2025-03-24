#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//###INSERT CODE HERE -
int Sum = 0;
TNODE* CreateTNode(int x) {
    TNODE *p;
    p = new TNODE;
    if(p == NULL) {
        exit(1);
    }
    else {
        p->key = x;
        p->pLeft = NULL;
        p->pRight = NULL;
    }
    return p;
}
void CreateTree(TREE &T) {
    int x;
    while(cin >> x) {
        if(x == -1)
            break;
        TNODE *p = CreateTNode(x);
        if(T == NULL) {
            T = p;
        } else {
            TNODE *q = T;
            TNODE *f = NULL;
            while(q != NULL) {
                f = q;
                if(x < q->key) {
                    q = q->pLeft;
                } else if(x > q->key) {
                    q = q->pRight;
                } else {
                    delete p;
                    p = NULL;
                    break;
                }
            }
            if(p != NULL) {
                if(x < f->key) {
                    f->pLeft = p;
                } else {
                    f->pRight = p;
                }
            }
        }
    }
}
int SumNode(TREE T) { // Find Sum of All Node
    if(T == NULL) return 0;
    else 
        return T->key + SumNode(T->pLeft) + SumNode(T->pRight);
}


int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	cout << SumNode(T);
	return 0;
}

