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

int a[1005][1005];

void solve() {
	setIO("leftout");
	int n; cin >> n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			char c; cin >> c;
			a[i][j] = (c == 'R');
		}
	}
	
	auto transform = [&](int i1, int j1, int i2, int j2) {
		for(int i = i1; i <= i2; i++) {
			for(int j = j1; j <= j2; j++) {
				a[i][j] ^= 1;
			}
		}
	};
	
	auto get = [&](int i1, int j1, int i2, int j2, int b) {
		int cnt = 0;
		for(int i = i1; i <= i2; i++) {
			for(int j = j1; j <= j2; j++) {
				cnt += (a[i][j] == b);
			}
		}
		return cnt;
	};
	
	for(int j = 0; j < n; j++) {
		if(a[0][j]) transform(0, j, n - 1, j);
	}
	
	for(int i = 0; i < n; i++) {
		if(a[i][0]) transform(i, 0, i, n - 1);
	}
	
	if(get(1, 1, n - 1, n - 1, 0) == 0) {
		cout << "1 1" << nl;
		return;
	}
	
	if(get(1, 1, n - 1, n - 1, 1) == n - 1) {
		for(int j = 0; j < n; j++) {
			if(get(0, j, n - 1, j, 1) == n - 1) {
				cout << 1 << ' ' << j + 1 << nl;
				return;
			}
		}
		for(int i = 0; i < n; i++) {
			if(get(i, 0, i, n - 1, 1) == n - 1) {
				cout << i + 1 << ' ' << 1 << nl;
				return;
			}
		}
		cout << -1 << nl;
		return;
	}
	
	if(get(1, 1, n - 1, n - 1, 1) == 1) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(a[i][j]) {
					cout << i + 1 << ' ' << j + 1 << nl;
					return;
				}
			}
		}
	}
	
	cout << -1 << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
