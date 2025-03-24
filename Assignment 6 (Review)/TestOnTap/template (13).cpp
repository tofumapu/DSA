/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct Node {
    int data;
    Node* pNext;
};
Node* initNode(int val) {
    Node *p = new Node;
    p->data = val;
    p->pNext = NULL;
    return p;
}
struct LIST {
    Node *pHead;
    Node *pTail;
};
void CreateEmptyList(LIST &l) {
    l.pHead = l.pTail = NULL;
}
void CreateList(LIST &l) {
    int x;
    while(cin >> x) {
        if(x == -1) break;
        Node *p = new Node;
        p = initNode(x);
        if(l.pHead == NULL) {
            l.pHead = l.pTail = p;
        }
        else {
            p->pNext = l.pHead;
            l.pHead = p;
        }
    }
}
int count_element(Node *p) {
    int cnt = 0;
    while(p != NULL) {
        cnt++;
        p = p->pNext;
    }
    return cnt;

}
void Print_Middle(LIST l) {
    if(l.pHead == NULL) {
        cout << "Empty List.";
        return;
    }
    int element = count_element(l.pHead);
    int middle = element / 2;
    Node *p = l.pHead;
    int init = 0;
    while(init != middle) {
        p = p->pNext;
        init++;
    }
    cout << p->data;
}
int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    Print_Middle(L);

    return 0;
}


