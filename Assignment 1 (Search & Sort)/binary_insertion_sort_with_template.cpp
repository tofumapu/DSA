/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 60000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

// Function to sort an array a[] of size 'n'
void binary_insertion_sort(int a[], int n)
{
    int i, j, k, selected;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];

//###INSERT CODE FROM HERE -
/
        int first, last, pos;
        first = 0;
        last = j;
        while(first < last) {
            if(selected > a[first]) {
                pos = first;
                break;
            }
            int mid = (first + last) / 2;
            if(a[mid] == selected)
            {
                pos = mid;
                break;
            }
            else if(a[mid] > selected) first = mid + 1;
            else last = mid - 1;
        }
        if(first >= last) {
            if(selected > a[first]) pos = first;
            else pos = first + 1;
        }

        while(j >= pos) {
            a[j + 1] = a[j];
            j--;
        }
//to here

        a[j+1] = selected;
    }
}
bool is_decending(int A[], int N) {
    for (int i = 0; i < N-1; i++)
        if(A[i]<A[i+1]) return false;
    return true;
}
void XuatMang(int A[], const int &N) {
    // std::cout << is_decending(A, N) << std::endl;
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << "\n";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    binary_insertion_sort(a, n);

    XuatMang(a, n);

    return 0;
}

