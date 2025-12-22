#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5;

void solve() {
	int T, C; cin >> T >> C;
	
	vector<int> t(2 * N);
	
	for(int i = 0; i < T; i++) {
		int x; cin >> x;
		t[x + N] = 1;
	}
	
	string s; cin >> s;
	
	vector<int> pos(C);
	
	int cur = 0;
	
	for(int i = 0; i < C; i++) {
		if(s[i] == 'L') cur--;
		else if(s[i] == 'R') cur++;
		pos[i] = cur;
	}
	
	array<vector<int>, 5> mp;
	
	array<int, 5> sz{};
	
	auto add = [&](int j, int x) {
		x += N;
		if(t[x]) {
			if(mp[j][x]++ == 0) sz[j]++;
		}
	};
	
	auto del = [&](int j, int x) {
		x += N;
		if(t[x]) {
			if(--mp[j][x] == 0) sz[j]--;
		}
	};
	
	for(int j = 0; j < 5; j++) {
		mp[j].resize(2 * N);
		for(int i = 0; i < C; i++) {
			if(s[i] == 'F') {
				add(j, pos[i] + (j - 2));
			}
		}
	}
	
	int ans = sz[2];
	
	for(int i = 0; i < C; i++) {
		if(s[i] == 'F') {
			for(int j = 0; j < 5; j++) {
				del(j, pos[i] + (j - 2));
				add(j, pos[i]);
			}
		}
		cur = (i ? pos[i - 1] : 0);
		// cout << i << ": ";
		for(auto j : {'F', 'L', 'R'}) {
			if(s[i] == j) continue;
			// cout << 
			if(j == 'F') {
				if(s[i] == 'L') { // shift by 1
					add(3, cur);
					ans = max(ans, sz[3]);
					// cout << sz[3] << ' ';
					del(3, cur);
				} else { // shift by -1
					add(1, cur);
					ans = max(ans, sz[1]);
					// cout << sz[1] << ' ';
					del(1, cur);
				}
			} else if(j == 'L') {
				if(s[i] == 'F') { // shift by -1
					del(1, cur);
					ans = max(ans, sz[1]);
					// cout << sz[1] << ' ';
					add(1, cur);
				} else { // shift by -2
					ans = max(ans, sz[0]);
					// cout << sz[0] << ' ';
				}
			} else {
				if(s[i] == 'F') { // shift by 1
					del(3, cur);
					ans = max(ans, sz[3]);
					// cout << sz[3] << ' ';
					add(3, cur);
				} else { // shift by 2
					ans = max(ans, sz[4]);
					// cout << sz[4] << ' ';
				}
			}
		}
		// cout << '\n';
	}
	
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
