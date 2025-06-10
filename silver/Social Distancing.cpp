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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
	setIO("socdist");
	int n, m; cin >> n >> m;
	
	vector<ar<int, 2>> rng(m);
	
	for(auto &[l, r] : rng) {
		cin >> l >> r;
	}
	
	sort(all(rng));
	
	auto check = [&](int d) {
		int last = rng[0][0], cnt = 0;
		// cout << d << ": ";
		for(auto [l, r] : rng) {
			if(last > r) continue;
			if(last < l) last = l;
			int y = (r - last) / d;
			cnt += y + 1;
			// cout << last << ' ';
			last += (y + 1) * d;
		}
		// cout << nl;
		return cnt >= n;
	};
	
	int l = 1, r = 1e18;
	
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	
	cout << l << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
