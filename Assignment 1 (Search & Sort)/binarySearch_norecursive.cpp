/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>

using namespace std;
#define MAXN 150000
void NhapMang(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
int binary_search(int a[], int n, int x) {

}


int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);


    int i= binary_search(a, n, x);

    if (i==-1) std::cout << "false";
    else std::cout << "true";

    return 0;
}



