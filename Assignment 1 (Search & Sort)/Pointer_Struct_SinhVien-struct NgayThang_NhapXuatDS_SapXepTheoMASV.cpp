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
// Nhap
void Nhap(SinhVien *&A, int &n) {
    cin >> n;
    if (n <= 0) {
        cout << "Empty List." << endl;
        return;
    }
    A = new SinhVien[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i].MASV;
        cin.ignore();
        cin.getline(A[i].HoTen, MAXN);
        cin >> A[i].NamSinh.d >> A[i].NamSinh.m >> A[i].NamSinh.y;
        cin >> A[i].GioiTinh >> A[i].DiemToan >> A[i].DiemLy >> A[i].DiemHoa;
        A[i].DTB = 1.0 * (A[i].DiemToan + A[i].DiemLy + A[i].DiemHoa) / 3;
    }
}
// Xuat
void Xuat(SinhVien *A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i].MASV << "\t" << A[i].HoTen << "\t";
        cout << A[i].NamSinh.d << "/" << A[i].NamSinh.m << "/" << A[i].NamSinh.y << "\t";
        cout << A[i].GioiTinh << "\t" << A[i].DiemToan << "\t" << A[i].DiemLy << "\t" << A[i].DiemHoa << "\t";
        cout << defaultfloat << setprecision(3) << A[i].DTB << endl;
    }
}
void SapXepGiamTheoMASV(SinhVien *A, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(A[i].MASV, A[j].MASV) < 0) {
                swap(A[i], A[j]);
            }
        }
    }
}

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    SinhVien *A;
    int n;
    Nhap(A, n);
    SapXepGiamTheoMASV(A, n);
    Xuat(A, n);
    return 0;
}
