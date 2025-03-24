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
void CreateEmptyList(LIST& l) {
    l.pHead = l.pTail = NULL;
}
Node* initNode(int val) {
    Node *p = new Node;
    p->data = val;
    p->pNext = NULL;
    return p;
}
void CreateList(LIST& l) {
    int x;
    while(cin >> x) {
        if(x == -1) break;
        Node *p = initNode(x);
        if(l.pHead == NULL) {
            l.pHead = l.pTail = p;
        }
        else {
            p->pNext = l.pHead;
            l.pHead = p;
        }
    }
}
int length(LIST l) {
    Node *p = l.pHead;
    int count_length = 0;
    while(p != NULL) {
        count_length++;
        p = p->pNext;
    }
    return count_length;
}

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    LIST L;
	CreateEmptyList(L);

	CreateList(L);

    cout << length(L);

    return 0;
}
