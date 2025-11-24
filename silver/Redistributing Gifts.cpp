#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n; cin >> n;
	
	vector<vector<int>> adj(n);
	vector<vector<int>> g(n, vector<int>(n));
	
	for(int i = 0; i < n; i++) {
		bool ok = true;
		for(int j = 0; j < n; j++) {
			cin >> g[i][j];
			g[i][j]--;
			if(ok) {
				adj[i].push_back(g[i][j]);
			}
			if(g[i][j] == i) ok = false;
		}
	}
	
	vector<vector<int>> used(n, vector<int>(n));
	
	int cur = -1;
	
	auto dfs = [&](auto &&self, int v) -> void {
		used[cur][v] = true;
		for(auto to : adj[v]) {
			if(!used[cur][to]) {
				self(self, to);
			}
		}
	};
	
	for(int i = 0; i < n; i++) {
		cur = i;
		dfs(dfs, i);
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(used[g[i][j]][i]) {
				cout << g[i][j] + 1 << '\n';
				break;
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
