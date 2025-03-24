/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <limits>
#include <string>
#include <string.h>
using namespace std;

#define MAXN 100

struct Ngay {
    int d, m, y;
};
struct SinhVien{
    char MASV[10];
    char HoTen[MAXN];
    Ngay NamSinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};

//###INSERT CODE HERE -
void Nhap(SinhVien *A, n)

int main() {
    SinhVien *A;
    int n, namsinh;
    cin >> namsinh;
    Nhap(A, n);
    TimTheoNamSinh(A, n, namsinh);
    return 0;
}


