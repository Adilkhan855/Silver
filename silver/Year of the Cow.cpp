#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

void solve() {
	int n, k; cin >> n >> k;
	
	vector<int> a(n + 1);
	
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(all(a), greater<>());
	
	vector<int> val;
	
	int prev = (a[0] + 12 - 1) / 12 * 12, ans = prev;
	
	for(int i = 0; i <= n; i++) {
		while(i <= n && a[i] > prev) i++;
		int cur = (a[i] + 12 - 1) / 12 * 12;
		val.pb(prev - cur);
		prev = cur - 12;
		// cout << "a[i]: " << a[i] << nl;
	}
	
	k--;
	
	sort(all(val), greater<>());
	
	for(int i = 0; i < min( (int)val.size(), k ); i++) ans -= val[i];
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
