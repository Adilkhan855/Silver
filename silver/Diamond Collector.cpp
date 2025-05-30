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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
	setIO("diamond");
	
	int n, k; cin >> n >> k;
	vector<int> a(n);
	
	for(auto &u : a) cin >> u;
	
	sort(all(a));
	
	queue<pair<int, int>> q;
	int ans = 0, mx = 0;
	
	for(int l = 0; l < n; l++) {
		int r = upper_bound(all(a), a[l] + k) - a.begin();
		while(!q.empty() && q.front().first <= l) {
			mx = max(mx, q.front().second);
			q.pop();
		}
		q.emplace(r, r - l);
		ans = max(ans, (r - l) + mx);
	}
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}
