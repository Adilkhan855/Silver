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
	setIO("reduce");
	int n; cin >> n;
	
	vector<pair<int, int>> c(n);
	
	for(auto &[x, y] : c) cin >> x >> y;
	
	if(n < 3) {
		cout << 0 << nl;
		return;
	}
	
	vector<pair<int, int>> x, y;
	
	map<int, int> mx, my;
	
	for(int i = 0; i < n; i++) {
		auto [_x, _y] = c[i];
		x.pb(_x, i);
		y.pb(_y, i);
		mx[_x]++;
		my[_y]++;
	}
	sort(all(x));
	sort(all(y));
	
	int ans = (x.back().first - x[0].first) * (y.back().first - y[0].first);
	
	set<int> st;
	
	for(int i = 0, j = (int)x.size() - 1; i < min(3ll, (int)x.size()); i++, j--) {
		st.emplace(x[i].second);
		st.emplace(x[j].second);
	} 
	
	for(int i = 0, j = (int)y.size() - 1; i < min(3ll, (int)y.size()); i++, j--) {
		st.emplace(y[i].second);
		st.emplace(y[j].second);
	}
	
	auto update = [&](int i, int j, int k) {
		set<int> idx({i, j, k});
		
		vector<int> cx, cy;
		for(auto u : idx) {
			cx.pb(c[u].first);
			cy.pb(c[u].second);
		}
		
		for(auto u : cx) {
			mx[u]--;
			if(mx[u] == 0) mx.erase(u);
		}
		for(auto u : cy) {
			my[u]--;
			if(my[u] == 0) my.erase(u);
		}
		
		int lx = mx.begin() -> first, rx = (--mx.end()) -> first;
		int ly = my.begin() -> first, ry = (--my.end()) -> first;
		
		ans = min(ans, (rx - lx) * (ry - ly));
		
		for(auto u : cx) mx[u]++;
		for(auto u : cy) my[u]++;
	};
	
	vector<int> ind;
	for(auto i : st) ind.pb(i);
	
	int m = ind.size();
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < m; j++) {
			for(int k = 0; k < m; k++) {
				update(ind[i], ind[j], ind[k]);
			}
		}
	}
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}
