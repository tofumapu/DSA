#include <iostream>
using namespace std;

struct NODE{
    int info;
    NODE *pNext;
};
struct queue{
    NODE *front;
    NODE *back;
};
NODE *CreatNode(int x){
    NODE *p=new NODE;
    p->info=x;
    p->pNext=NULL;
    return p;
//###INSERT CODE HERE -
}
void init(queue &q) {
    q.front=NULL;
    q.back=NULL;
}
void printfront(queue q){
    if(q.front!=NULL){
        cout<<q.front->info;
    }
}
void printback(queue q) {
    if(q.back!=NULL){
        cout<<q.back->info;
    }
}
bool isEmpty(queue q){
    return q.front==NULL;
}
void enQueue(queue &q, int x){
    NODE *p=CreatNode(x);
    if(isEmpty(q)){
        q.front=q.back=p;
    }
    else{
        q.back->pNext=p;
        q.back=p;
    }
}
int deQueue(queue &q, int &x){
    if(isEmpty(q))
        return 0;
    NODE *p = q.front;
    x = p->info;
    q.front = q.front->pNext;
    if(q.front==NULL){
        q.back=NULL;
    }
    return 1;
}
void output(bool &check) {
    if(check) {
        cout << "output: ";
    }
    check = false;
}
void createQueue(queue &q){
    bool checkprint = true;
    init(q);
    int n;
    while(cin >> n) {
        output(checkprint);
        if(n == -1) {
            break;
        }
        else if(n == 0) { // deQueue
            int x;
            if(deQueue(q, x)) {
                cout << x << " ";
            }
        }
        else {
            enQueue(q, n);
        }
    }
    cout << "\n";
    cout << "front: ";
    printfront(q);
    cout << "\n";
    cout << "back: ";
    printback(q);

}

int main() {
    queue q;
	createQueue(q);
    return 0;
}
