#include <iostream>
using namespace std;

struct NODE {
    int info;
    NODE *pNext;
};

struct LIST {
    NODE *pHead;
    NODE *pTail;
};

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
        NODE *p = CreateNode(n);
        if(L.pHead == NULL) {
            L.pHead = L.pTail = p;
        } else {
            L.pTail->pNext = p;
            L.pTail = p;
        }
        cin >> n;
    }
}

void PrintList(LIST L) {
    NODE *p = L.pHead;
    while(p != NULL) {
        cout << p->info << " ";
        p = p->pNext;
    }
    cout << endl;
}

void Partition(LIST &L, LIST &L1, NODE* &pivot, LIST &L2) {
    if(L.pHead == NULL) return;

    pivot = L.pHead;
    NODE *p = L.pHead->pNext;

    while(p != NULL) {
        NODE *next = p->pNext;
        if(p->info < pivot->info) {
            p->pNext = L1.pHead;
            L1.pHead = p;
            if(L1.pTail == NULL) L1.pTail = p;
        } else {
            p->pNext = L2.pHead;
            L2.pHead = p;
            if(L2.pTail == NULL) L2.pTail = p;
        }
        p = next;
    }
    L.pHead = L.pTail = NULL;
}

int main() {
    LIST L, L1, L2;
    NODE *pivot;

    CreateEmptyList(L);
    CreateEmptyList(L1);
    CreateEmptyList(L2);
    CreateList(L);

    if(L.pHead == NULL) {
        cout << "Empty List.";
        return 0;
    }

    Partition(L, L1, pivot, L2);

    if (pivot != NULL) {
        cout << pivot->info << endl;
    } else {
        cout << "Pivot is NULL" << endl;
    }

    PrintList(L1);
    PrintList(L2);
    PrintList(L);

    return 0;
}