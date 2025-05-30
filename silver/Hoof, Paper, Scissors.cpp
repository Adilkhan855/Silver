/*
 *    author: a.k
 *    created: idk
*/
#include <bits/stdc++.h> 
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb emplace_back
#define nl '\n'

void solve() {
	int n; cin >> n;
	vector<char> a(n);
	for(auto &i : a) cin >> i;
	vector<map<char, int>> pref(n + 1);
	
	for(int i = 0; i < n; i++) {
		pref[i + 1] = pref[i];
		pref[i + 1][a[i]]++;
	}
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		for(auto x : {'P', 'H', 'S'}) {
			for(auto y : {'P', 'H', 'S'}) {
				ans = max(ans, pref[i][x] + (pref[n][y] - pref[i][y]));
			}
		}
	}
	cout << ans << nl;
}

signed main() {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	while(tt--) solve();
}
