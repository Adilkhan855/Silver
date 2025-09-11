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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
	setIO("teleport");
	
	int n; cin >> n;
	
	int cur_f = 0, sl_f = 0, cur_y = -2e9;
	
	map<int, int> slch;
	
	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		
		cur_f += abs(a - b);
		
		if(abs(a) > abs(a - b)) continue;
		slch[b] += 2;
		if( (a < b && a < 0) || (a >= b && a >= 0) ) { slch[0]--, slch[2 * b]--; }
		if( (a < b && a >= 0) || (a >= b && a < 0) ) { slch[2 * (b - a)]--, slch[2 * a]--; }
	}
	
	int min_f = cur_f;
	
	for(auto [key, val] : slch) {
		int new_y = key, delta_sl = val;
		cur_f += sl_f * (new_y - cur_y);
		cur_y = new_y;
		sl_f += delta_sl;
		chmin(min_f, cur_f);
	}
	
	cout << min_f << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
