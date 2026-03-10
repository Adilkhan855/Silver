#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll inf = 1e9 + 5;

void solve() {
	int N; cin >> N;
	
	ll H; cin >> H;
	
	vector<ll> h(N), w(N), s(N);
	
	for(int i = 0; i < N; i++) {
		cin >> h[i] >> w[i] >> s[i];
	}
	
	vector<ll> dp(1 << N, -inf);
	
	dp[0] = inf;
	
	ll ans = -inf;
	
	for(int mask = 0; mask < (1 << N); mask++) {
		ll hsum = 0, wsum = 0;
		
		for(int i = 0; i < N; i++) {
			if(mask >> i & 1) {
				hsum += h[i];
				wsum += w[i];
			}
		}
		
		for(int i = 0; i < N; i++) {
			if(!(mask >> i & 1)) {
				int nmask = mask | (1 << i);
				
				if(s[i] >= wsum) {
					dp[nmask] = max(dp[nmask], min(dp[mask], s[i] - wsum));
				}
			}
		}
		
		if(hsum >= H) {
			ans = max(ans, dp[mask]);
		}
	}
	
	if(ans == -inf) {
		cout << "Mark is too tall" << '\n';
		return;
	}
	
	cout << ans << '\n';
}

signed main() {
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
