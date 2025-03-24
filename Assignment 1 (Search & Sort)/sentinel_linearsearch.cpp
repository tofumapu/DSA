#include <iostream>
#define MAXN 100000


void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int Sentinel_LinearSearch(int A[], int N, int X) {
    int last=A[N-1]; // Lưu lại giá trị cuối danh sách

    A[N-1]=X; // Đặt giá trị X vào cuối danh sách

    int i=0;
    while(A[i]!=X){
        i++;
    }

    //###INSERT CODE HERE -
    A[N - 1] = last; // gan' lai. gia' tri. cua phan tu cuoi cho danh sach'
    if(i < N - 1 || A[N - 1] == X) return 1; // kiem tra neu duoc tim thay hoac phan tu cuoi cung la gia tri dang tim

    return -1;
}

int main() {
    int a[MAXN], n, x;

    std::cin >> x;

    NhapMang(a, n);

    int i = Sentinel_LinearSearch(a, n, x);

    if (i==-1) std::cout << "false";
    else std::cout << "true";

    return 0;
}
