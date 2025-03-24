/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int binary_search_first_occurrence(int a[], int n, int x) {
    int first = 0;
    int last = n - 1;
    int pos = -1;
    while(first <= last) {
        int mid = (first + last) / 2;
        if(a[mid] == x) {
            if(mid == 0 || a[mid - 1] != x)
            {
                return mid;
            }
            else last = mid - 1;
        }
        else if(a[mid] < x) first = mid + 1;
        else last = mid - 1;
    }
    return pos;
}

int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_first_occurrence(a, n, x);

    return 0;
}


