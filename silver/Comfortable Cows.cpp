#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve() {
	int n; cin >> n;
	
	set<ar<int, 2>> ad, all;
	
	stack<ar<int, 2>> res;
	
	auto check = [&](int x, int y) {
		if(!all.count({x, y})) return;
		int one_x = -1, one_y = -1, cnt = 0;
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(all.count({nx, ny})) cnt++;
			else one_x = nx, one_y = ny;
		}
		
		if(cnt == 3) res.push({one_x, one_y});
	};
	
	auto check_adj = [&](int x, int y) {
		check(x, y);
		for(int i = 0; i < 4; i++) {
			check(x + dx[i], y + dy[i]);
		}
	};
	
	for(int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		
		ad.erase({x, y});
		all.insert({x, y});
		
		check_adj(x, y);
		
		while(!res.empty()) {
			auto [ax, ay] = res.top();
			res.pop();
			
			ad.insert({ax, ay});
			all.insert({ax, ay});
			
			check_adj(ax, ay);
		}
		
		cout << ad.size() << nl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
