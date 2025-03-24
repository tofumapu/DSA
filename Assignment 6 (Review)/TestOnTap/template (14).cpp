/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <string.h>

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

void CreateEmptyList(LIST &l) {
    l.pHead = l.pTail = NULL;
}
NODE* initNode(int val) {
    NODE *p = new NODE;
    p->info = val;
    p->pNext = NULL;
    return p;
}
void CreateList(LIST &l) {
    int x;
    while(cin >> x) {
        if(x == -1) break;
        NODE *p = new NODE;
        p = initNode(x);
        if(l.pHead == NULL) {
            l.pHead = l.pTail = p;
        }
        else {
            l.pTail->pNext = p;
            l.pTail = p;
        }
    }

}
int count_element(NODE* p) {
    int cnt = 0;
    while(p != NULL) {
        cnt++;
        p = p->pNext;
    }
    return cnt;
}
int get_nth_node_from_head(NODE *p, int k) {
    if (p == NULL || k < 1) return -1; // Kiểm tra đầu vào không hợp lệ

    int count_ = count_element(p); // Đếm số phần tử
    if (k > count_) return -1; // Nếu k lớn hơn số phần tử, trả về -1

    int pos = 1;
    while (p != NULL && pos < k) {
        p = p->pNext;
        pos++;
    }

    return (p != NULL) ? p->info : -1; // Đảm bảo không truy cập p->info khi p == NULL
}

int main() {
    LIST L;
	int k;
	CreateEmptyList(L);
	CreateList(L);

	std::cin >> k;
	cout << get_nth_node_from_head(L.pHead, k);

    return 0;
}
