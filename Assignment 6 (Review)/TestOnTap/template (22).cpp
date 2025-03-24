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
/*
TREE CreateNode(int data) {
	TREE newNode = new TNODE;
	newNode->key = data;
	newNode->pLeft = NULL;
	newNode->pRight = NULL;
	return newNode;
}
void CreateTree(TREE &T) {
	while(true) {
		int i;
		cin >> i;
		TREE newNode = CreateNode(i);
		if(i == -1) break;
		if(T == NULL) T = newNode;
		else {
			TREE cur = T, prev = NULL;
            while (cur != NULL) {
                prev = cur;
                if (i > cur->key)
                    cur = cur->pRight;
                else
                    cur = cur->pLeft;
            }

            if (i > prev->key)
                prev->pRight = newNode;
            else
                prev->pLeft = newNode;
		}
	}
}
*/
TNODE* initNode(int val) {
    TNODE* p = new TNODE;
    p->key = val;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
void CreateTree(TREE& t, int x) {
    TNODE* p = initNode(x);
    if(t == NULL) t = p;
    else {
        if(x < t->key)
            CreateTree(t->pLeft, x);
        else if(x > t->key)
            CreateTree(t->pRight, x);
    }
}
void CreateTree(TREE& t) {
    int x;
    while(cin >> x) {
        if(x == -1) return;
        CreateTree(t, x);
    }
}
/*
int CountNode_Con(TREE t) {
    if(t == NULL) return 0;
    return 1 + CountNode_Con(t->pLeft) + CountNode_Con(t->pRight);
}
void TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(TREE t) {
    if(t == NULL) return;
    int cLeft = CountNode_Con(t->pLeft);
    int cRight = CountNode_Con(t->pRight);
    TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(t->pLeft);
    if(cLeft - cRight == 1) cout << t->key << " ";
    TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(t->pRight);
}
*/
int CountAndProcess(TREE t) {
    if (t == NULL) return 0;

    int cLeft = CountAndProcess(t->pLeft);
    int cRight = CountAndProcess(t->pRight);

    if (cLeft - cRight == 1)
        cout << t->key << " ";

    return 1 + cLeft + cRight; // Tổng số nút (gốc + trái + phải)
}

void TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(TREE t) {
    CountAndProcess(t);
}
int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)

	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(T);

	return 0;
}
