#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

const int inf = 1e18;

void chmax(int &a, const int &b) {
	if(a < b) a = b;
}

void solve() {
	int k, m, n;
	
	cin >> k >> m >> n;
	
	vector<ar<int, 2>> g(k);
	
	for(auto &[p, t] : g) {
		cin >> p >> t;
	}
	
	vector<int> f(m);
	
	for(auto &x : f) cin >> x;
	
	sort(all(g));
	
	f.pb(-inf);
	f.pb(inf);
	
	sort(all(f));
	
	m = f.size();
	
	vector<vector<ar<int, 3>>> h(m);
	
	for(int i = 0; i < k; i++) {
		auto &[p, t] = g[i];
		
		int j = upper_bound(all(f), p) - f.begin();
		int mn = min(f[j] - p, p - f[j - 1]) - 1;
		h[j].pb({ p - mn, p + mn, t });
	}
	
	vector<int> one(m), two(m);
	
	for(int i = 0; i < m; i++) {
		vector<ar<int, 2>> ev;
		
		// cout << nl;
		
		// cout << i << ": " << nl;
		
		for(auto &[l, r, t] : h[i]) {
			ev.pb({l, t});
			ev.pb({r + 1, -t});
			two[i] += t;
			// cout << l << ' ' << r << ' ' << t << nl;
		}
		
		// cout << nl;
		
		sort(all(ev));
		
		int cur = 0, E = ev.size();
		
		for(int l = 0, r = 0; l < E; l = r) {
			while(r < E && ev[l][0] == ev[r][0]) {
				cur += ev[r][1];
				r++;
			}
			
			chmax(one[i], cur);
		}
	}
	
	// for(int i = 0; i < m; i++) {
		// cout << one[i] << ' ' << two[i] << nl;
	// }
	
	vector<int> vals;
	
	for(int i = 0; i < m; i++) {
		vals.pb(one[i]);
		vals.pb(two[i] - one[i]);
	}
	
	sort(all(vals), greater<>());
	
	vals.resize(n);
	
	// for(auto &x : vals) cout << x << ' ';
	// cout << nl;
	
	cout << accumulate(all(vals), 0ll) << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
