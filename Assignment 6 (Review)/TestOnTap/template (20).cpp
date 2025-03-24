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
TNODE* initTNODE (int val) {
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
bool searchNode(TREE t, int x) {
    if(t == NULL) return false;
    else {
        if(x == t->key) return true;
        if(x > t->key) return searchNode(t->pRight, x);
        if(x < t->key) return searchNode(t->pLeft, x);
    }
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
