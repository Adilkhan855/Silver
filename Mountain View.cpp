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

void solve() {
	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);
	int n; cin >> n;
	
	vector<ar<int, 2>> rng;
	
	for(int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		rng.pb({x - y, -(x + y)});
	}
	
	sort(all(rng));
	
	int mx = -(1e9 + 5), ans = n;
	
	for(auto &[l, r] : rng) {
		r = -r;
		if(r <= mx) ans--;
		mx = max(mx, r);
	}
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
