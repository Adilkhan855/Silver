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

using vi = vector<int>;

void apply(vi &a, vi p) {
	int n = a.size();
	vector<int> tmp(n);
	for(int i = 0; i < n; i++) {
		tmp[i] = a[p[i]];
	}
	swap(a, tmp);
}

void binpow(vi &a, vi p, int k) {
	while(k) {
		if(k & 1) apply(a, p);
		apply(p, p);
		k >>= 1;
	}
}

void solve() {
	setIO("swap");
	int n, m, k; cin >> n >> m >> k;

	vector<int> p(n), l(m), r(m);
	
	iota(all(p), 0);
	
	for(int i = 0; i < m; i++) {
		int l, r; cin >> l >> r;
		l--;
		reverse(p.begin() + l, p.begin() + r);
	}
	
	vector<int> ans(n);
	
	iota(all(ans), 0);
	
	binpow(ans, p, k);
	
	for(auto x : ans) cout << x + 1 << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
