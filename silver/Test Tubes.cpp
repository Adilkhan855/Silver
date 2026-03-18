#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int inf = 1e9 + 5;

void solve() {
	int n, p; cin >> n >> p;
	
	string s, t; cin >> s >> t;
	
	bool put = false;
	
	vector<array<int, 2>> ans;
	
	auto rec = [&](auto &&self, int sz1, int sz2, int top1, int top2, int type, int beak, int inbeak, int who) -> int {
		// if(put) {
			// cout << "here: " << sz1 << ' ' << sz2 << ' ' << top1 << ' ' << top2 << ' ' << type << ' ' << beak << ' ' << inbeak << ' ' << who << '\n';
		// }
		
		if(type == 1) {
			if( (sz1 == 0 || (sz1 == 1 && top1 == 1)) && (sz2 == 0 || (sz2 == 1 && top2 == 2))) {
				if(put) {
					if(inbeak) {
						if(beak == 1) ans.push_back({3, 1});
						else ans.push_back({3, 2});
					}
				}
				return inbeak;
			}
			
			if( sz1 == 2 && top1 == 2 && (sz2 == 0 || (sz2 == 1 && top2 == 2)) ) {
				// 1 -> 2
				if(put) {
					ans.push_back({1, 2});[
					if(inbeak) {
						if(beak == 1) ans.push_back({3, 1});
						else ans.push_back({3, 2});
					}
				}
				return 1 + inbeak;
			}
			
			if( sz2 == 2 && top2 == 1 && (sz1 == 0 || (sz1 == 1 && top1 == 1)) ) {
				// 2 -> 1
				if(put) {
					ans.push_back({2, 1});
					if(inbeak) {
						if(beak == 1) ans.push_back({3, 1});
						else ans.push_back({3, 2});
					}
				}
				return 1 + inbeak;
			}
		} else {
			if( (sz1 == 0 || (sz1 == 1 && top1 == 2)) && (sz2 == 0 || (sz2 == 1 && top2 == 1)) ) {
				if(put) {
					if(inbeak) {
						if(beak == 1) ans.push_back({3, 1});
						else ans.push_back({3, 2});
					}
				}
				return inbeak;
			}
			
			if( sz1 == 2 && top1 == 1 && (sz2 == 0 || (sz2 == 1 && top2 == 1)) ) {
				// 1 -> 2
				if(put) {
					ans.push_back({1, 2});
					if(inbeak) {
						if(beak == 1) ans.push_back({3, 1});
						else ans.push_back({3, 2});
					}
				}
				return 1 + inbeak;
			}
			
			if( sz2 == 2 && top2 == 2 && (sz1 == 0 || (sz1 == 1 && top1 == 2)) ) {
				// 2 -> 1
				if(put) {
					ans.push_back({2, 1});
					if(inbeak) {
						if(beak == 1) ans.push_back({3, 1});
						else ans.push_back({3, 2});
					}
				}
				return 1 + inbeak;
			}
		}
		
		int cnt = 0;
		
		if(sz1 > 0 && top1 == beak) { // 1 -> 3
			sz1--;
			top1 = 3 - top1;
			cnt++;
			if(put) {
				ans.push_back({1, 3});
			}
		}
		
		if(sz2 > 0 && top2 == beak) { // 2 -> 3
			sz2--;
			top2 = 3 - top2;
			cnt++;
			if(put) {
				ans.push_back({2, 3});
			}
		}
		
		int is = 0;
		
		if(who == 1) {
			if(sz1 > 0) { // 1 2
				sz1--;
				top1 = 3 - top1;
				if(put) {
					ans.push_back({1, 2});
				}
				is = 1;
				if(sz2 == 0) {
					sz2++;
					top2 = 3 - beak;
				}
			}
		} else {
			if(sz2 > 0) { // 2 1
				sz2--;
				top2 = 3 - top2;
				if(put) {
					ans.push_back({2, 1});
				}
				is = 1;
				if(sz1 == 0) {
					sz1++;
					top1 = 3 - beak;
				}
			}
		}
		
		return self(self, sz1, sz2, top1, top2, type, beak, (inbeak || cnt > 0), 3 - who) + is + cnt;
	};
	
	int sz1 = 0, sz2 = 0;
	
	for(int i = 0, j = i; i < n; i = j) {
		while(j < n && s[i] == s[j]) j++;
		sz1++;
	}
	
	for(int i = 0, j = i; i < n; i = j) {
		while(j < n && t[i] == t[j]) j++;
		sz2++;
	}
	
	int top1 = s.back() - '0', top2 = t.back() - '0';
	
	int mn = inf, beak1 = 0, type1 = 0, who1 = 0;
	
	for(int type = 1; type <= 2; type++) {
		for(int beak = 1; beak <= 2; beak++) {
			for(int who = 1; who <= 2; who++) {
				int res = rec(rec, sz1, sz2, top1, top2, type, beak, false, who);
				if(mn > res) {
					mn = res;
					beak1 = beak;
					type1 = type;
					who1 = who;
				}
			}
		}
	}
	
	cout << '\n';
	
	cout << type1 << ' ' << beak1 << ' ' << who1 << '\n';
	
	cout << mn << '\n';
	
	if(p >= 2) {
		put = true;
		
		rec(rec, sz1, sz2, top1, top2, type1, beak1, false, who1);
		
		assert( (int)ans.size() == mn );
		
		for(auto &[x, y] : ans) {
			cout << x << ' ' << y << '\n';
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while(tt--) solve();
}
