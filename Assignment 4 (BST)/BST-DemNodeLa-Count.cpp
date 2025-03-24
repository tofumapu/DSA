/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

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
int CountLeaf(TREE T, int &count) {
    if(T == NULL) {
        return 0;
    }
    if(T->pLeft == NULL && T->pRight == NULL) {
        count++;
    }
    CountLeaf(T->pLeft, count);
    CountLeaf(T->pRight, count);
    return count;
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int count =0;
	CountLeaf(T, count);
	cout << count;
	return 0;
}
