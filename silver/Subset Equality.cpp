#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

void solve() {
	string s, t; cin >> s >> t;
	
	vector<int> freqS(26), freqT(26);
	
	for(auto &c : s) freqS[c - 'a']++;
	for(auto &c : t) freqT[c - 'a']++;
	
	vector<vector<bool>> ch(26, vector<bool>(26));
	
	for(char c1 = 'a'; c1 <= 'r'; c1++) {
		for(char c2 = c1 + 1; c2 <= 'r'; c2++) {
			string _s, _t;
			for(auto &c : s) {
				if(c == c1 || c == c2) _s += c;
			}
			for(auto &c : t) {
				if(c == c1 || c == c2) _t += c;
			}
			ch[c1 - 'a'][c2 - 'a'] = ch[c2 - 'a'][c1 - 'a'] = (_s == _t);
		}
	}
	
	auto check = [&](const string &X) {
		for(int i = 0; i < (int)X.size(); i++) {
			for(int j = i + 1; j < (int)X.size(); j++) {
				if(!ch[X[i] - 'a'][X[j] - 'a']) return false;
			}
		}
		return true;
	};
	
	int q; cin >> q;
	
	while(q--) {
		string X; cin >> X;
		
		int lenS = 0, lenT = 0;
		
		for(auto &c : X) {
			lenS += freqS[c - 'a'];
			lenT += freqT[c - 'a'];
		}
		
		cout << (lenS == lenT && check(X) ? 'Y' : 'N');
	}
	
	cout << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
