/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <cstdlib>
#include <ctime>
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

NODE* CreateNode(int x) {
	NODE* p;
	p = new NODE;
	//if (p == NULL)
    //		exit(1);

	p->info = x;
	p->pNext = NULL;
	return p;
}

void CreateEmptyList(LIST &L) {
	L.pHead = NULL;
	L.pTail = NULL;
}

//###INSERT CODE HERE -
void CreateList(LIST &L) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int t; 
        cin >> t;
        NODE *p = CreateNode(t);
        // Add last
        if(L.pHead == NULL) {
            L.pHead = L.pTail = p;
        } else {   
            L.pTail->pNext = p;
            L.pTail = p;
        }
    }
}
NODE* SeparateHead(LIST &L) {
    if(L.pHead == NULL) return NULL;
    NODE *p = L.pHead;
    L.pHead = L.pHead->pNext;
    p->pNext = NULL;
    return p;
}
void PrintList(NODE *p) {
    if(p == NULL) {
        cout << "Empty List.";
    }
    while(p != NULL) {
        cout << p->info << " ";
        p = p->pNext;
    }
}

int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    NODE*p=SeparateHead(L);
	if( p!=NULL) cout << p->info << endl;
    PrintList(L.pHead);

    return 0;
}
