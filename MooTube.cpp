#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

signed main() {
	setIO("mootube");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q; cin >> n >> q;
	
	vector<vector<pair<int, int>>> adj(n + 1);
	
	for(int i = 1; i < n; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	
	int K, cnt = 0;
	
	auto dfs = [&](auto &&self, int v, int p, int rel) -> void {
		for(auto [to, w] : adj[v]) {
			if(to == p) continue;
			if(min(rel, w) >= K) {
				cnt++;
				self(self, to, v, min(rel, w));
			}
		}
	};
	
	while(q--) {
		int k, v; cin >> k >> v;
		K = k;
		cnt = 0;
		dfs(dfs, v, -1, 1e9);
		cout << cnt << nl;
	}
}
