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

const int inf = 1e18;

void solve() {
	int n, S; cin >> n >> S;
	
	vector<vector<int>> adj(n);
	
	vector<int> w(n), c(n), p(n);
	
	for(int i = 0; i < n; i++) {
		cin >> w[i] >> c[i] >> p[i];
		p[i]--;
		if(p[i] >= 0) {
			adj[p[i]].pb(i);
			// cout << i + 1 << ' ' << p[i] + 1 << nl;
		}
	}
	
	int sum = accumulate(all(w), 0ll), sumc = accumulate(all(c), 0ll);
	
	if(sum <= S) {
		cout << sumc << nl;
		return;
	}
	
	vector<int> dp(sum + 1, inf);
	
	dp[0] = 0;
	
	auto dfs = [&](auto &&self, int v) -> void {
		for(auto to : adj[v]) {
			self(self, to);
			w[v] += w[to];
			c[v] += c[to];
		}
	};
	
	dfs(dfs, 0);
	
	auto dfs2 = [&](auto &&self, int v) -> void {
		vector<int> ndp(sum + 1, inf);
		for(int j = sum; j >= w[v]; j--) {
			chmin(ndp[j], dp[j - w[v]] + c[v]);
		}
		for(auto to : adj[v]) {
			self(self, to);
		}
		// cout << v + 1 << ": " << w[v] << ' ' << c[v] << nl;
		for(int j = 0; j <= sum; j++) {
			chmin(dp[j], ndp[j]);
			// cout << (dp[j] == inf ? -1 : dp[j]) << ' ';
		}
		// cout << nl;
	};
	
	dfs2(dfs2, 0);
	
	int ans = 0;
	
	for(int i = sum - S; i <= sum; i++) {
		// cout << dp[i] << ' ';
		chmax(ans, sumc - dp[i]);
	}
	
	// cout << nl;
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// int tt; cin >> tt;
	// while(tt--) solve();
	solve();
}
