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

struct DSU {
	vector<int> p, sz;
	int dsize;
	DSU(int n) : p(n), sz(n, 1), dsize(n) {
		iota(all(p), 0);
	}
	
	int find(int v) {
		return v == p[v] ? v : p[v] = find(p[v]);
	}
	
	void unite(int u, int v) {
		u = find(u), v = find(v);
		if(u == v) return;
		dsize--;
		if(sz[u] < sz[v]) swap(u, v);
		p[v] = u;
		sz[u] += sz[v];
	}
};

void solve() { 
	int n; cin >> n;
	
	vector<int> x(n), y(n);
	
	vector<pair<int, int>> v;
	
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		v.pb({x[i], y[i]});
	}
	
	sort(all(v));
	
	vector<int> sufm(n + 1, -1e9);
	
	for(int i = n - 1; i >= 0; i--) {
		sufm[i] = v[i].second;
		chmax(sufm[i], sufm[i + 1]);
	}
	
	// for(int i = 0; i < n; i++) {
		// cout << v[i].second << ' ';
	// }
	// cout << nl;
	
	int mn = 1e18, ans = 1;
	
	for(int i = 0; i + 1 < n; i++) {
		chmin(mn, v[i].second);
		if(mn > sufm[i + 1]) ans++;
	}
	
	cout << ans << nl;
}

signed main() {
	freopen("moop.in", "r", stdin);
	freopen("moop.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// int tt; cin >> tt;
	// while(tt--) solve();
	solve();
}
