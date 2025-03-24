/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/


#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int data) : value(data), next(NULL) {}
};
struct LIST {
    Node* pHead;
    Node* pTail;
};
void CreateEmptyList(LIST &L) {
    L.pHead = L.pTail = NULL;
}
Node* CreateNode(int value) {
    return new Node(value);
}
void addHead(LIST &L, Node* p) {
    if(L.pHead == NULL) {
        L.pHead = L.pTail = p;
    } else {
        p->next = L.pHead;
        L.pHead = p;
    }
}
int length(LIST L) {
    int count = 0;
    while(L.pHead != NULL) {
        count++;
        L.pHead = L.pHead->next;
    }
    return count;
}
void CreateList(LIST &L) {
    int n;
    cin >> n;
    while(n != -1) {
        Node *p = CreateNode(n);
        addHead(L, p);
        cin >> n;
    }
}
int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);

    cout << length(L);

    return 0;
}

