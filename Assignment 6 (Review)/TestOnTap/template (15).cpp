/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

// Cấu trúc của một node
struct NODE {
	int info;
	NODE* pNext;
};
// Cấu trúc của một DSLK
struct LIST {
	NODE* pHead;
	NODE* pTail;
};

//###INSERT CODE HERE -
NODE* initNode(int val) {
    NODE *p = new NODE;
    p->info = val;
    p->pNext = NULL;
    return p;
}
NODE* CreateNode(int val) {
    NODE *p = new NODE;
    p->info = val;
    p->pNext = NULL;
    return p;
}
void CreateList(LIST &l) {
    int x;
    while(cin >> x) {
        if(x == -1) break;
        NODE *p = new NODE;
        p = initNode(x);
        if(l.pHead == NULL) {
            l.pHead = l.pTail = p;
        }
        else {
            l.pTail->pNext = p;
            l.pTail = p;
        }
    }
}
void CreateEmptyList(LIST &l) {
    l.pHead = l.pTail = NULL;
}
void Join(LIST &L, LIST L1, NODE* p, LIST L2) {
    NODE* p1 = L1.pHead;
    NODE* p2 = L2.pHead;
    while(p1 != NULL) {
        if(L.pHead == NULL) {
            L.pHead = L.pTail = p1;
        }
        else {
            L.pTail->pNext = p1;
            L.pTail = p1;
        }
        p1 = p1->pNext;
    }
    if(L.pHead == NULL) {
        L.pHead = L.pTail = p;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
        while(p2 != NULL) {
        if(L.pHead == NULL) {
            L.pHead = L.pTail = p2;
        }
        else {
            L.pTail->pNext = p2;
            L.pTail = p2;
        }
        p2 = p2->pNext;
    }
}
void PrintList(LIST l) {
    NODE *p = new NODE;
    p = l.pHead;
    while(p != NULL) {
        cout << p->info << " ";
        p = p->pNext;
    }
}
int main() {
    LIST L, L1, L2;

	int x;
	NODE *pivot;

	CreateEmptyList(L);
	CreateEmptyList(L1);
	CreateEmptyList(L2);

	CreateList(L1);
	cin >> x;
	pivot=CreateNode(x);
	CreateList(L2);


	Join(L, L1, pivot, L2);
	PrintList(L);

    return 0;
}
