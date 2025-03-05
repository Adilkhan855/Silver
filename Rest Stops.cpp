#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

signed main() {
	setIO("reststops");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int L, n, rf, rb;
	cin >> L >> n >> rf >> rb;
	
	vector<int> x(n), c(n);
	
	map<int, int> mp;
	
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> c[i];
		mp[c[i]]++;
	}
	
	int ans = 0, tf = 0, tb = 0;
	
	for(int i = 0; i < n; i++) {
		auto it = mp.upper_bound(c[i]);
		
		if(it == mp.end()) {
			int cur = (x[i] * rf + tf) - (x[i] * rb + tb);
			ans += cur * c[i];
			tb += cur;
		}
		
		if(--mp[c[i]] == 0) mp.erase(c[i]);
	}
	
	cout << ans << nl;
}
