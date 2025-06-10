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

const int inf = 1 << 30 | 1;

void solve() {
	setIO("cereal");
	int n, m; cin >> n >> m;
	vector<int> f(n), s(n);
	for(int i = 0; i < n; i++) {
		cin >> f[i] >> s[i];
		f[i]--, s[i]--;
	}
	
	vector<int> ans(n), occ(m, inf);
	
	int cur = 0;
	
	auto dfs = [&](auto &&self, int v, int pos, int new_val) -> void {
		if(occ[pos] == inf) cur++;
		occ[pos] = new_val;
		if(v & 1) return;
		int i = v >> 1;
		v |= 1;
		if(v < occ[s[i]]) {
			self(self, occ[s[i]], s[i], v);
		}
	};
	
	for(int i = n - 1; i >= 0; i--) {		
		dfs(dfs, occ[f[i]], f[i], i << 1);
		// for(int j = 0; j < m; j++) {
			// cout << j + 1 << " - ";
			// if(occ[j] == inf) cout << '?';
			// else cout << (occ[j] & 1 ? 'b' : 'a') << occ[j] / 2 + 1;
			// cout << nl;
		// }
		ans[i] = cur;
	}
	
	for(auto x : ans) cout << x << nl;
}

/**
4 5
5 3
4 3
5 3
3 2


**/

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
