/**
 *    author: a.k
 *    created: idk
**/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) x.begin(), x.end()
#define pb push_back
#define nl '\n'

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int nax = 2005;

int main() {
	setIO("gates");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	string s; cin >> s;
	
	vector fn(nax, vector(nax, false));
	int curx = 1002, cury = 1002;
	fn[curx][cury] = true;
	for(int i = 0; i < n; i++) {
		char dir = s[i];
		int dx = 0, dy = 0;
		if(dir == 'N') dy++;
		if(dir == 'S') dy--;
		if(dir == 'E') dx++;
		if(dir == 'W') dx--;
		for(int it = 0; it < 2; it++) {
			curx += dx;
			cury += dy;
			fn[curx][cury] = true;
		}
	}
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	int cnt = 0;
	for(int i = 0; i < nax; i++) {
		for(int j = 0; j < nax; j++) {
			if(fn[i][j]) continue;
			cnt++;
			queue<pair<int, int>> q;
			q.emplace(i, j);
			fn[i][j] = true;
			while(!q.empty()) {
				auto [x, y] = q.front();
				q.pop();
				for(int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if(nx >= 0 && nx < nax && ny >= 0 && ny < nax && !fn[nx][ny]) {
						fn[nx][ny] = true;
						q.emplace(nx, ny);
					}
				}
			}
		}
	}
	cout << cnt << nl;
}
