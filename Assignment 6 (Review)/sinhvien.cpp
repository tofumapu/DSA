/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;

struct SinhVien {
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};

void Input(SinhVien &a){
    cin.getline(a.MASV, 10);
    cin.getline(a.HoTen, 100);
    cin.getline(a.NgaySinh, 12);
    cin >> a.GioiTinh;
    cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
    a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3;
}

struct NODE {
    SinhVien data;
    NODE* pNext;
};

struct LIST {
    NODE* pHead;
    NODE* pTail;
};
void Input(LIST &L) {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i <= n; i++) {
        SinhVien sv;
        Input(sv);
        Insert_Decreasing(L, sv);
    }
}
void Insert_Decreasing(struct LIST &L, SinhVien sv) {
    struct NODE *p = new NODE;
    p->data = sv;
    p->pNext = NULL;
    if (L.pHead == NULL) {
        L.pHead = L.pTail = p;
    } else {
        if (strcmp(L.pHead->data.MASV, sv.MASV) < 0) {
            p->pNext = L.pHead;
            L.pHead = p;
        } else if (strcmp(L.pTail->data.MASV, sv.MASV) > 0) {
            L.pTail->pNext = p;
            L.pTail = p;
        } else {
            struct NODE *q = L.pHead;
            while (q->pNext != NULL && strcmp(q->pNext->data.MASV, sv.MASV) > 0) {
                q = q->pNext;
            }
            p->pNext = q->pNext;
            q->pNext = p;
        }
    }
}

void Output(struct LIST L) {
    struct NODE *p = L.pHead;
    while (p != NULL) {
        cout << p->data.MASV << " " << p->data.HoTen << " " << p->data.NgaySinh << " " << p->data.GioiTinh << " ";
        cout << fixed << setprecision(1) << p->data.DiemToan << " " << p->data.DiemLy << " " << p->data.DiemHoa << " " << p->data.DTB << endl;
        p = p->pNext;
    }
}
int main() {
    LIST L;
    L.pHead=L.pTail=NULL;
    Input(L); // DS đầu vào mặc định có thứ tự Giảm dần theo MASV

    cin.ignore();
    SinhVien sv;// Sinh viên cần chèn
    Input(sv);

    Insert_Decreasing(L, sv);

    Output(L);

    return 0;
}
