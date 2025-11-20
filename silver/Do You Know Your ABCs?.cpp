#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

void solve() {
	int n; cin >> n;
	
	vector<int> x(n);
	
	for(auto &u : x) cin >> u;
	
	x.pb(0);
	
	sort(all(x));
	
	n = x.size();
	
	vector<int> ele;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			ele.pb(x[i] - x[j]);
		}
	}
	
	sort(all(ele));
	ele.erase(unique(all(ele)), ele.end());
	
	// for(auto &u : ele) cout << u << ' ';
	// cout << nl;
	
	// cout << nl;
	
	int ans = 0;
	
	for(auto A : ele) {
		for(auto B : ele) {
			if(A > B) continue;
			for(auto C : ele) {
				if(B > C) continue;
				// assert(A <= B && B <= C);
				vector<int> y{A, B, C, A + B, A + C, B + C, A + B + C};
				// assert(is_sorted(all(y)));
				// if(!is_sorted(all(y))) {
					// cout << "Found!" << nl;
					// cout << A << ' ' << B << ' ' << C << nl;
					// for(auto &u : y) cout << u << ' ';
					// cout << nl;
					// return;
				// }
				// cout << "here: " << A << ' ' << B << ' ' << C << nl;
				sort(all(y));
				bool flag = true;
				for(auto &u : x) {
					if(!u) continue;
					if(!binary_search(all(y), u)) {
						flag = false;
						break;
					}
				}
				if(flag) {
					ans++;
					// cout << A << ' ' << B << ' ' << C << nl;
				}
			}
		}
	}
	
	// cout << nl;
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while(tt--) solve();
}
