
#include<bits/stdc++.h>
using namespace std;
    int n, m;
    vector<int> adj[1001];
    vector<vector<int>> v(n, vector<int>(n, 0));
    bool visited[1001];
void dfs(int u) {
    cout << u << " ";
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}
void bfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(int w : adj[v]) {
            if(!visited[w]) {
                q.push(w);
                visited[w] = true;
            }
        }
    }
}
void dijks(int u) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INT_MAX);
    dist[u] = 0;
    pq.push({0, u});
    while(!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        for(int w : adj[v]) {
            if(dist[w] > dist[v] + 1) {
                dist[w] = dist[v] + 1;
                pq.push({dist[w], w});
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
}
void findCycle(int u, int p) {
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) {
            findCycle(v, u);
        } else if(v != p) {
            cout << "YES";
            exit(0);
        }
    }
}
// Số thành phần liên thông
void findConnectedComponents() {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
}
// Số cạnh
void countEdges() {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cnt += adj[i].size();
    }
    cout << cnt / 2;
}
// Đường đi giữa 2 đỉnh
void findPath(int u, int v) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int y : adj[x]) {
            if(!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
    }
    if(visited[v]) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    dfs(1);
}

