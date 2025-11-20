#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

void solve() {
	int n, k; cin >> n >> k;
	
	vector<int> a(k), b(k);
	
	vector<int> from(n);
	
	iota(all(from), 0);
	
	vector<vector<int>> st(n);
	
	for(int i = 0; i < n; i++) st[i].pb(i);
	
	for(int i = 0; i < k; i++) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
		
		st[from[a[i]]].pb(b[i]);
		st[from[b[i]]].pb(a[i]);
		
		swap(from[a[i]], from[b[i]]);
	}
	
	vector<int> used(n), cnt(n);
	
	int uni = 0;
	
	auto add = [&](int v) {
		for(auto u : st[v]) {
			if(cnt[u]++ == 0) uni++;
		}
	};
	
	auto rem = [&](int v) {
		for(auto u : st[v]) {
			if(--cnt[u] == 0) uni--;
		}
	};
	
	vector<int> ans(n);
	
	for(int i = 0; i < n; i++) {
		if(!used[i]) {
			int j = i;
			
			do {
				add(j);
				j = from[j];
			} while(j != i);
			
			j = i;
			
			int cur = uni;
			
			do {
				rem(j);
				used[j] = true;
				ans[j] = cur;
				j = from[j];
			} while(j != i);
		}
	}
	
	for(auto &x : ans) cout << x << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
