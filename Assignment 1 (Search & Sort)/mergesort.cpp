/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <climits>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
#include <vector>
//###INSERT CODE HERE -
void merge(int a[], int left, int middle, int right) {
    if (left > right) return;
    std::vector<int> x(a + left, a + middle + 1);
    std::vector<int> y(a + middle +1, a + right + 1);
    int i = 0, j = 0;
    while (i < x.size() && j < y.size()) {
        if (x[i] <= y[j]) {
            a[left] = x[i];
            i++; left++;
        }
        else {
            a[left] = y[j];
            j++; left++;
        }
    }
    while (i < x.size()) {
        a[left] = x[i];
        i++; left++;
    }
    while (j < y.size()) {
        a[left] = y[j];
        j++; left++;
    }
}

void mergeSortRange(int input[], int from, int to) {
    if (from < to) {
        int middle = (from + to) / 2;
        mergeSortRange(input, from, middle);
        mergeSortRange(input, middle + 1, to);
        merge(input, from, middle, to);
    }
}

void mergeSort(int input[], int n) {
    mergeSortRange(input, 0, n - 1);
}

void XuatMang(int A[], const int &N) {
    // std::cout << is_ascending(A, N) << std::endl;
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}


int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    mergeSort(a, n);

    XuatMang(a, n);

    return 0;
}
