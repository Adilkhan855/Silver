#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'
 
template <typename A, typename B>
bool chmin(A &a, const B &b) {
	if( a > b ) {
		return a = b, true;
	}
	return false;
}
 
template <typename A, typename B>
bool chmax(A &a, const B &b) {
	if( a < b ) {
		return a = b, true;
	}
	return false;
}

void solve() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	
	int n; cin >> n;
	
	vector<int> a(n);
	
	for(auto &x : a) cin >> x;
	
	auto b = a;
	
	sort(all(b));
	
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		int j = upper_bound(all(b), a[i]) - b.begin();
		chmax(ans, i - j + 1);
	}
	
	cout << ans + 1 << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
