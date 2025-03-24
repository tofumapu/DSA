/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct TNODE {
    int key;
    TNODE* pLeft;
    TNODE* pRight;
    int solanxuathien;
};

TNODE* CreateTNode(int x) {
    TNODE *p = new TNODE;
    if(p == NULL) {
        exit(1);
    }
    else {
        p->key = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        p->solanxuathien = 1;
    }
    return p;
}
typedef TNODE* TREE;
void CreateTree(TREE &T) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        TNODE *p = CreateTNode(x);
        if(T == NULL) {
            T = p;
        } 
        else {
            TNODE *q = T;
            TNODE *f = NULL;
            while(q != NULL) {
                f = q;
                if(x < q->key) {
                    q = q->pLeft;
                } else if(x > q->key) {
                    q = q->pRight;
                } else {
                    q->solanxuathien++;
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
int PrintTree(TNODE* T) { // inorder
    if(T != NULL) {
        PrintTree(T->pLeft);
        cout << T->key << " xuat hien " << T->solanxuathien << " lan" << endl;
        PrintTree(T->pRight);
    }
    return 0;
}
int main() {
	TNODE* T;
	T = NULL;
	CreateTree(T);
	PrintTree(T);
	return 0;
}
