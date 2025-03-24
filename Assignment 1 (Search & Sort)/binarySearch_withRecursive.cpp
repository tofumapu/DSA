/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
for
while
goto
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
int binary_search_recursive(int a[], int first, int last, int x) {
    int mid = (first + last) / 2;
    if(first > last) return -1;
    if(a[mid] == x) return mid;
    else if(a[mid] < x) return binary_search_recursive(a, mid + 1, last, x);
    else if(a[mid] > x) return binary_search_recursive(a, first, mid - 1, x);
}
int binary_search(int a[], int n, int x) {
    int first = 0;
    int last = n - 1;
    int mid = (first + last) / 2;
    if(a[mid] == x) return mid;
    else if(a[mid] < x) return binary_search_recursive(a, mid + 1, last, x);
    else return binary_search_recursive(a, first, mid - 1, x);
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

