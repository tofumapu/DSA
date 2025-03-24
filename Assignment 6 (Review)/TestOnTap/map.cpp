#include <bits/stdc++.h>
#include <map>
#include <multimap>
#include <unordered_map>
using namespace std;

// Đếm số lần xuất hiện các phần tử trong mảng , sau đó in ra tần suất
int main() {
    // map<datatype1, datatype2>
    map<int, int> mp;
    int a[1000];
    mp[100] = 200; // (100, 200)
    mp[200] = 300; // (200, 300)
    mp.insert({300, 400});
    mp.insert({400, 500});
    cout << mp.size() << endl;
    mp.erase(100);
    for(auto x : mp) {
        cout << x.first << " "  << x.second << endl;
    }
    if(mp.count(300) != 0) {
        cout << mp.count(300) << endl;
    }
    else cout << "Not Found!" << endl;
    //
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> a[i];
        mp[a[i]]++;
    }
    for(auto x : mp) {
        cout << x.first << " " << x.second << endl;
    }
    for(int i = 0; i < n; i++) {
        if(mp[a[i]] != 0) {
            cout << a[i] << " " << mp[a[i]] << endl;
            mp[a[i]] = 0;
        }
    }

    multimap<int, int> mp1;
    mp1.insert({1, 100});
    mp1.insert({2, 200});
    mp1.insert({1, 100});

    unordered_map<int, int> mp2;
}
