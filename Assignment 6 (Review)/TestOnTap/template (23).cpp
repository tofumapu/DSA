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
NODE* initNode(int val) {
    NODE* p = new NODE;
    p->info = val;
    p->pNext = NULL;
    return p;
}
void CreateList(LIST &l) {
    int x;
    while(cin >> x) {
        if(x == -1) break;
        NODE* p = initNode(x);
        if(l.pHead == NULL) {
            l.pHead = l.pTail = p;
        }
        else {
            l.pTail->pNext = p;
            l.pTail = p;
        }
    }
}
void Reverse_LinkedList(LIST& l) {
    NODE* prev = NULL;
    NODE* curr = l.pHead;
    NODE* next = NULL;

    while (curr != NULL) {
        next = curr->pNext;
        curr->pNext = prev;
        prev = curr;
        curr = next;
    }

    l.pTail = l.pHead;
    l.pHead = prev;
}

void PrintList(const LIST &L)  {
	NODE* p;

	if (L.pHead == NULL)
		cout << "Empty List.";
	else {
		p = L.pHead;
		while (p) {
			cout << p->info << " ";
			p = p->pNext;
		}
	}
}

int main() {
    LIST L;

	CreateEmptyList(L);
	CreateList(L);

	Reverse_LinkedList(L);

	PrintList(L);

    return 0;
}
