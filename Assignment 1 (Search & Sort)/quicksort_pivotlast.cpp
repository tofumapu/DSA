/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}
void hoanvi(int &x, int &y){
    int temp=x;
    x=y;
    y=temp;
}


//###INSERT CODE HERE -
int medianofThree(int *a, int left, int right) {
    int mid = left + (right - left) / 2;
    if(a)
}
int partition(int *a, int left, int right) {
    int pivot = a[right];
    int id = left - 1;
    for(int i = left; i < right; i++) {
        if(a[i] < pivot) {
            id++;
            hoanvi(a[id], a[i]);
        }
    }
    id++;
    hoanvi(a[id], a[right]);
    return id;
}
void quickSort(int *a, int left, int right) {
    if(left < right) {
        int id_pivot = partition(a, left, right);
        quickSort(a, left, id_pivot - 1);
        quickSort(a, id_pivot + 1, right);
    }
}

void quick_sort_ascending(int *a, int n) {
    quickSort(a, 0, n - 1);
}

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int a[MAXN], n;

    NhapMang(a, n);

    quick_sort_ascending(a, n);

    XuatMang(a, n);

    return 0;
}

