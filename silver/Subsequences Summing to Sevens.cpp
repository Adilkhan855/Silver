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
	vector<int> a(n);
	for(auto &i : a) {
		cin >> i;
	}
	vector<int> pref(n + 1);
	for(int i = 0; i < n; i++) {
		pref[i + 1] = (pref[i] + a[i]) % 7;
	}
	vector<int> lst(7, n);
	for(int i = n; i > 0; i--) {
		lst[pref[i]] = i;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(i > lst[pref[i]]) {
			ans = max(ans, i - lst[pref[i]]);
		}
	}
	cout << ans << nl;
}

signed main() {
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	while(tt--) solve();
}
