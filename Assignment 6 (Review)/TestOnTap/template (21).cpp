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
TREE CreateNode(int val) {
    TREE newNode = new TNODE;
    newNode->key = val;
    newNode->pLeft = NULL;
    newNode->pRight = NULL;
    return newNode;
}

void InsertNode(TREE& T, int val) {
    if (T == NULL) {
        T = CreateNode(val);
    } else if (val < T->key) {
        InsertNode(T->pLeft, val);
    } else if (val > T->key) {
        InsertNode(T->pRight, val);
    }
}

void CreateTree(TREE& T) {
    while(1) {
        int x;
        cin >> x;
        if(x != -1) {
            InsertNode(T, x);
        } else {
        break;
    }
    }
}

int CountNode_Have2Child(TREE T, int& count) {
    if(T == NULL) return 0;
    if(T->pLeft != NULL && T->pRight != NULL) count += 1;
    return count + CountNode_Have2Child(T->pLeft, count) + CountNode_Have2Child(T->pRight, count);
}
int main() {
	int count=0;
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	CountNode_Have2Child(T, count);
	cout << count;
	return 0;
}
