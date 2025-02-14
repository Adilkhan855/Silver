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
	freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k, r; cin >> n >> k >> r;
	
	map<array<int, 4>, bool> road;
	
	for(int i = 0; i < r; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		x1--, y1--, x2--, y2--;
		road[{x1, y1, x2, y2}] = road[{x2, y2, x1, y1}] = 1;
	}
	
	vector<array<int, 2>> cow(k);
	
	for(auto &[x, y] : cow) {
		cin >> x >> y;
		x--, y--;
	}
	
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	
	vector<vector<int>> used(n, vector<int>(n));
	
	auto dfs = [&](auto &&self, int x, int y) -> void {
		used[x][y] = true;
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= n || ny >= n || used[nx][ny]) continue;
			
			if(!road[{x, y, nx, ny}]) self(self, nx, ny);
		}
	};
	
	int cnt = 0;
	
	for(int i = 0; i < k; i++) {
		for(int x = 0; x < n; x++) {
			for(int y = 0; y < n; y++) {
				used[x][y] = false;
			}
		}
		
		dfs(dfs, cow[i][0], cow[i][1]);
		
		for(int j = 0; j < i; j++) {
			if(!used[cow[j][0]][cow[j][1]]) cnt++;
		}
	}
	
	cout << cnt << nl;
}
