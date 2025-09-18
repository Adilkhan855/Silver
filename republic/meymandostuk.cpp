#include <bits/stdc++.h>
using namespace std;

// #define int long long
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

const int inf = 1e9;

void solve() {
	int n, L; cin >> n >> L;
	
	vector<int> x(n), h(n);
	
	for(auto &x : x) cin >> x;
	for(auto &x : h) cin >> x;
	
	vector<int> lg(n + 1);
	
	for(int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
	
	vector<vector<int>> sp(21, vector<int>(n));
	
	auto sp2 = sp;
	
	for(int i = 0; i < n; i++) {
		sp[0][i] = h[i] + x[i];
		sp2[0][i] = h[i] - x[i];
	}
	
	for(int i = 0; i < 20; i++) {
		for(int j = 0; j + (1 << i) < n; j++) {
			sp[i + 1][j] = max(sp[i][j], sp[i][j + (1 << i)]);
			sp2[i + 1][j] = max(sp2[i][j], sp2[i][j + (1 << i)]);
		}
	}
	
	auto query1 = [&](int l, int r) {
		r++;
		int i = lg[r - l];
		return max(sp[i][l], sp[i][r - (1 << i)]);
	};
	
	auto query2 = [&](int l, int r) {
		r++;
		int i = lg[r - l];
		return max(sp2[i][l], sp2[i][r - (1 << i)]);
	};
	
	for(int i = 0, l = 0, r = 0; i < n; i++) {
		while(l < i && x[l] < x[i] - L / 2) l++;
		while(r < n && x[r] <= x[i] + L / 2) r++;
		int res = 0;
		if(l - 1 >= 0) chmax(res, h[i] - x[i] + L + query1(0, l - 1));
		if(l < i) chmax(res, h[i] + x[i] + query2(l, i - 1));
		if(r < n) chmax(res, h[i] + x[i] + L + query2(r, n - 1));
		if(i + 1 <= r - 1) chmax(res, h[i] - x[i] + query1(i + 1, r - 1));
		cout << res << ' ';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// int tt; cin >> tt;
	// while(tt--) solve();
	solve();
}
