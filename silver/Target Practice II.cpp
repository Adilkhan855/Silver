#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
	int n, X1; cin >> n >> X1;
	
	vector<int> y1(n), y2(n), x2(n);
	
	vector<array<int, 2>> neg, pos;
	
	vector<int> ys;
	
	ys.reserve(2 * n);
	
	for(int i = 0; i < n; i++) {
		cin >> y1[i] >> y2[i] >> x2[i];
		neg.push_back({x2[i], y2[i]});
		pos.push_back({x2[i], y1[i]});
		ys.push_back(y1[i]);
		ys.push_back(y2[i]);
	}
	
	vector<ll> s(4 * n), sneg, spos;
	
	for(auto &x : s) {
		cin >> x;
		if(x < 0) sneg.push_back(-x);
		else spos.push_back(x);
	}
	
	if( (int)sneg.size() < n || (int)spos.size() < n ) {
		cout << -1 << '\n';
		return;
	}
	
	sort(ys.begin(), ys.end());
	sort(sneg.begin(), sneg.end());
	sort(spos.begin(), spos.end());
	
	int p = sneg.size() - n;
	
	for(int i = 0; i < p; i++) {
		neg.push_back({X1, ys[i]});
	}
	
	for(int i = p; i < 2 * n; i++) {
		pos.push_back({X1, ys[i]});
	}
	
	// for(auto &[x, y] : pos) {
		// cout << x << ' ' << y << '\n';
	// }
	
	// assert(neg.size() == sneg.size());
	// assert(pos.size() == spos.size());
	
	ll mn, mx;
	
	{ // pos
		auto check = [&](ll k) {
			vector<ll> t;
			
			for(auto &[x, y] : pos) {
				if(y - k < 0) return false;
				t.push_back((y - k) / x);
			}
			
			sort(t.begin(), t.end());
			
			// assert(t.size() == spos.size());
			
			for(int i = 0; i < (int)spos.size(); i++) {
				if(spos[i] > t[i]) return false;
			}
			
			return true;
		};
		
		// cout << '\n';
		
		// cout << "pos: " << '\n';
		
		// for(auto &[x, y] : pos) {
			// cout << x << ' ' << y << '\n';
		// }
		
		// cout << "spos: " << '\n';
		
		// for(auto &x : spos) cout << x << ' ';
		
		// cout << '\n';
		
		ll l = -1e18, r = 1e18;
		
		while(l < r) {
			ll mid = (l + r + 1) >> 1;
			
			if(check(mid)) l = mid;
			else r = mid - 1;
		}
		
		mn = l;
	}
	
	{ // neg
		auto check = [&](ll k) {
			vector<ll> t;
			
			for(auto &[x, y] : neg) {
				if(k - y < 0) return false;
				t.push_back((k - y) / x);
			}
			
			sort(t.begin(), t.end());
			
			// assert(t.size() == sneg.size());
			
			for(int i = 0; i < (int)sneg.size(); i++) {
				if(sneg[i] > t[i]) return false;
			}
			
			return true;
		};
		
		ll l = -1e18, r = 1e18;
		
		while(l < r) {
			ll mid = (l + r) >> 1;
			
			if(check(mid)) r = mid;
			else l = mid + 1;
		}
		
		mx = l;
	}
	
	// cout << mn << ' ' << mx << '\n';
	cout << mx - mn << '\n';
}

/**

**/

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while(tt--) solve();
}
