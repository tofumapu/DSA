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

void quickSort(int a*, int left, int right) {
	int pivot = a[(left + (right - left) / 2)];
	int i = left; int j = right;
	while(i <= j) {
		while(a[i] < pivot) i++;
		while(a[j] > pivot) j--;
		if(i <= j)
			swap(a[i], a[j]);
			i++, j--;
	}
	if(left < j) quickSort(a, left, j)
	if(i < right) quickSort(a, i, right)
}

void quickSort(int a*, int left, int right)  {
	int pivot = a[(left + (right - left) / 2)];
	int i = left, j = right;
	while(i <= j) {
		while(a[i] < pivot) i++;
		while(a[j] > pivot) j--;
		if(i <= j) {
			swap(a[i], a[j]);
			i++, j--;
		}
	}
	if(left < j) quickSort(a, left, j);
	if(i < right) quickSort(a, i, right);
}

void quick_sort_ascending(int a*, int n) {
	quickSort(a, 0, n - 1);
}
//###INSERT CODE HERE -
/*void quickSort(int a[], int left, int right) {
    int i, j, pivot;
    i = left;
    j = right;
    pivot = a[(left + right) / 2];
    while(i <= j) {
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i <= j) {
            hoanvi(a[i], a[j]);
            i++, j--;
        }
    }
    if(left < j) quickSort(a, left, j);
    if(i < right) quickSort(a, i, right);
}
void quick_sort_ascending(int a[], int n) {
    quickSort(a, 0, n - 1);
}*/
// 3B
void partition(int *a, int l, int r, int &i, int &j) {
    int pivot = a[(l + r) / 2];
    i = l;
    j = r;
    while(i <= j) {
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i <= j) {
            hoanvi(a[i], a[j]);
            i++;
            j--;
        }
    }
}
void quick_sort_ascending(int *a, int left, int right) {
    if (left >= right) return;
    int i, j;
    partition(a, left, right, i, j);
    quick_sort_ascending(a, left, j);
    quick_sort_ascending(a, i, right);
}
void quick_sort_ascending(int *a, int n) {
    quick_sort_ascending(a, 0, n - 1);
}
int main() {

    int a[MAXN], n;

    NhapMang(a, n);

    quick_sort_ascending(a, n);

    XuatMang(a, n);

    return 0;
}
