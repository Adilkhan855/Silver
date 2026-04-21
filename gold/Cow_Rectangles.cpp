#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

using ll = long long;

const int N = 1005;

int prefH[N][N], prefG[N][N];

int sumH(int x1, int y1, int x2, int y2) {
	x1--, y1--;
	return prefH[x2][y2] - prefH[x1][y2] - prefH[x2][y1] + prefH[x1][y1];
}

int sumG(int x1, int y1, int x2, int y2) {
	x1--, y1--;
	return prefG[x2][y2] - prefG[x1][y2] - prefG[x2][y1] + prefG[x1][y1];
}

void solve() {
	int n; cin >> n;
	
	vector<array<int, 2>> H, Hy;
	
	for(int i = 0; i < n; i++) {
		int x, y;
		
		char c;
		
		cin >> x >> y >> c;
		
		x++, y++;
		
		if(c == 'H') {
			prefH[x][y]++;
			H.push_back({x, y});
			Hy.push_back({y, x});
		} else {
			prefG[x][y]++;
		}
	}
	
	for(int x = 1; x < N; x++) {
		for(int y = 1; y < N; y++) {
			prefH[x][y] += prefH[x - 1][y] + prefH[x][y - 1] - prefH[x - 1][y - 1];
			prefG[x][y] += prefG[x - 1][y] + prefG[x][y - 1] - prefG[x - 1][y - 1];
		}
	}
	
	sort(H.begin(), H.end());
	sort(Hy.begin(), Hy.end());
	
	n = H.size();
	
	array<int, 2> ans{};
	
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			auto [xl, yl] = H[i];
			auto [xr, yr] = H[j];
			
			if(yl > yr) swap(yl, yr);
			
			if( sumG(xl, yl, xr, yr) > 0 ) continue;
			
			for(int k = 0; k < n; k++) {
				auto [y, x] = Hy[k];
				
				if(y >= yl) break;
				
				if(x > xr || x < xl) continue;
				
				if( sumG(xl, y, xr, yl) == 0 ) {
					yl = y;
					break;
				}
			}
			
			for(int k = n - 1; k >= 0; k--) {
				auto [y, x] = Hy[k];
				
				if(y <= yr) break;
				
				if(x > xr || x < xl) continue;
				
				if( sumG(xl, yr, xr, y) == 0 ) {
					yr = y;
					break;
				}
			}
			
			int cnt = sumH(xl, yl, xr, yr);
			int area = (xr - xl) * (yr - yl);
			
			if(ans[0] < cnt || (ans[0] == cnt && ans[1] > area)) {
				// cout << nl;
				// cout << "here: " << nl;
				// cout << i << ' ' << j << nl;
				// cout << cnt << ' ' << area << nl;
				// cout << xl << ' ' << yl << ' ' << xr << ' ' << yr << nl;
				ans = {cnt, area};
			}
		}
	}
	
	cout << ans[0] << nl << ans[1] << nl;
}

signed main() {
	freopen("cowrect.in", "r", stdin);
	freopen("cowrect.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
