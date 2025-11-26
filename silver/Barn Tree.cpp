#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n; cin >> n;
	
	vector<i64> h(n);
	
	for(auto &x : h) cin >> x;
	
	vector<vector<int>> adj(n);
	
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	i64 avg = accumulate(h.begin(), h.end(), 0ll);
	
	assert(avg % n == 0);
	
	avg /= n;
	
	for(auto &x : h) x -= avg;
	
	vector<array<i64, 3>> ops;
	
	vector<i64> sum = h;
	
	{
		auto dfs = [&](auto &&self, int v, int p) -> void {
			for(auto to : adj[v]) {
				if(to == p) continue;
				self(self, to, v);
				sum[v] += sum[to];
			}
		};
		
		dfs(dfs, 0, 0);
	}
	
	{
		auto distribute = [&](auto &&self, int v, int p) -> void {
			for(auto to : adj[v]) {
				if(to == p) continue;
				if(sum[to] >= 0) {
					self(self, to, v);
					if(sum[to]) ops.push_back({to, v, sum[to]});
				}
			}
			for(auto to : adj[v]) {
				if(to == p) continue;
				if(sum[to] < 0) {
					ops.push_back({v, to, -sum[to]});
					self(self, to, v);
				}
			}
		};
		
		distribute(distribute, 0, 0);
	}
	
	cout << ops.size() << '\n';
	
	for(auto &[u, v, w] : ops) {
		cout << u + 1 << ' ' << v + 1 << ' ' << w << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
