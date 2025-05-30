/*
 *    author: a.k
 *    created: idk
*/
#include <bits/stdc++.h> 
using namespace std;

using i64 = long long;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int INF = 1e9 + 5	;
void solve() {
	setIO("trapped");
	int n, B; cin >> n >> B;
	
	vector<pair<int, int>> a(n);
	for(auto &[P, S] : a) cin >> S >> P;
	sort(a.begin(), a.end());
	
	int ans = INF;
	int sp = lower_bound(a.begin(), a.end(), pair{B, 0}) - a.begin();
	int j = sp;
	for(int i = sp - 1; i >= 0; i--) {
		while(j < n && a[j].first - a[i].first <= a[i].second) {
			ans = min(ans, a[j].first - a[i].first - a[j].second);
			j++;
		}
	}
	j = sp - 1;
	for(int i = sp; i < n; i++) {
		while(j >= 0 && a[i].first - a[j].first <= a[i].second) {
			ans = min(ans, a[i].first - a[j].first - a[j].second);
			j--;
		}
	}
	if(ans == INF) {
		cout << -1 << '\n';
	} else {
		cout << max(ans, 0) << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	while(tt--) solve();
}
