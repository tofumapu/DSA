#include <bits/stdc++.h>
using namespace std;

void func1(int n, stack<int> &s) {
    while(n > 0) {
        int du = n % 2;
        s.push(du);
        n /= 2;
    }
}
void insertionSort(int *a, int n) {
    for(int i = 1; i < n; i++) {
        int key = a[i];
        int pos = i - 1;
        while(pos >= 0 && a[pos] > key) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = key;
    }
}
int binary_search_(int *a, int left, int right, int x) {
    int start = 0;
    int endd = n - 1;
    while (start <= endd) {
        int mid = left + (right - left) / 2;
        if(a[mid] == x) return mid;
        else if(a[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;

}
void selectionSort(int *a, int n) {
    for(int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < n; j++) {
            if(a[min_idx] > a[j]) min_idx = j;
        }
        swap(a[min_idx], a[i]);
    }
}

void quickSort(int *a, int n) {

}
int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int x;
    map<int, int> mp;
    cin >> x;
    for(int i = 1; i <= x; i++) {
        long long n;
        cin >> n;
        stack<int> s;
        func1(n, s);
        while(!s.empty()) {
            cout << s.top();
            s.pop();
            s.
        }
        cout << endl;
    }
}
