/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct Node {
    int data;
    Node *pNext;
};

struct LIST {
    Node *pHead;
    Node *pTail;
};

void CreateEmptyList(LIST &l) {
    l.pHead = l.pTail = NULL;
}
Node* initNode(int value) {
    Node* p = new Node;
    p->data = value;
    p->pNext = NULL;
    return p;
}
void CreateList(LIST &l) {
    int x;
    while(cin >> x) {
        if(x == -1) break;
        Node* p = initNode(x);
        if(l.pHead == NULL) {
            l.pHead = l.pTail = p;
        }
        else {
            l.pTail->pNext = p;
            l.pTail = p;
        }
    }
}
void PrintList(Node *p) {
    if(p == NULL) {
        cout << "Empty List.";
    }
    else {
        while(p != NULL) {
            cout << p->data << " ";
            p = p->pNext;
        }
    }
}
int find_pos(LIST l, int value) {
    int count_pos = 0;
    Node *p = l.pHead;
    while(p != NULL) {
        if(p->data == value) return count_pos;
        count_pos++;
        p = p->pNext;
    }
    return -1;
}
void add_afterX_1(LIST &l, int y, int x) {
    Node *p = l.pHead;
    int pos = find_pos(l, x);
    if(pos != -1) {
        int count_pos = 0;
        for(int i = 0; i < pos; i++)
            p = p->pNext;
        if(p == NULL) {
            l.pTail->pNext = p;
            l.pTail = p;
        }
        else {
            Node *q = initNode(y);
            q->pNext = p->pNext;
            p->pNext = q;
        }
    }
}
int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    LIST L;
	int X, Y;

	CreateEmptyList(L);

	CreateList(L);

	std::cin >> X >> Y;
	add_afterX_1(L, Y, X);

	PrintList(L.pHead);

    return 0;
}


