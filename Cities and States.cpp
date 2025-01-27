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
	setIO("citystate");
	
	int n; cin >> n;
	
	map<pair<string, string>, int> x;
	
	int ans = 0;
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		string t; cin >> t;
		string C = s.substr(0, 2);
		if(C == t) continue;
		ans += x[{t, C}];
		x[{C, t}]++;
	}
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}
