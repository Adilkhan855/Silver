#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

void solve() {
	int n; cin >> n;
	
	vector<ar<int, 2>> p(n);
	
	for(auto &[x, y] : p) {
		cin >> x >> y;
	}
	
	sort(all(p));
	
	for(int i = 0; i < n; i++) {
		p[i][0] = i + 1;
	}
	
	sort(all(p), [](const ar<int, 2> &p1, const ar<int, 2> &p2) {
		return p1[1] < p2[1];
	});
	
	for(int i = 0; i < n; i++) {
		p[i][1] = i + 1;
	}
	
	vector<vector<int>> pref(n + 1, vector<int>(n + 1));
	
	for(int i = 0; i < n; i++) {
		pref[p[i][0]][p[i][1]] = 1;
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			pref[i][j] = pref[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}
	
	auto sum = [&](int x1, int x2, int y1, int y2) {
		x1--, y1--;
		return pref[x2][y2] - pref[x1][y2] - pref[x2][y1] + pref[x1][y1];
	};
	
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			int x1 = p[i][0], x2 = p[j][0];
			if(x1 > x2) swap(x1, x2);
			ans += sum(1, x1, p[i][1], p[j][1]) * sum(x2, n, p[i][1], p[j][1]);
		}
	}
	
	cout << ans + 1 << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
