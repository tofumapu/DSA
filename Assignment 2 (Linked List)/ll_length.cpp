/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/


#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct LIST {
    int value;
    LIST* next;

    LIST(int data) : value(data), next(nullptr) {};
};
LIST* makeList(int value) {
    return new LIST(value);
}
void CreateEmptyList(LIST *L) {
    L = NULL;
}
LIST* addLast(int v, LIST* h) {
    // Create a new LIST having value = v, insert this LIST at the end of list pointed by h
    // Return a pointer to the first LIST of the resulting list
    LIST* q = makeList(v);
    if(h == NULL) {
        return q;
    }
    // else
    LIST*p = h;
    while(p->next != NULL) {
        p = p->next;
    }
    // p points to the last LIST of the list
    p->next = q;
    return h; // trả lại con trỏ về đầu danh sách
}
void CreateList(LIST *&L) {
    int prompt;
    cin >> prompt;
    while(prompt != -1)
    L = addLast(prompt, L);
}
int length(LIST* L) {
    int count_length = 0;
    while(L->next != NULL) {
        count_length++;
        L = L->next;
    }
}
int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);

    cout << length(L);

    return 0;
}
