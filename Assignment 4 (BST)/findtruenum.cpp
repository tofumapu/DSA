#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("output.txt", "w", stdout);
    string output = "11248316792";
    string x1[] = {"1", "4"};
    string x2[] = {"8", "3", "5", "6"};
    string x3[] = {"6", "8", "3", "5"};
    string x4[] = {"7", "1"};
    // make a complete string from x1 to x4 by each case of number of xi
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                for(int m = 0; m < 2; m++) {
                    string s = output + x1[i] + x2[j] + x3[k] + x4[m];
                    cout << s << endl;
                }
            }
        }
    }
}