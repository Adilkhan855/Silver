#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n; cin >> n;
	
	vector s(n, vector(n, ' '));
	vector c(n + 1, vector(n + 1, 0));
	
	for(int i = 0; i < n + 1; i++) {
		if(i < n) {
			for(int j = 0; j < n; j++) {
				cin >> s[i][j];
			}
			cin >> c[i][n];
		} else {
			for(int j = 0; j < n; j++) {
				cin >> c[n][j];
			}
		}
	}
	
	vector cnt(n + 1, vector(n + 1, 0));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cnt[i][j]++;
			if(s[i][j] == 'R') cnt[i][j + 1] += cnt[i][j];
			else cnt[i + 1][j] += cnt[i][j];
		}
	}
	
	int tot = 0;
	
	for(int i = 0; i < n; i++) {
		tot += cnt[i][n] * c[i][n];
		tot += cnt[n][i] * c[n][i];
	}
	
	cout << tot << '\n';
	
	int q; cin >> q;
	
	while(q--) {
		int x, y; cin >> x >> y;
		x--, y--;
		
		int i, j;
		
		for(i = x, j = y; i < n && j < n;) {
			if(s[i][j] == 'R') j++;
			else i++;
			cnt[i][j] -= cnt[x][y];
		}
		
		tot -= (cnt[i][j] + cnt[x][y]) * c[i][j];
		tot += cnt[i][j] * c[i][j];
		
		s[x][y] = (s[x][y] == 'R' ? 'D' : 'R');
		
		for(i = x, j = y; i < n && j < n;) {
			if(s[i][j] == 'R') j++;
			else i++;
			cnt[i][j] += cnt[x][y];
		}
		
		tot -= (cnt[i][j] - cnt[x][y]) * c[i][j];
		tot += cnt[i][j] * c[i][j];
		
		cout << tot << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
