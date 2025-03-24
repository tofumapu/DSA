/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
#include <climits>
#include <bits/stdc++.h>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
//###INSERT CODE HERE -
void merge_2_Sorted_subArray(int *a, int left, int middle, int right) {
    int m = left;
    int n = middle + 1;
    int k = 0;
    int* temp = new int[right - left + 1];
    while(!((m > middle) && (n > right)))
    {
        if((a[m] < a[n] && m <= middle && n <= right) || (n > right))
            temp[k++] = a[m++];
        else
            temp[k++] = a[n++];
    }
    for(int i = 0; i < k; i++)
        a[left + i] = temp[i];
    delete[] temp;
}

void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

	int l=0, r=n-1, middle =(l+r)/2;
    merge_2_Sorted_subArray(a, l, middle, r);

    XuatMang(a, n);

    return 0;
}

