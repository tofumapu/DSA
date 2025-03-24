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

//###INSERT CODE HERE -


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
