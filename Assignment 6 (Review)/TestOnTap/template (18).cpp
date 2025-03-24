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
TNODE* initTNODE(int val) {
    TNODE* p = new TNODE;
    p->key = val;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
void CreateTree(TREE &T, int x) {
    if (x == -1) return;
    TNODE *p = initTNODE(x);
    if (T == NULL) {
        T = p;  // Nếu cây rỗng, gán nút mới làm gốc
    } else {
        if (x < T->key) {
            CreateTree(T->pLeft, x);  // Đệ quy sang cây con trái
        } else if (x > T->key) {
            CreateTree(T->pRight, x); // Đệ quy sang cây con phải
        }
    }
}

void CreateTree(TREE &T) {
    int x;
    while (cin >> x) {
        if (x == -1) break; // Kết thúc khi nhập -1
        CreateTree(T, x);   // Gọi hàm chèn giá trị vào cây
    }
}
void PrintTree(TREE T) { // LNR
    if(T != NULL) {
        if(T->pLeft != NULL) PrintTree(T->pLeft);
        cout << T->key << " ";
        if(T->pRight != NULL) PrintTree(T->pRight);
    }
    else {
        cout << "Empty Tree.";
    }
}
int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	PrintTree(T);
	return 0;
}
