#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//
TNODE* initTNODE(int val) {
    TNODE* p = new TNODE;
    p->key = val;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
void CreateTree(TREE& t, int x) {
    TNODE* p = initTNODE(x);
    if(t == NULL) t = p;
    else {
        if(x < t->key) CreateTree(t->pLeft, x);
        else if(x > t->key) CreateTree(t->pRight, x);
    }
}
void CreateTree(TREE& t) {
    int x;
    while(cin >> x) {
        if(x == -1) break;
        CreateTree(t, x);
    }
}

TNODE* FindMin(TREE t) {
    if(t == NULL) return NULL;
    while(t->pLeft != NULL) {
        t = t->pLeft;
    }
    return t;
}

TNODE* FindMax(TREE t) {
    if(t == NULL) return NULL;
    while(t->pRight != NULL) {
        t = t->pRight;
    }
    return t;
}
int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else
    {
                cout << FindMin(T)->key << endl;
        cout << FindMax(T)->key;

    }

	return 0;
}
