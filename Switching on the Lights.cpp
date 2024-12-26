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

void solve() {
	int n, m; cin >> n >> m;
	map<int, map<int, vector<pair<int, int>>>> mp;
	for(int i = 0; i < m; i++) {
		int x, y, a, b; cin >> x >> y >> a >> b;
		mp[x][y].pb(a, b);
	}
	
	vector lit(n + 1, vector(n + 1, false));
	vector used(n + 1, vector(n + 1, false));
	
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	
	lit[1][1] = true;
	
	auto Lit = [&](int x, int y) {
		return x >= 1 && y >= 1 && x <= n && y <= n && lit[x][y];
	};
	
	auto Used = [&](int x, int y) {
		return x >= 1 && y >= 1 && x <= n && y <= n && used[x][y];
	};
	
	auto has = [&](int x, int y) {
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(Lit(nx, ny) && Used(nx, ny)) {
				return true;
			}
		}
		return false;
	};
	
	auto dfs = [&](auto &&dfs, int x, int y) {
		if(Used(x, y)) return;
		used[x][y] = true;
		for(auto [a, b] : mp[x][y]) {
			if(!lit[a][b]) {
				lit[a][b] = true;
				if(has(a, b)) {
					dfs(dfs, a, b);
				}
			}
		}
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(Lit(nx, ny)) {
				dfs(dfs, nx, ny);
			}
		}
	};
	dfs(dfs, 1, 1);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			ans += lit[i + 1][j + 1];
		}
	}
	cout << ans << nl;
}

signed main() {
	freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	// cin >> tt;
	while(tt--) solve();
}
