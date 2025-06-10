#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

template <typename A, typename B>
bool chmin(A &a, const B &b) {
	if(a > b) {
		return a = b, true;
	}
	return false;
}

template <typename A, typename B>
bool chmax(A &a, const B &b) {
	if(a < b) {
		return a = b, true;
	}
	return false;
}

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
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
	setIO("wormsort");
	int n, m; cin >> n >> m;
	
	vector<int> a(n);
	
	for(auto &x : a) cin >> x, x--;
	
	vector<ar<int, 3>> edges(m);
	
	int mx = 0;
	
	for(auto &[u, v, w] : edges) {
		cin >> u >> v >> w;
		u--, v--;
		chmax(mx, w);
	}
	
	auto check = [&](int x) {
		DSU d(n);
		for(auto [u, v, w] : edges) {
			if(w >= x) d.unite(u, v);
		}
		set<int> st;
		for(int i = 0; i < n; i++) {
			if(a[i] != i) st.emplace(d.find(i));
		}
		return st.size() <= 1;
	};
	
	int l = 0, r = mx + 1;
	
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	
	cout << (!check(l) || (check(l) && l == mx + 1) ? -1 : l) << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
