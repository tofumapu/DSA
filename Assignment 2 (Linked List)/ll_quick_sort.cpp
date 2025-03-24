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

NODE* CreateNode(int x) {
	NODE* p;
	p = new NODE;
	//if (p == NULL)
    //		exit(1);

	p->info = x;
	p->pNext = NULL;
	return p;
}
void AddTail(LIST &L, NODE* p) {
	if (L.pHead == NULL) {
		L.pHead = p;
		L.pTail = L.pHead;
	}
	else {
		L.pTail->pNext = p;
		L.pTail=p;
    }
}

void CreateEmptyList(LIST &L) {
	L.pHead = NULL;
	L.pTail = NULL;
}
void CreateList(LIST &L) {
	NODE* p;
	int x, n;
    cin >> n; // Số lượng phần tử của danh sách
	while (n-->0) {
		cin >> x;
		p = CreateNode(x);
		AddTail(L, p);
	}
}

//###INSERT CODE HERE -

NODE* SeparateHead(LIST &L) {
    NODE* p = L.pHead;
    if(p == NULL) return NULL;
    L.pHead = L.pHead->pNext;
    p->pNext = NULL;
    return p;
}
void Partition(LIST &L, LIST &L1, NODE *&pivot, LIST &L2) {
    NODE *p;
    if(L.pHead == NULL) 
    {
        cout << "Empty List.";
        return;
    }
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

void Join(LIST &L1, LIST &L2, NODE *pivot, LIST &L3) {
    // Cách của cô không full điểm được huhu ;=;
    if (L1.pHead == NULL) {
        L1.pHead = pivot;
        L1.pTail = pivot;
    } else {
        L1.pTail->pNext = pivot;
        L1.pTail = pivot;
    }

    if (L2.pHead != NULL) { // Nối List 2 vào list 1, sau đó gán list 1 cho list chính, chính là mảng base của mình
        L1.pTail->pNext = L2.pHead;
        L1.pTail = L2.pTail;
    }

}
void quicksort_ascending(LIST &L) {
    if (L.pHead == NULL || L.pHead == L.pTail) return;
    LIST L1, L2;
    CreateEmptyList(L1);
    CreateEmptyList(L2);

    NODE *pivot;
    Partition(L, L1, pivot, L2);   
    quicksort_ascending(L1);
    quicksort_ascending(L2);
    Join(L1, L2, pivot, L);
    L = L1;
}
// End-region
int length(NODE *p){
    int i=0;
    while (p) {
        i++;
        p = p->pNext;
    }
    return i;
}

void PrintList(NODE* p) {
	if (p == NULL)
    {
        cout << "Empty List.";
    }
	else {
        // cout << boolalpha << is_ascending(p) << endl;
        cout << length(p) << endl;
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
    quicksort_ascending(L);
    PrintList(L.pHead);

    return 0;
}
