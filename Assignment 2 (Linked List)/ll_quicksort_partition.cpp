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
void CreateEmptyList(LIST &L) {
    L.pHead = L.pTail = NULL;
}
NODE* CreateNode(int value) {
    NODE *p = new NODE;
    p->info = value;
    p->pNext = NULL;
    return p;
}

void CreateList(LIST &L) {
    int n;
    cin >> n;
    while(n != -1) {
        NODE* p = CreateNode(n);
        if(L.pHead == NULL) {
            L.pHead = L.pTail = p;
        } else {
            L.pTail->pNext = p;
            L.pTail = p;
        }   
        cin >> n;
    }
}
NODE* SeparateHead(LIST &L) {
    NODE* p = L.pHead;
    if(p == NULL) return NULL;
    L.pHead = L.pHead->pNext;
    p->pNext = NULL;
    return p;
}
void AddTail(LIST &L, NODE* p) {
    if(L.pHead == NULL) {
        L.pHead = L.pTail = p;
    } else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}
void Partition(LIST &L, LIST &L1, NODE *&pivot, LIST &L2) {
    NODE *p;
    if(L.pHead == NULL) return;
    pivot = SeparateHead(L);
    while(L.pHead != NULL) {
        p = SeparateHead(L);
        if(p->info <= pivot->info) {
            AddTail(L1, p);

        } else {
            AddTail(L2, p);
        }
    }
}
void PrintList(LIST L) {
    NODE *p = L.pHead;
    if(p == NULL) {
        cout << "Empty List.";
        cout << endl;
        return;
    }
    while(L.pHead != NULL) {
        cout << L.pHead->info << " ";
        L.pHead = L.pHead->pNext;
    }
    cout << endl;
}

int main() {
    LIST L, L1, L2;
	NODE *pivot;

	CreateEmptyList(L);
	CreateEmptyList(L1);
	CreateEmptyList(L2);
	CreateList(L);

	if(L.pHead==NULL) {
		cout << "Empty List.";
		return 0;
	}

	Partition(L, L1, pivot, L2);

	cout << pivot->info << endl;
	PrintList(L1);
	PrintList(L2);
	PrintList(L);

    return 0;
}
