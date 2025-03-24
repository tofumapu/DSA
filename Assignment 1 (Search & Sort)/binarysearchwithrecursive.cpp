
#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

//###INSERT CODE HERE -
int binary_search_recursive(int* a, int left, int right, int x) {
	int mid = left + (right - left) / 2;
    if (left > right) return -1;
    if (a[mid] == x) return mid;
    else if (a[mid] < x) return binary_search_recursive(a, mid + 1, right, x);
	else return binary_search_recursive(a, left, mid - 1, x);
    return -1;
}
int binary_search(int* a, int n, int x) {
	return binary_search_recursive(a, 0, n - 1, x);
}
int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);


    int i = binary_search(a, n, x);

    if (i==-1) std::cout << "false";
    else std::cout << "true";

    return 0;
}

