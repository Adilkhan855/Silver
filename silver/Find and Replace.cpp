#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	string s, t; cin >> s >> t;
	
	int n = s.size();
	
	vector a(52, vector(52, false));
	
	vector b(52, 0);
	
	for(int i = 0; i < n; i++) {
		int si = s[i], ti = t[i];
		
		if(islower(s[i])) si -= 'a';
		else si = (si - 'A') + 26;
		
		if(islower(t[i])) ti -= 'a';
		else ti = (ti - 'A') + 26;
		
		a[si][ti] = true;
		b[ti] = true;
	}
	
	if(accumulate(b.begin(), b.end(), 0) == 52) {
		cout << (s != t ? -1 : 0) << '\n';
		return;
	}
	
	vector<int> r(52, -1);
	
	vector<vector<int>> radj(52);
	
	for(int i = 0; i < 52; i++) {
		for(int j = 0; j < 52; j++) {
			if(a[i][j]) {
				if(r[i] == -1) {
					r[i] = j;
				} else {
					cout << -1 << '\n';
					return;
				}
			}
		}
		if(r[i] == -1) r[i] = i;
		radj[r[i]].push_back(i);
	}
	
	vector<int> used(52);
	
	int tot = 0;
	
	auto dfs = [&](auto &&self, int v) -> void {
		used[v] = true;
		tot++;
		for(auto to : radj[v]) {
			if(!used[to]) self(self, to);
		}
	};
	
	int ans = 0;
	
	for(int i = 0; i < 52; i++) {
		ans += (r[i] != i);
		if(!used[i]) {
			int a = r[i], b = r[r[i]];
			
			while(a != b) {
				a = r[a];
				b = r[r[b]];
			}
			
			int sz = 0;
			
			do {
				used[a] = true;
				sz++;
				a = r[a];
			} while(a != b);
			
			tot = 0;
			
			do {
				dfs(dfs, a);
				a = r[a];
			} while(a != b);
			
			if(sz == tot && sz > 1) {
				ans++;
			}
		}
	}
	
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while(tt--) solve();
}
