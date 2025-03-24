#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//###INSERT CODE HERE -
TNODE* CreateTNode(int x) {
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
bool searchNode(TREE T, int x) {
    if(T == NULL) return false;
    if(T->key == x) return true;
    if(x < T->key) return searchNode(T->pLeft, x);
    return searchNode(T->pRight, x);
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;
	if(searchNode(T, x)) cout << "true";
	else cout << "false";
	return 0;
}
