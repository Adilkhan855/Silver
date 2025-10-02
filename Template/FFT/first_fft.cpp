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

using cmpl = complex<double>;

const double PI = atan2(0, -1);

vector<cmpl> fft(vector<cmpl> P) {
	int n = P.size();
	
	if(n == 1) {
		return P;
	}
	
	// P(x) = P0 + P1 * x + P2 * x ^ 2 + P3 * x ^ 3 ...
	// P(-x) = P0 - P1 * x + P2 * x ^ 2 - P3 * x ^ 3 ...
	
	// P_even(x) = P0 + P2 * x + P4 * x ^ 2 + P6 * x ^ 3 ...
	// P_odd(x) = P1 + P3 * x + P5 * x ^ 2 + P7 * x ^ 3 ...
	
	// P(x) = P_even(x ^ 2) + x * P_odd(x ^ 2)
	// P(-x) = P_even(x ^ 2) - x * P_odd(x ^ 2)
	
	// angle(j) = 2 * PI * j / n
	// angle(j) == -angle(j + n / 2)
	
	// x = angle(j)
	
	vector<cmpl> P_even(n / 2), P_odd(n / 2);
	
	for(int j = 0; j < n / 2; j++) {
		P_even[j] = P[2 * j];
		P_odd[j] = P[2 * j + 1];
	}
	
	vector<cmpl> val_even = fft(P_even);
	vector<cmpl> val_odd = fft(P_odd);
	vector<cmpl> P_val(n);
	
	for(int j = 0; j < n / 2; j++) {
		cmpl wj( cos(2 * PI * j / n), sin(2 * PI * j / n) );
		P_val[j] = val_even[j] + wj * val_odd[j];
		P_val[j + n / 2] = val_even[j] - wj * val_odd[j];
	}
	
	return P_val;
}

vector<cmpl> ifft(vector<cmpl> P_val) {
	int n = P_val.size();
	
	if(n == 1) {
		return P_val;
	}
	
	// P_val[j] = val_even[j] + wj * val_odd[j];
	// P_val[j + n / 2] = val_even[j] - wj * val_odd[j]
	
	// val_even[j] = (P_val[j] + P_val[j + n / 2]) / 2
	// val_odd[j] = (P_val[j] - P_val[j + n / 2]) / (2 * wj)
	
	vector<cmpl> val_even(n / 2), val_odd(n / 2);
	
	for(int j = 0; j < n / 2; j++) {
		cmpl wj( cos(2 * PI * j / n), sin(2 * PI * j / n) );
		val_even[j] = (P_val[j] + P_val[j + n / 2]) / cmpl(2, 0);
		val_odd[j] = (P_val[j] - P_val[j + n / 2]) / (wj * cmpl(2, 0));
	}
	
	vector<cmpl> P_even = ifft(val_even);
	vector<cmpl> P_odd = ifft(val_odd);
	vector<cmpl> P(n);
	
	for(int j = 0; j < n / 2; j++) {
		P[2 * j] = P_even[j];
		P[2 * j + 1] = P_odd[j];
	}
	
	return P;
}

vector<int> multiply(vector<int> &P, vector<int> &Q) {
	int n = 1;
	
	while(n < (int)P.size() + (int)Q.size() - 1) {
		n <<= 1;
	}
	
	vector<cmpl> P_cmpl(n), Q_cmpl(n);
	
	copy(all(P), P_cmpl.begin());
	copy(all(Q), Q_cmpl.begin());
	
	// cout << n << nl;
	
	// for(int i = 0; i < n; i++) {
		// cout << P_cmpl[i] << ' ';
	// }
	// cout << nl;
	
	// for(int i = 0; i < n; i++) {
		// cout << Q_cmpl[i] << ' ';
	// }
	// cout << nl;
	
	vector<cmpl> P_val = fft(P_cmpl);
	vector<cmpl> Q_val = fft(Q_cmpl);
	vector<cmpl> R_val(n);
	
	for(int j = 0; j < n; j++) {
		R_val[j] = P_val[j] * Q_val[j];
	}
	
	vector<cmpl> R_cmpl = ifft(R_val);
	vector<int> R(n);
	
	// for(auto j = 0; j < n; j++) {
		// cout << R_cmpl[j] << ' ';
	// }
	// cout << nl;
	
	for(int j = 0; j < n; j++) {
		R[j] = round(R_cmpl[j].real());
	}
	
	return R;
}

void solve() {
	int n; cin >> n;
	
	vector<int> A(n);
	
	for(auto &x : A) cin >> x;
	
	int m; cin >> m;
	
	vector<int> B(m);
	
	for(auto &x : B) cin >> x;
	
	auto C = multiply(A, B);
	
	for(int i = 0; i < n + m - 1; i++) {
		cout << C[i] << ' ';
	}
	
	cout << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
