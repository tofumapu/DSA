#include <bits/stdc++.h>
using namespace std;

// Ma tran ke
// Danh sach ke
// Danh sach canh



int n, m;
int a[1000][1001];
// vector<int> adj[1001];
// adj[i] danh sách kề đỉnh i
vector<pair<int, int>> adj;
int main() {
    /*
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    */

    /*
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i++) {
        cout << i << ": ";
        for(int x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    */

    return 0;
}
