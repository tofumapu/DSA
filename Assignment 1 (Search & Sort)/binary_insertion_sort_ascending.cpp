#include <bits/stdc++.h>
#define MAXN 60000
using namespace std;

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
void XuatMang(int A[], const int &N) {
    // std::cout << is_decending(A, N) << std::endl;
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << "\n";
}
int bs_recursive(int a[], int first, int last, int x) {
    int mid = (first + last) / 2;
    if(first >= last) return (x > a[first]) ? first + 1: first; // dòng này quan trọng
    if(a[mid] == x) return mid + 1;
    else if (a[mid] < x) return bs_recursive(a, mid + 1, last, x);
    return bs_recursive(a, first, mid - 1, x);
}
void binary_insertion_sort(int a[], int n) {
    int pos, j, key, i;
    for(int i = 1; i < n; ++i) {
        key = a[i];
        j = i - 1;
        pos = bs_recursive(a, 0, j, key);
        while(j >= pos) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main() {

    int a[MAXN], n;

    NhapMang(a, n);

    binary_insertion_sort(a, n);

    XuatMang(a, n);
    cout << endl;
    cout << n << endl;
    return 0;
}
