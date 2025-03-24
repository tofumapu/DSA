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
NODE* CreateNode(int value)
{
    NODE *p = new NODE;
    p->info = value;
    p->pNext = NULL;
    return p;
}
void CreateList(LIST &L) {
    int n;
    cin >> n;
    while(n != -1) {
        NODE *p = CreateNode(n);
        // Add last
        if(L.pHead == NULL) {
            L.pHead = L.pTail = p;
        }
        else {
            L.pTail->pNext = p;
            L.pTail = p;
        }
        cin >> n;
    }
}
bool isSorted(NODE *pHead) {
    bool anyValueChanged = false;
    if(pHead == NULL || pHead->pNext == NULL) return false;
    while(pHead->pNext != NULL) {
        if(pHead->info > pHead->pNext->info) return false;
        else if(pHead->info < pHead->pNext->info) anyValueChanged = true, pHead = pHead->pNext;
        else pHead = pHead->pNext;
    }
    if(!anyValueChanged) return false;
    return true;
}
int main() {
    LIST *L=new LIST;

	CreateEmptyList(*L);
	CreateList(*L);

	cout << boolalpha << isSorted(L->pHead);

    return 0;
}
