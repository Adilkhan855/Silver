#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int inf = 2e9 + 5;

void solve() {
	int n, m; cin >> n >> m;
	
	vector<array<int, 4>> edges(m);
	
	for(auto &[c, r, d, s] : edges) {
		cin >> c >> r >> d >> s;
		c--, d--;
	}
	
	vector<int> a(n);
	
	for(auto &x : a) cin >> x;
	
	vector<set<array<int, 3>>> adj(n);
	
	for(auto &[c, r, d, s] : edges) {
		if(c) r -= a[c];
		adj[c].insert({r, d, s});
	}
	
	vector<int> d(n, inf);
	
	d[0] = 0;
	
	priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
	
	pq.push({d[0], 0});
	
	while(!pq.empty()) {
		auto [d_v, v] = pq.top();
		pq.pop();
		
		if(d_v != d[v]) continue;
		
		auto fr = adj[v].lower_bound({d[v], -inf, -inf});
		
		vector<array<int, 3>> del;
		
		for(auto it = fr; it != adj[v].end(); it++) {
			auto [r, to, s] = *it;
			if(d[to] > s) {
				d[to] = s;
				pq.push({d[to], to});
			}
			del.push_back(*it);
		}
		
		for(auto e : del) {
			adj[v].erase(e);
		}
	}
	
	for(int i = 0; i < n; i++) {
		if(d[i] == inf) d[i] = -1;
		cout << d[i] << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
