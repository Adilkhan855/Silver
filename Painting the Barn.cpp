/**
 *    author: a.k
 *    created: idk
**/
#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define int long long
#define nl '\n'

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 1005;

signed main() {
	setIO("paintbarn");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k; cin >> n >> k;
	
	vector pref(mxN, vector(mxN, 0ll));
	
	for(int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		x1++;
		y1++;
		x2++;
		y2++;
		
		pref[x1][y1]++;
		pref[x1][y2]--;
		pref[x2][y1]--;
		pref[x2][y2]++;
	}
	for(int i = 1; i < mxN; i++) {
		for(int j = 1; j < mxN; j++) {
			pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}
	
	int ans = 0;
	for(int i = 1; i < mxN; i++) {
		for(int j = 1; j < mxN; j++) {
			if(pref[i][j] == k) {
				ans++;
			}
		}
	}
	cout << ans << nl;
}
