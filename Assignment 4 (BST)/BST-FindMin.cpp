\

#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;
//###INSERT CODE HERE
TNODE* CreateTNODE(int x) {
    TNODE *p;
    p = new TNODE;
    if(p == NULL) {
        exit(1);
    }
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
void CreateTree(TREE &T) {
    int x;
    while(cin >> x) {
        if(x == -1)
            break;
        TNODE *p = CreateTNODE(x);
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
TNODE* FindMin(TREE T) {
    if(T == NULL) return NULL;
    while(T->pLeft != NULL) {
        T = T->pLeft;
    }
    return T;
}
int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else cout << FindMin(T)->key;
	return 0;
}
