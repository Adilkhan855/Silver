#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int inf = 1e9 + 5;

void solve() {
	int n; cin >> n;
	
	vector<vector<int>> r(n, vector<int>(n));
	
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			cin >> r[i][j];
		}
	}
	
	vector<int> ans(n + 1);
	
	for(int i = n - 1; i >= 0; i--) {
		auto check = [&]() {
			int mn = inf, mx = -inf;
			for(int j = i; j < n; j++) {
				mn = min(mn, ans[j]);
				mx = max(mx, ans[j]);
				if(mx - mn != r[i][j]) return false;
			}
			return true;
		};
		
		ans[i] = ans[i + 1] + r[i][i + 1];
		
		if(!check()) {
			ans[i] = ans[i + 1] - r[i][i + 1];
		}
	}
	
	for(int i = 0; i < n; i++) {
		if(i) cout << ' ';
		cout << ans[i];
	}
	
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
