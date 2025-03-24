/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/


//###INSERT CODE HERE -
 /*
int main()
{
    	int v,e; //v là số đỉnh, e là số cạnh
	cin>>e>>v;
	vector<vector<int>> G (v,vector<int>(v,0)); // ma trận kề
	map<string, int> v_index; // Danh sách ánh xạ tên đỉnh --> index
	Input(v,v_index,e,G);
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int e, n;
    cin >> e >> n;
    vector<string> vertices(n);
    unordered_map<string, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> vertices[i];
        mp[vertices[i]] = i;
    }
    vector<vector<int>> mt(n, vector<int>(n, 0));
    for(int i = 0; i < e; i++) {
        string u, v;
        int weight;
        cin >> u >> v >> weight;
        int u_index = mp[u];
        int v_index = mp[v];
        mt[u_index][v_index] = weight;
    }

    int k;
    cin >> k;
    vector<string> result;
    for (int i = 0; i < n; i++) {
        int out_degree = 0, in_degree = 0;

        // Tính bậc ra (out-degree)
        for (int j = 0; j < n; j++) {
            if (mt[i][j] > 0) out_degree++;
        }

        // Tính bậc vào (in-degree)
        for (int j = 0; j < n; j++) {
            if (mt[j][i] > 0) in_degree++;
        }

        // Tổng bậc = bậc vào + bậc ra
        int total_degree = out_degree + in_degree;

        if (total_degree == k) result.push_back(vertices[i]);
    }

    if(result.empty()) cout << "No find";
    else {
        for(auto x : result) {
            cout << x << " ";
        }
    }

    return 0;
}
