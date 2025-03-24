#include <iostream>
using namespace std;
#define MAXN 100

struct NODE{
    char info;
    NODE *pNext;
};

NODE *CreateNode(char x){
    NODE *p=new NODE;
    p->info=x;
    p->pNext=NULL;
    return p;
}
struct stack{
    NODE *top;
};
bool empty(const stack &s){
    return (s.top==NULL);
}
void CreateEmptyStack(stack &s){
    s.top=NULL;
}
void push(stack &s, char x){
    NODE *p=CreateNode(x);
    if(s.top==NULL) s.top= p;
    else {
        p->pNext=s.top;
        s.top=p;
    }
}
void pop (stack &s) {
    if(s.top==NULL) return;
    NODE *p= s.top;
    s.top=s.top->pNext;
    delete p;
}
char& top(stack s) {
    return s.top->info;
}


//###INSERT CODE HERE -
int precedence(char x)
{
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return 0;
}
void Input_infix(char infix[], int &ni)
{
    ni = 0;
    char c;
    while (cin >> c && c != '#')
    {
        infix[ni++] = c;
    }
    infix[ni] = '\0';
}
void infix_to_postfix(char infix[], int ni, char postfix[], int& np) {
    stack s; CreateEmptyStack(s);
    np = 0;
    for (int i = 0; i < ni; ++i) {
        char token = infix[i];
        if (isdigit(token)) {
            postfix[np++] = token;
        }
        else if (token == '(') {
            push(s, token);
        }
        else if (token == ')') {
            while (!empty(s) && top(s) != '(') {
                postfix[np++] = top(s);
                pop(s);
            }
            pop(s); 
        }
        else {
            while (!empty(s) && precedence(top(s)) >= precedence(token)) {
                postfix[np++] = top(s);
                pop(s);
            }
            push(s, token);
        }
    }
    while (!empty(s)) {
        postfix[np++] = top(s);
        pop(s);
    }
    postfix[np] = '\0';
}
void Output(char postfix[], int np) {
    for (int i = 0; i < np; ++i) {
        cout << postfix[i] << ' ';
    }
    cout << endl;
}
int main() {
    char infix[MAXN], postfix[MAXN];
    int ni, np;

    Input_infix(infix, ni);

    infix_to_postfix(infix, ni, postfix, np);

    Output(postfix, np);

    return 0;
}
