#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *pLeft;
    struct Node *pRight;
};
typedef struct Node NODE;
typedef NODE* TREE;
void initTree(TREE &t) {
    t = NULL;
}
Node* initNode(int val) {
    Node* p = new Node;
    p->data = val;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
// Hàm thêm phần tử x vào cây nhị phân
// Lưu ý:
void ThemNodeVaoCay(TREE &t, int x) {
    Node* p = new Node;
    p = initNode(x);
    if(t == NULL) {
        t = p;
    }
    else { // cây có tồn tại phần tử
        // nếu phần tử thêm vào mà nhỏ hơn Node gốc =>
        // thêm vào bên trái của cây
        if(t->data > x) {
            ThemNodeVaoCay(t->pLeft, x); // duyệt qua trái để thêm phần tử x
        }
        else if(t->data < x) {
            ThemNodeVaoCay(t->pRight, x); // duyệt qua bên phải để thêm phần tử x
        }
    }
}
void PrintNLR(TREE t) {
    // Nếu cây còn phần tử
    if(t != NULL) {
        cout << t->data << " ";
        PrintNLR(t->pLeft);
        PrintNLR(t->pRight);
    }
}
// Hàm nhập dữ liệu
void menu(TREE &t) {
    cout << "\n\n\t\t ============= Menu ============";
    cout << "\n1. Nhập dữ liệu";
    cout << "\n2. Xuất dữ liệu";
    cout << "\n0. Thoát";
    cout << "\n\n\t\t================================";
    int luachon;
    cout << "Nhap lua chon: ";
    cin >> luachon;
    if(luachon < 0 && luachon > 2) {
        cout << "\nLựa chọn không hợp lệ!";
        system("pause");
    }
    else if (luachon == 1){
        int x;
        cout << "\nNhap so nguyen x: ";
        cin >> x;
        ThemNodeVaoCay(t, x);
    }
    else if(luachon == 2) {
        // NLR
    }
    else {
        system("pause");
    }
}
int main() {
    return 0;
}
