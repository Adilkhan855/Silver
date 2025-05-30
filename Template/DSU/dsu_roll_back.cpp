#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'
 
template <typename A, typename B>
bool chmin(A &a, const B &b) {
	if( a > b ) {
		return a = b, true;
	}
	return false;
}
 
template <typename A, typename B>
bool chmax(A &a, const B &b) {
	if( a < b ) {
		return a = b, true;
	}
	return false;
}
 
struct DSU {
	int cnt;
	vector<int> p, sz;
	stack<ar<int, 2>> upd;
	
	DSU(int n) : cnt(n - 1), p(n), sz(n, 1) {
		iota(all(p), 0);
	}
	
	int find(int v) {
		return v == p[v] ? v : find(p[v]);
	}
	
	bool unite(int u, int v) {
		u = find(u), v = find(v);
		if(u == v) return false;
		if(sz[u] < sz[v]) swap(u, v);
		p[v] = u;
		sz[u] += sz[v];
		upd.push({u, v});
		cnt--;
		return true;
	}
	
	void roll_back() {
		assert(!upd.empty());
		auto [u, v] = upd.top();
		upd.pop();
		p[v] = v;
		sz[u] -= sz[v];
		cnt++;
	}
};
 
void solve() {
	int n, m, q; cin >> n >> m >> q;
	
	vector<ar<int, 2>> queries;
	
	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		queries.pb({u, v});
	}
	
	for(int i = 0; i < q; i++) {
		int t, u, v; cin >> t >> u >> v;
		queries.pb({u, v});
	}
	
	q = queries.size();
	
	vector<ar<int, 4>> init;
	map<ar<int, 2>, int> st;
	
	for(int i = 0; i < q; i++) {
		auto [u, v] = queries[i];
		if(u > v) swap(u, v); // IMPORTANT!!!
		if(st.count({u, v})) {
			init.pb({st[{u, v}], i - 1, u, v});
			st.erase({u, v});
		} else {
			st[{u, v}] = i;
		}
	}
	
	for(auto [key, val] : st) {
		init.pb({val, q - 1, key[0], key[1]});
	}
	
	DSU d(n + 1);
	
	vector<int> ans(q);
	
	auto Dnc = [&](auto &&self, int l, int r, vector<ar<int, 4>> ops) -> void {
		vector<ar<int, 4>> ops_child;
		
		int cnt = 0;
		
		for(auto [ll, rr, u, v] : ops) {
			if(l >= ll && r <= rr) {
				cnt += d.unite(u, v);
			} else if(l > rr || r < ll) {
				// nothing
			} else {
				ops_child.pb({ll, rr, u, v});
			}
		}
		
		if(l == r) {
			ans[l] = d.cnt;
		} else {
			int m = (l + r) >> 1;
			self(self, l, m, ops_child);
			self(self, m + 1, r, ops_child);
		}
		
		while(cnt--) d.roll_back();
	};
	
	Dnc(Dnc, 0, q - 1, init);
	
	for(int i = m - 1; i < q; i++) {
		cout << ans[i] << ' ';
	}
	cout << nl;
}
 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
