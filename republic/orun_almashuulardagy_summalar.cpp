#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

template <typename A, typename B>
bool chmin(A &a, const B &b) {
	if(a > b) {
		return a = b, true;
	}
	return false;
}

template <typename A, typename B>
bool chmax(A &a, const B &b) {
	if(a < b) {
		return a = b, true;
	}
	return false;
}

void solve() {
	int n, q; cin >> n >> q;
	
	vector <int> fact(15 + 1);
	
	fact[0] = 1;
	
	for (int i = 1; i <= 15; i++) fact[i] = fact[i - 1] * i;
	
	auto get = [&](int i) {
		if(i == 0) return 0ll;
		
		int idx = (i - 1) / n, rem = i % n, res = n * (n + 1) / 2 * (i / n);
		
		// cout << "idx: " << idx << ' ' << res << nl;
		
		int tmp = max ( 0ll , n - 15 ) ;
		
		if (rem <= tmp) return res + rem * (rem + 1) / 2;
		
		rem -= tmp;
		
		res += tmp * (tmp + 1) / 2;
		
		vector<int> c(15);
		
		// cout << nl << "array of size: " << rem << nl;
		
		for (int i = 0; i < rem; i++) {
			
			// cout << "here: " << idx << ' ';
			
			for (int j = 1; j <= min(n, 15ll); j++) {
				if (j * fact[min(n, 15ll) - i - 1] > idx) {
					idx -= (j - 1) * fact[min(n, 15ll) - i - 1];
					int cnt = 0;
					for(int k = 0; k < 15; k++) {
						if(!c[k]) cnt++;
						if(cnt == j) {
							res += k + 1 + tmp;
							c[k] = true;
							break;
						}
					}
					break;
				}
			}
			
		}
		
		// cout << nl;
		
		return res;
	};
	
	while (q--) {
		int l, r; cin >> l >> r;
		
		// get(r);
		
		cout << get(r) - get(l - 1) << ' ';
	}
	
	cout << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
