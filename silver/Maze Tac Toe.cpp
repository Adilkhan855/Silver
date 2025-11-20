#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};

int st[25][25][20000];	

void solve() {
	int n; cin >> n;
	
	vector<string> s(n);
	
	for(auto &row : s) cin >> row;
	
	vector<vector<ar<char, 3>>> a(n, vector<ar<char, 3>>(n));
	
	int bx = -1, by = -1;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < (int)s[i].size(); j += 3) {
			a[i][j / 3][0] = s[i][j];
			a[i][j / 3][1] = s[i][j + 1];
			a[i][j / 3][2] = s[i][j + 2];
			if(s[i][j] == 'B') {
				bx = i, by = j / 3;
			}
		}
	}
	
	vector< ar< ar<int, 2>, 3> > to_check;
	
	// ar< ar<int, 2>, 3> b{ {0, 0}, {0, 0}, {0, 0} };
	
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 8; k++) {
				int ni = i + dx[k], nj = j + dy[k];
				int ni2 = ni + dx[k], nj2 = nj + dy[k];
				if(ni < 0 || nj < 0 || ni2 < 0 || nj2 < 0) continue;
				if(ni > 2 || nj > 2 || ni2 > 2 || nj2 > 2) continue;
				to_check.pb({ { {i, j}, {ni, nj}, {ni2, nj2} } });
			}
		}
	}
	
	vector<int> pw(30, 1);
	
	for(int i = 1; i < 30; i++) pw[i] = pw[i - 1] * 3;
	
	auto idx = [&](int i, int j) {
		return i * 3 + j;
	};
	
	auto get = [&](int state, const ar<int, 2> &p) {
		return state / pw[idx(p[0], p[1])] % 3;
	};
	
	auto check = [&](int state) {
		for(auto ps : to_check) {
			if( get(state, ps[0]) == 1 && get(state, ps[1]) == 2 && get(state, ps[2]) == 2 ) return true;
		}
		return false;
	};
	
	set<int> ans;
	
	auto dfs = [&](auto &&self, int x, int y, int state) -> void {
		if(st[x][y][state]) return;
		// cout << x << ' ' << y << ' ' << state << ' ' << a[x][y][0] << endl;
		
		st[x][y][state] = 1;
		
		if(check(state)) {
			// cout << nl;
			// for(int i = 0; i < 3; i++) {
				// for(int j = 0; j < 3; j++) {
					// int g = get(state, {i, j});
					// if(g == 0) cout << '.';
					// if(g == 1) cout << 'M';
					// if(g == 2) cout << 'O';
				// }
				// cout << nl;
			// }
			// cout << nl;
			ans.emplace(state);
			return;
		}
		
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= n || ny >= n || a[nx][ny][0] == '#') continue;
			
			auto [val, ix, iy] = a[nx][ny];
			
			ix = ix - '0' - 1;
			iy = iy - '0' - 1;
			
			int nstate = state;
			
			if((val == 'M' || val == 'O') && get(nstate, {ix, iy}) == 0) {
				if(val == 'M') {
					nstate += 1 * pw[idx(ix, iy)];
				}
				if(val == 'O') {
					nstate += 2 * pw[idx(ix, iy)];
				}
			}
			
			self(self, nx, ny, nstate);
		}
	};
	
	dfs(dfs, bx, by, 0);
	
	cout << ans.size() << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
