#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n; cin >> n;
	
	vector<ll> a(n);
	
	for(auto &x : a) cin >> x;
	
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	
	n = a.size();
	
	if(n <= 3) {
		ll mn = a[0] / 4;
		cout << mn * (mn + 1) / 2 << '\n';
		return;
	}
	
	set<ll> st;
	
	for(int i = 0; i < 4; i++) {
		for(int j = i + 1; j < 4; j++) {
			int y = a[j] - a[i];
			for(int x = 1; x * x <= y; x++) {
				if(y % x == 0) {
					st.emplace(x);
					st.emplace(y / x);
				}
			}
		}
	}
	
	auto check = [&](ll u) {
		if(u * 4 > a[0]) return false;
		
		set<ll> ya;
		
		for(int i = 0; i < n; i++) {
			ya.emplace(a[i] % u);
			if(ya.size() > 3) return false;
		}
		
		return true;
	};
	
	ll ans = 0;
	
	for(auto &u : st) {
		if(check(u)) ans += u;	
	}
	
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
