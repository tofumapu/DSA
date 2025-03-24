#include <bits/stdc++.h>
using namespace std;
double recursive(int n)
{
    double sum = 0;
    if(n == 1) return 1.0 / 2;
    else return recursive(n - 1) + 1.0 / (2 * n);
}
int main() {
    int n;
    cin >> n;
    cout << recursive(n);
}
