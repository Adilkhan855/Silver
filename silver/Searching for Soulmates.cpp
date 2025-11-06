#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

bool chmin(int &a, const int &b) {
	if(a > b) {
		return a = b, true;
	}
	return false;
}

const int L = 60;

void solve() {
	int a, b; cin >> a >> b;
	
	// cout << nl;
	// cout << bitset<L>(a) << nl;
	// cout << bitset<L>(b) << nl;
	// cout << nl;
	
	int ans = 4 * L;
	
	int s1 = a, s1_cnt = 0;
	
	for(int D = 0; D <= 2 * L; D++) {
		int s2_cnt = 0;
		
		for(int M = 0; M <= 2 * L; M++) {
			int num = 0;
			
			for(int i = M; i <= L; i++) {
				if(b >> i & 1) {
					num |= (1ll << (i - M));
				}
			}
			
			if(s1 <= num) {
				if(chmin(ans, s1_cnt + s2_cnt + (num - s1))) {
					// cout << nl;
					// cout << D << ' ' << (num - s1) << ' ' << M << ' ' << s1_cnt + s2_cnt + (num - s1) << nl;
					// cout << s1_cnt << ' ' << s2_cnt << ' ' << s1 << ' ' << num << nl;
					// cout << nl;
				}
			}
			
			if(b >> M & 1) {
				s2_cnt++;
			}
			
			s2_cnt++;
		}
		
		if(s1 & 1) {
			s1++;
			s1_cnt++;
		}
		
		s1 >>= 1;
		s1_cnt++;
	}
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while(tt--) solve();
}
