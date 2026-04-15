#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
// #define int long long

using ll = long long;

const int N = 2e5 + 5;

int x[N], y[N], used[N], idx[N], who[N], ans[N], pref[N], jmp[N][20];
set<int> g[N];
ll sum[N][20];

void solve() {
	int n, p; cin >> n >> p;
	
	swap(n, p);
	
	map<array<int, 2>, int> mp;
	
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		mp[{x[i], y[i]}] = i;
	}
	
	map<int, vector<array<int, 2>>> xm, ym;
	
	for(int i = 0; i < n; i++) {
		xm[y[i]].push_back({x[i], i});
		ym[x[i]].push_back({y[i], i});
	}
	
	for(auto &[key, val] : xm) {
		sort(val.begin(), val.end());
		for(int i = 0; i + 1 < (int)val.size(); i += 2) {
			g[val[i][1]].emplace(val[i + 1][1]);
			g[val[i + 1][1]].emplace(val[i][1]);
		}
	}
	
	for(auto &[key, val] : ym) {
		sort(val.begin(), val.end());
		for(int i = 0; i + 1 < (int)val.size(); i += 2) {
			g[val[i][1]].emplace(val[i + 1][1]);
			g[val[i + 1][1]].emplace(val[i][1]);
		}
	}
	
	// cout << nl;
	
	// cout << "edges: " << nl;
	
	// for(int i = 0; i < n; i++) {
		// cout << i + 1 << ": ";
		
		// for(auto j : adj[i]) {
			// cout << j + 1 << ' ';
		// }
		
		// cout << nl;
	// }
	
	for(int i = 0; i < n; i++) {
		assert(g[i].size() == 2);
	}
	
	map<int, vector<array<int, 3>>> xs, ys;
	
	int timer = 0;
	
	ll tot = 0;
	
	auto dfs = [&](auto &&self, int v) -> void {
		used[v] = true;
		
		// cout << v + 1 << ' ';
		
		idx[v] = timer++;
		who[idx[v]] = v;
		
		int l, r;
		
		for(auto to : g[v]) {
			if(!used[to] || (idx[v] == n - 1 && to == 0)) {
				if(x[v] == x[to]) {
					l = y[v];
					r = y[to];
					if(l > r) swap(l, r);
					ys[x[v]].push_back({r, l, v});
				} else {
					l = x[v];
					r = x[to];
					if(l > r) swap(l, r);
					xs[y[v]].push_back({r, l, v});
				}
				
				jmp[v][0] = to;
				sum[v][0] = r - l;
				tot += sum[v][0];
			}
			
			if(!used[to]) {
				self(self, to);
			}
		}
	};
	
	// cout << "order: " << nl;
	
	dfs(dfs, 0);
	
	for(auto &[key, val] : xs) {
		sort(val.begin(), val.end());
	}
	
	for(auto &[key, val] : ys) {
		sort(val.begin(), val.end());
	}
	
	// cout << nl;
	
	// for(int i = 0; i < n; i++) {
		// cout << i + 1 << ": " << jmp[i][0] + 1 << nl;
	// }
	
	for(int i = 1; i < 20; i++) {
		for(int v = 0; v < n; v++) {
			jmp[v][i] = jmp[ jmp[v][i - 1] ][i - 1];
			sum[v][i] = sum[v][i - 1] + sum[ jmp[v][i - 1] ][i - 1];
		}
	}
	
	auto index = [&](int a, int b, int v, bool to_less) {
		if(mp.count({a, b})) return mp[{a, b}];
		
		int to = jmp[v][0];
		
		if(to_less) {
			return idx[v] == n - 1 || idx[v] < idx[to] ? v : to;
		} else {
			return idx[v] == n - 1 || idx[v] < idx[to] ? to : v;
		}
	};
	
	auto get = [&](int a, int b, bool to_less = false) {
		{ // x - axis
			auto &tmp = xs[b];
			int j = lower_bound(tmp.begin(), tmp.end(), array<int, 3>{a, -1, -1}) - tmp.begin();
			if(j < (int)tmp.size()) {
				int i = tmp[j][2];
				if(a >= tmp[j][1]) {
					int k = index(a, b, i, to_less);
					return array<int, 3>{i, k, abs(a - x[k])};
				}
			}
		}
		
		{ // y - axis
			auto &tmp = ys[a];
			int j = lower_bound(tmp.begin(), tmp.end(), array<int, 3>{b, -1, -1}) - tmp.begin();
			if(j < (int)tmp.size()) {
				int i = tmp[j][2];
				if(b >= tmp[j][1]) {
					int k = index(a, b, i, to_less);
					return array<int, 3>{i, k, abs(b - y[k])};
				}
			}
		}
		
		while(true);
		
		// assert(false);
		
		return array<int, 3>{-1, -1, -1};
	};
	
	auto add = [&](int l, int r) {
		if(l > r) {
			pref[l]++;
			pref[n]--;
			pref[0]++;
			pref[r + 1]--;
		} else {
			pref[l]++;
			pref[r + 1]--;
		}
	};
	
	// cout << nl;
	
	for(int i = 0; i < p; i++) {
		int x1, y1, x2, y2;
		
		cin >> x1 >> y1 >> x2 >> y2;
		
		auto [va, idxa, da] = get(x1, y1);
		auto [vb, idxb, db] = get(x2, y2, true);
		
		if(va == vb) {
			if(mp.count({x1, y1})) {
				ans[ mp[{x1, y1}] ]++;
			}
			if(x1 != x2 && y1 != y2) {
				if(mp.count({x2, y2})) {
					ans[ mp[{x2, y2}] ]++;
				}
			}
		} else {
			ll cur = da + db;
			
			int dist = (idx[idxb] - idx[idxa] + n) % n;
			
			for(int i = 0, u = idxa; i < 20; i++) {
				if(dist >> i & 1) {
					cur += sum[u][i];
					u = jmp[u][i];
				}
			}
			
			// cout << i + 1 << ": " << cur << ' ' << tot << ' ' << va + 1 << ' ' << vb + 1 << ' ' << idxa + 1 << ' ' << idxb + 1 << ' ' << dist << nl;
			// cout << idx[idxa] + 1 << ' ' << idx[idxb] + 1 << nl;
			
			if(cur < tot - cur) {
				// qrs.push_back({idxa, idxb});
				add(idx[idxa], idx[idxb]);
			} else {
				auto [va2, idxa2, da2] = get(x1, y1, true);
				auto [vb2, idxb2, db2] = get(x2, y2);
				// qrs.push_back({idxb2, idxa2});
				add(idx[idxb2], idx[idxa2]);
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		pref[i + 1] += pref[i];
		ans[who[i]] += pref[i];
	}
	
	for(int i = 0; i < n; i++) {
		cout << ans[i] << nl;
	}
}

/**

**/

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
