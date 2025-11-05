#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

const int inf = 1e9;

bool chmin(int &a, const int &b) {
	if(a > b) {
		return a = b, true;
	}
	return false;
}

void chmax(int &a, const int &b) {
	if(a < b) a = b;
}

struct DSU {
	vector<int> p, sz;
	
	DSU(int n) : p(n), sz(n, 1) {
		iota(all(p), 0);
	}
	
	int find(int v) {
		return v == p[v] ? v : p[v] = find(p[v]);
	}
	
	void unite(int u, int v) {
		u = find(u), v = find(v);
		if(u == v) return;
		if(sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v];
		p[v] = u;
	}
};

void solve() {
	int n, m; cin >> n >> m;
	
	DSU d(n);
	
	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		
		d.unite(u, v);
	}
	
	vector<vector<int>> comp(n);
	
	for(int i = 0; i < n; i++) {
		comp[d.find(i)].pb(i);
	}
	
	vector<int> cost0(n, inf), costn(n, inf);
	
	int d0 = d.find(0), dn = d.find(n - 1);
	
	for(int i = 0; i < n; i++) {
		int u = d.find(i);
		if(i == u) {
			for(auto &x : comp[u]) {
				auto it0 = upper_bound(all(comp[d0]), x);
				
				if(it0 != comp[d0].end()) chmin(cost0[u], *it0 - x);
				
				if(it0 != comp[d0].begin()) {
					it0--;
					chmin(cost0[u], x - *it0);
				}
				
				auto itn = upper_bound(all(comp[dn]), x);
				
				if(itn != comp[dn].end()) chmin(costn[u], *itn - x);
				
				if(itn != comp[dn].begin()) {
					itn--;
					chmin(costn[u], x - *itn);
				}
				
			}
		}
	}
	
	int ans = inf * inf;
	
	for(int i = 0; i < n; i++) {
		chmin(ans, cost0[i] * cost0[i] + costn[i] * costn[i]);
	}
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while(tt--) solve();
}
