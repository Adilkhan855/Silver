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

struct dsu {
	vector<int> p, sz;
	
	dsu(int n) : p(n), sz(n, 1) {
		iota(all(p), 0);
	}
	
	int find(int v) {
		return v == p[v] ? v : p[v] = find(p[v]);
	}
	bool unite(int a, int b) {
		a = find(a);
		b = find(b);
		if(a == b) return false;
		if(sz[a] < sz[b]) swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
		return true;
	}
};

void solve() {
	setIO("closing");
	
	int n, m; cin >> n >> m;
	
	vector<pair<int, int>> edges(m);
	for(auto &[u, v] : edges) {
		cin >> u >> v;
		u--, v--;
	}
	
	vector<int> p(n), pos(n);
	
	for(int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
		pos[p[i]] = i;
	}
	
	vector<vector<int>> G(n);
	
	for(auto [u, v] : edges) {
		if(pos[u] > pos[v]) swap(u, v);
		G[u].pb(v);
	}
	
	dsu d(n);
	
	vector<int> ans(n);
	int comps = 0;
	for(int i = n - 1; i >= 0; i--) {
		int u = p[i]; comps++;
		for(auto v : G[u]) {
			comps -= d.unite(u, v);
		}
		ans[i] = (comps <= 1);
	}
	for(int i = 0; i < n; i++) {
		cout << (ans[i] ? "YES" : "NO") << nl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}
