#include <bits/stdc++.h>
using namespace std;

int main() {
    int e, n;
    cin >> e >> n;
    unordered_map<string, int> mp;
    vector<vector<int>> mt(n, vector<int>(n, 0));
    vector<string> vertices(n);
    for (int i = 0; i < n; i++) {
        cin >> vertices[i];
        mp[vertices[i]] = i;
    }
    for(int i = 0; i < e; i++) {
        string u, v;
        int weight;
        cin >> u >> v >> weight;
        int u_index = mp[u];
        int v_index = mp[v];
        mt[u_index][v_index] = weight;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << mt[i][j] << " ";
        }
        cout << endl;
    }
}
