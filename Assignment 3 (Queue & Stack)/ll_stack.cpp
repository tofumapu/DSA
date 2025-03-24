#include <iostream>
using namespace std;
//###INSERT CODE HERE -
// Node structure
struct NODE {
    int info;
    NODE* pNext;
};
// Stack structure
struct stack {
    NODE* pHead;
    NODE* pTail;
};
// Function to create a new node
NODE* createNode(int value) {
    NODE* p = new NODE;
    if (p == NULL) {
        cout << "Memory allocation failed!" << endl;
        return NULL;
    }
    p->info = value;
    p->pNext = NULL;
    return p;
}
// Function to initialize a stack
void initStack(stack& s) {
    s.pHead = s.pTail = NULL;
}
// Function to check if a stack is empty
bool isEmpty(stack s) {
    return s.pHead == NULL;
}
// Function to push a value into a stack
void push(stack& s, int value) {
    NODE* p = createNode(value);
    if (isEmpty(s)) {
        s.pHead = s.pTail = p;
    }
    else {
        p->pNext = s.pHead;
        s.pHead = p;
    }
}
// Function to pop a value from a stack
bool pop(stack& s, int& value) {
    if (isEmpty(s)) {
        return false;
    }
    NODE* p = s.pHead;
    value = p->info;
    s.pHead = s.pHead->pNext;
    delete p;
    if (s.pHead == NULL) {
        s.pTail = NULL;
    }
    return true;
}
// Function to get the top value of a stack
bool top(stack s, int& value) {
    if (isEmpty(s)) {
        return false;
    }
    value = s.pHead->info;
    return true;
}
// Function to test push, pop, top functions
void printoutput(bool &check) {
    if(check) {
        cout << "output: ";
    }
    check = false;
}
void Testing_Push_Pop_Top_Stack(stack s) {
    int n;
    initStack(s);
    bool checkprint = true;
    while(cin >> n) {
        printoutput(checkprint);
        if(n == -1) {
            break;
        }
        if(n != 0) {
            push(s, n);
        }
        else {
            if(pop(s, n)) {
                cout << n << " ";
            }
        }
    }
    // top of current stack
    if(top(s, n)) {
        cout << "\ntop: " << n << endl;
    }
    else {
        cout << "\ntop: " << endl;
    }
}
int main() {
    stack s;
	Testing_Push_Pop_Top_Stack(s);
    return 0;
}


