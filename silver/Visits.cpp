#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

const int inf = 1e18;

void solve() {
	int n; cin >> n;
	
	vector<vector<ar<int, 2>>> radj(n);
	
	vector<int> r(n), v(n);
	
	for(int i = 0; i < n; i++) {
		cin >> r[i] >> v[i];
		r[i]--;
		
		radj[r[i]].pb({i, v[i]});
	}
	
	vector<int> used(n), dp(n);
	
	auto dfs = [&](auto &&self, int v) -> void {
		used[v] = true;
		for(auto [to, w] : radj[v]) {
			if(used[to]) continue;
			self(self, to);
			dp[v] += dp[to] + w;
		}
	};
	
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		if(!used[i]) {
			int a = r[i], b = r[r[i]];
			
			while(a != b) {
				a = r[a];
				b = r[r[b]];
			}
			
			int sum = 0, mn = inf;
			
			do {
				sum += v[a];
				mn = min(mn, v[a]);
				used[a] = true;
				a = r[a];
			} while(a != b);
			
			int res = sum - mn;
			
			do {
				dfs(dfs, a);
				res += dp[a];
				a = r[a];
			} while(a != b);
			
			ans += res;
		}
	}
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
