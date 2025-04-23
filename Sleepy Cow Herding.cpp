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
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	int n; cin >> n;
	
	vector<int> a(n);
	
	for(auto &i : a) cin >> i;
	
	sort(all(a));
	
	auto solve_min = [&]() -> int {
		if(a[n - 2] - a[0] == n - 2 && a[n - 1] - a[n - 2] > 2) return 2;
		if(a[n - 1] - a[1] == n - 2 && a[1] - a[0] > 2) return 2;
		int mx = 0;
		for(int i = 0, j = 0; i < n; i++) {
			while(j < n && a[j] - a[i] + 1 <= n) j++;
			mx = max(mx, j - i);
		}
		return n - mx;
	};
	
	cout << solve_min() << nl;
	
	cout << (a[n - 1] - a[0] + 1 - n) - min(a[n - 1] - a[n - 2] - 1, a[1] - a[0] - 1) << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
