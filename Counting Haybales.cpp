/**
 *    author: a.k
 *    created: idk
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb emplace_back
#define nl '\n'

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
	setIO("haybales");
	
	int n, q; cin >> n >> q;
	
	vector<int> a(n);
	for(auto &u : a) cin >> u;
	
	sort(all(a));
	
	while(q--) {
		int A, B; cin >> A >> B;
		cout << upper_bound(all(a), B) - lower_bound(all(a), A) << nl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}
