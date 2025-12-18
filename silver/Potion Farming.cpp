#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n; cin >> n;
	
	vector<int> p(n);
	
	for(auto &x : p) {
		cin >> x;
		x--;
	}
	
	vector<vector<int>> adj(n);
	
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> ch(n);
	
	int cnt = 0;
	
	for(int i = 1; i < n; i++) {
		if(adj[i].size() == 1) {
			cnt++;
			ch[i] = 1;
		}
	}
	
	vector<int> mark(n);
	
	for(int i = 0; i < cnt; i++) {
		mark[p[i]]++;
	}
	
	int ans = 0;
	
	auto dfs = [&](auto &&self, int v, int p) -> void {
		for(auto to : adj[v]) {
			if(to == p) continue;
			self(self, to, v);
			ch[v] += ch[to];
		}
		
		int mn = min(ch[v], mark[v]);
		
		ans += mn;
		
		ch[v] -= mn;
	};
	
	dfs(dfs, 0, 0);
	
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
