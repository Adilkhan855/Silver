#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

using ll = long long;

const int inf = 1e9 + 5;

bool chmax(int &a, const int &b) {
	return a < b ? a = b, true : false;
}

void solve() {
	int n, L; cin >> n >> L;
	
	vector<int> d(n), c(n);
	
	vector<vector<int>> l(n);
	
	for(int i = 0; i < n; i++) {
		cin >> d[i] >> c[i];
		
		l[i].resize(c[i]);
		
		for(auto &x : l[i]) cin >> x;
	}
	
	vector<int> dp(1 << n);
	
	int ans = inf;
	
	for(int mask = 0; mask < (1 << n); mask++) {
		int cnt = 0;
		
		for(int i = 0; i < n; i++) {
			if(mask >> i & 1) {
				cnt++;
				continue;
			}
			
			int j = upper_bound(l[i].begin(), l[i].end(), dp[mask]) - l[i].begin();
			
			if(j > 0) {
				j--;
				chmax(dp[mask | (1 << i)], max(dp[mask], l[i][j] + d[i]));
			}
		}
		
		if(dp[mask] >= L) {
			ans = min(ans, cnt);
		}
		
		// cout << bitset<4>(mask) << ' ' << dp[mask] << nl;
	}
	
	if(ans == inf) ans = -1;
	
	cout << ans << nl;
}

signed main() {
	freopen("movie.in", "r", stdin);
	freopen("movie.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
