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
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	
	vector<int> p(n);
	
	for(auto &x : p) {
		cin >> x;
		x--;
	}
	
	vector<int> ans(n);
	
	bool in_cycle = false;
	
	auto dfs = [&](auto &&self, int v) {
		if(ans[v]) {
			if(ans[v] == 1) {
				ans[v] = 2;
				in_cycle = true;
			}
			return;
		}
		
		ans[v] = 1;
		
		self(self, p[v]);
		
		if(ans[v] != 1) {
			in_cycle = false;
		} else {
			ans[v] = in_cycle ? 2 : 3;
		}
		
	};

	for(int i = 0; i < n; i++) {
		if(!ans[i]) dfs(dfs, i);
	}
	
	cout << count(all(ans), 2) << nl;
}
