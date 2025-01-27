/**
 *    author: a.k
 *    created: idk
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb emplace_back
#define nl '\n'

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
	setIO("closing");
	
	int n, m; cin >> n >> m;
	
	vector<set<int>> G(n);
	
	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		G[u].emplace(v);
		G[v].emplace(u);
	}
	
	vector<int> used(n);
	auto dfs = [&](auto &&dfs, int v) -> void {
		used[v] = true;
		for(auto to : G[v]) {
			if(used[to]) continue;
			dfs(dfs, to);
		}
	};
	
	for(int it = 0; it < n; it++) {
		used.assign(n, 0);
		int comp = 0;
		for(int i = 0; i < n; i++) {
			if(!used[i]) {
				dfs(dfs, i);
				comp++;
			}
		}
		cout << (comp - it == 1 ? "YES" : "NO") << nl;
		int v; cin >> v;
		v--;
		for(auto to : G[v]) {
			G[to].erase(v);
		}
		G[v].clear();
	}
	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}
