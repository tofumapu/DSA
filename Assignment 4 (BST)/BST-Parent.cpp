#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

void CreateEmptyTree(TREE &T)
{
    T = NULL;
}
TNODE *CreateTNode(int x)
{
    TNODE *p = new TNODE; // cấp phát vùng nhớ động
    p->key = x;           // gán trường dữ liệu của node = x
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
int Insert(TREE &T, TNODE *p)
{
    if (T)
    {
        if (T->key == p->key)
            return 0;
        if (T->key > p->key)
            return Insert(T->pLeft, p);
        return Insert(T->pRight, p);
    }
    T = p;
    return 1;
}
void CreateTree(TREE &T)
{
    CreateEmptyTree(T);
    int x;
    while (cin >> x)
    {
        if (x == -1)
            break;
        TNODE *p = CreateTNode(x);
        if (Insert(T, p) == 0)
        {
            delete p;
    }
}

bool searchNode(TREE T, int x)
{
    if (T == NULL)
        return false;
    if (T->key == x)
        return true;
    if (x < T->key)
        return searchNode(T->pLeft, x);
    return searchNode(T->pRight, x);
}

void FindParent(TREE T, const int &x)
{
    if (T != NULL)
    {
        if (!searchNode(T, x))
        {
            cout << "Not found " << x << ".";
            return;
        }
        if (T->key == x)
        {
            cout << x << " has no parent.";
            return;
        }
        TNODE *pre = NULL;
        TNODE *p = T;
        while (p != NULL)
        {
            if (x == p->key && pre != NULL)
            {
                cout << pre->key << " is parent of " << x << ".";
                return;
            }
            pre = p;
            if (x < p->key)
                p = p->pLeft;
            else
                p = p->pRight;
        }
    }
    else
    {
        cout << "Empty Tree.";
        return;
    }
}

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int x;
    cin >> x;

    FindParent(T, x);

    return 0;
}
