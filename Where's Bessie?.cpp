/**
 *    author: a.k
 *    created: idk
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define nl '\n'

signed main() {
	freopen("where.in", "r", stdin);
	freopen("where.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	
	vector<string> s(n);
	
	for(auto &row : s) cin >> row;
	
	vector<array<int, 4>> P;
	
	vector<vector<int>> used(n, vector<int>(n));
	
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	
	auto dfs = [&](auto &&self, int x, int y, int i1, int j1, int i2, int j2) -> void {
		used[x][y] = true;
		
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			
			if(nx < i1 || ny < j1 || nx > i2 || ny > j2 || used[nx][ny]) continue;
			
			if(s[nx][ny] == s[x][y]) {
				self(self, nx, ny, i1, j1, i2, j2);
			}
		}
	};
	
	auto check = [&](int i1, int j1, int i2, int j2) {
		
		for(int i = i1; i <= i2; i++) {
			for(int j = j1; j <= j2; j++) {
				used[i][j] = false;
			}
		}
		
		vector<int> c(26);
		
		int cnt = 0;
		
		for(int i = i1; i <= i2; i++) {
			for(int j = j1; j <= j2; j++) {
				if(!used[i][j]) {
					int cur = s[i][j] - 'A';
					if(c[cur]++ == 0) cnt++;
					dfs(dfs, i, j, i1, j1, i2, j2);
				}
			}
		}
		
		if(cnt != 2) return false;
		
		bool f1 = false, f2 = false;
		
		for(int i = 0; i < 26; i++) {
			if(c[i] == 1) f1 = true;
			if(c[i] > 1) f2 = true;
		}
		
		return f1 && f2;
	};
	
	for(int i1 = 0; i1 < n; i1++) {
		for(int j1 = 0; j1 < n; j1++) {
			for(int i2 = i1; i2 < n; i2++) {
				for(int j2 = j1; j2 < n; j2++) {
					if(check(i1, j1, i2, j2)) {
						P.pb({i1, j1, i2, j2});
					}
				}
			}
		}
	}
	
	auto contains = [&](int i1, int i2) {
		return P[i1][0] >= P[i2][0] && P[i1][2] <= P[i2][2] && P[i1][1] >= P[i2][1] && P[i1][3] <= P[i2][3];
	};
	
	auto is = [&](int i) {
		for(int j = 0; j < (int)P.size(); j++) {
			if(i != j && contains(i, j)) return false;
		}
		return true;
	};
	
	int cnt = 0;
	
	for(int i = 0; i < (int)P.size(); i++) {
		cnt += is(i);
	}
	
	cout << cnt << nl;
}
