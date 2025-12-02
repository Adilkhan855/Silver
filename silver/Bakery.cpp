#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using i128 = __int128;

struct F {
	i64 p;
	int q;
	
	F(i64 p = 0, int q = 1) : p(p), q(q) {}
	
	bool operator<(const F &other) {
		return (i128)p * other.q < (i128)q * other.p;
	};
	
	bool operator>(const F &other) {
		return (i128)p * other.q > (i128)q * other.p;
	}
};

template<typename A, typename B>
inline void chmin(A &a, const B &b) {
	if(a > b) a = b;
}

template<typename A, typename B>
inline void chmax(A &a, const B &b) {
	if(a < b) a = b;
}

void solve() {
	int n; cin >> n;
	
	int tc, tm; cin >> tc >> tm;
	
	vector<int> a(n), b(n);
	vector<i64> e(n), c(n);
	
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
		e[i] = c[i] - (a[i] * 1ll * tc + b[i] * 1ll * tm);
	}
	
	auto check = [&](int d) {
		// F flx( max(0, d + 1 - tm), 1 );
		// F frx( min(d, tc - 1), 1 );
		
		i64 lx = max(0, d + 1 - tm), rx = min(d, tc - 1);
		
		for(int i = 0; i < n; i++) {
			i64 p = e[i] + b[i] * 1ll * d;
			i64 q = b[i] - a[i];
			// /**
			if(q < 0) {
				p = -p, q = -q;
				if(p > 0) {
					// chmax(flx, F(p, q));
					chmax(lx, (p + q - 1) / q);
				}
			} else if(q > 0) {
				if(p < 0) return false;
				// chmin(frx, F(p, q));
				chmin(rx, p / q);
			} else {
				if(p < 0) return false;
			}
			// **/
		}
		
		// cout << lx << ' ' << rx << '\n';
		
		// i64 lx = (flx.p + flx.q - 1) / flx.q;
		// i64 rx = frx.p / frx.q;
		
		return lx <= rx;
		
		// return true;
	};
	
	i64 l = 0, r = tc + tm - 2;
	
	while(l < r) {
		int mid = (l + r) >> 1;
		// cout << "cur mid: " << mid << endl;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	
	cout << l << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	// auto z = clock();
	while(tt--) solve();
	// cout << fixed << setprecision(10) << "Time: " << (double)(clock() - z) / CLOCKS_PER_SEC << '\n';
	// cout << "11\n6\n";
}
