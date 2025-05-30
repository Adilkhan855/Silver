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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve() {
	setIO("mooyomooyo");
	int n, k; cin >> n >> k;
	
	vector<string> s(n);
	
	for(auto &str : s) cin >> str;
	
	int nw = 0;
	
	vector<vector<int>> used(n, vector<int>(10));
	vector<int> cnt(10 * n);
	
	auto dfs = [&](auto &&self, int x, int y) -> void {
		used[x][y] = nw;
		cnt[nw]++;
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && ny >= 0 && nx < n && ny < 10 && !used[nx][ny] && s[nx][ny] == s[x][y]) {
				self(self, nx, ny);
			}
		}
	};
	
	while(true) {
		for(int i = 0; i < n; i++) fill(all(used[i]), false);
		fill(all(cnt), 0);
		
		nw = 0;
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < 10; j++) {
				if(s[i][j] != '0' && !used[i][j]) {
					nw++;
					dfs(dfs, i, j);
				}
			}
		}
		
		bool flag = false;
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < 10; j++) {
				if(cnt[used[i][j]] >= k) {
					s[i][j] = '0';
					flag = true;
				}
			}
		}
		
		if(!flag) break;
		
		for(int j = 0; j < 10; j++) {
			string tmp;
			for(int i = n - 1; i >= 0; i--) {
				if(s[i][j] != '0') tmp += s[i][j];
			}
			while((int)tmp.size() < n) tmp += '0';
			reverse(all(tmp));
			for(int i = 0; i < n; i++) {
				s[i][j] = tmp[i];
			}
		}
	}
	
	for(auto str : s) cout << str << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
