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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve() {
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
	int n; cin >> n;
	
	vector<string> s(n);
	
	for(auto &row : s) cin >> row;
	
	vector<vector<int>> used(n, vector<int>(n));
	
	int nw = 0;
	
	auto dfs = [&](auto &&self, int x, int y) -> void {
		used[x][y] = nw;
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= n || used[nx][ny] || s[nx][ny] == '.') continue;
			self(self, nx, ny);
		}
	};
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(!used[i][j] && s[i][j] == '#') {
				nw++;
				dfs(dfs, i, j);
			}
		}
	}
	
	auto count = [&](int x, int y) {
		int cnt = 0;
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= n || s[nx][ny] == '.') cnt++;
		}
		return cnt;
	};
	
	vector<int> per(nw + 1), area(nw + 1);
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(s[i][j] == '#') {
				area[used[i][j]]++;
				per[used[i][j]] += count(i, j);
			}
		}
	}
	
	int mxar = 0, mnper = 1e9;
	
	for(int i = 1; i <= nw; i++) {
		if(mxar == area[i]) chmin(mnper, per[i]);
		if(chmax(mxar, area[i])) mnper = per[i];
	}
	
	cout << mxar << ' ' << mnper << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
