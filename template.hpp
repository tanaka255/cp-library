#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(a) begin(a), end(a)
#define eb emplace_back
#define si(a) int(size(a))

#define ov4(a, b, c, d, name, ...) name
#define rep3(i, a, b, c) for (ll i = (ll)(a); i < (ll)(b); i += (ll)(c))
#define rep2(i, a, b) rep3(i, a, b, 1)
#define rep1(i, n) rep2(i, 0, n)
#define rep(...) ov4(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using vvvvb = vector<vvvb>;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vvvvi = vector<vvvi>;

using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vvvvl = vector<vvvl>;

bool chmax(auto& a, const auto& b) { return a < b ? (a = b, true) : false; }
bool chmin(auto& a, const auto& b) { return a > b ? (a = b, true) : false; }
