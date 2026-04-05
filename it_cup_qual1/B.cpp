#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define int long long

using ll = long long;

bool chmax(int &a, const int &b) {
    return a < b ? a = b, true : false;
}

void mul_self8(vector<int> &a) {
    int cur = 0;

    for(int i = 0; i < (int)a.size(); i++) {
        cur += a[i] * 8;
        a[i] = cur % 10;
        cur /= 10;
    }

    while(cur > 0) {
        a.push_back(cur % 10);
        cur /= 10;
    }

    while(!a.empty() && a.back() == 0) a.pop_back();
}

void add_self(vector<int> &a, const int &d) {
    int cur = d;

    for(int i = 0; i < (int)a.size(); i++) {
        cur += a[i];
        a[i] = cur % 10;
        cur /= 10;
    }

    while(cur > 0) {
        a.push_back(cur % 10);
        cur /= 10;
    }

    while(!a.empty() && a.back() == 0) a.pop_back();
}

int div_self8(vector<int> &a) {
    int cur = 0;

    vector<int> b;

    for(int i = (int)a.size() - 1; i >= 0; i--) {
        cur = cur * 10 + a[i];
//
//        cout << nl;
//
//        cout << "cur cnt: " << cur << ' ' << cnt << nl;

        b.push_back(cur / 8);
        cur %= 8;
    }

    a = b;

    int d = 0;

    if(cur == 1) {
        a.push_back(1);
        a.push_back(2);
        a.push_back(5);
        d = 3;
    }

    if(cur == 2) {
        a.push_back(2);
        a.push_back(5);
        d = 2;
    }

    if(cur == 3) {
        a.push_back(3);
        a.push_back(7);
        a.push_back(5);
        d = 3;
    }

    if(cur == 4) {
        a.push_back(5);
        d = 1;
    }

    if(cur == 5) {
        a.push_back(6);
        a.push_back(2);
        a.push_back(5);
        d = 3;
    }

    if(cur == 6) {
        a.push_back(7);
        a.push_back(5);
        d = 2;
    }

    if(cur == 7) {
        a.push_back(8);
        a.push_back(7);
        a.push_back(5);
        d = 3;
    }

    reverse(a.begin(), a.end());

    while(!a.empty() && a.back() == 0) a.pop_back();

    return d;
}

void output(const vector<int> &a) {
    if(a.empty()) {
        cout << 0 << nl;
        return;
    }

    for(int i = (int)a.size() - 1; i >= 0; i--) {
        cout << a[i];
    }

    cout << nl;
}

void solve() {
    string s; cin >> s;

    vector<int> a;

//    cout << nl;

//    cout << "add and multiply: " << nl;

    for(int i = 2; i < (int)s.size(); i++) {
        mul_self8(a);
        add_self(a, (int)s[i] - '0');
//        cout << "char: " << s[i] - '0' << nl;
//        output(a);
    }

    assert(!a.empty());

    int cnt = 0;

    int k = s.size() - 2;

//    cout << nl;
//
//    cout << "division: " << nl;

    for(int i = 0; i < k; i++) {
        cnt += div_self8(a);
//        output(a);
//        cout << "cnt: " << cnt << nl;
    }

    reverse(a.begin(), a.end());

    assert( cnt >= a.size() );

    vector<int> b;

    while(!a.empty() && cnt > 0) {
        b.push_back(a.back());
        a.pop_back();
        cnt--;
    }

    assert(a.empty());

    while(cnt > 0) {
        b.push_back(0);
        cnt--;
    }

    reverse(b.begin(), b.end());

    while(!b.empty() && b.back() == 0) b.pop_back();

    assert(!b.empty());

    cout << "0.";

    for(auto &x : b) cout << x;

    cout << nl;
}

/**

**/

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
