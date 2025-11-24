#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct edge {
	int cow, to;
	
	bool is_first;
	
	edge(int cow = 0, int to = 0, bool is_first = false) : cow(cow), to(to), is_first(is_first) {}
};

void solve() {
	int n, m; cin >> n >> m;
	
	swap(n, m);
	
	vector<vector<edge>> adj(n);
	
	for(int i = 0; i < m
	; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		
		adj[u].push_back({i, v, false});
		adj[v].push_back({i, u, true});
	}
	
	vector<int> used_cycle(n), used(n), got_cereal(m);
	
	queue<int> order;
	
	int first_ver = -1, skip_edge = -1;
	
	auto dfs_cycle = [&](auto &&self, int v, int p) -> void {
		used_cycle[v] = true;
		
		for(auto nxt : adj[v]) {
			if(used_cycle[nxt.to]) {
				if(first_ver == -1 && nxt.to != p) {
					if(nxt.is_first) {
						first_ver = nxt.to;
					} else {
						first_ver = v;
					}
					
					skip_edge = nxt.cow;
					order.push(nxt.cow);
					got_cereal[nxt.cow] = true;
				}
			} else {
				self(self, nxt.to, v);
			}
		}
	};
	
	auto dfs = [&](auto &&self, int v) -> void {
		used[v] = true;
		for(auto nxt : adj[v]) {
			if(!used[nxt.to] && nxt.cow != skip_edge) {
				order.push(nxt.cow);
				got_cereal[nxt.cow] = true;
				self(self, nxt.to);
			}
		}
	};
	
	for(int i = 0; i < n; i++) {
		if(!used[i]) {
			first_ver = -1;
			skip_edge = -1;
			
			dfs_cycle(dfs_cycle, i, -1);
			
			if(first_ver != -1) {
				dfs(dfs, first_ver);
			} else {
				dfs(dfs, i);
			}
		}
	}
	
	int cnt = 0;
	
	for(int i = 0; i < m; i++) {
		if(!got_cereal[i]) {
			cnt++;
			order.push(i);
		}
	}
	
	cout << cnt << '\n';
	
	while(!order.empty()) {
		cout << order.front() + 1 << '\n';
		order.pop();
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
