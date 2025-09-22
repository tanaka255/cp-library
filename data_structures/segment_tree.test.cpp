#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "data_structures/segment_tree.hpp"

#include "template.hpp"
ll op(ll a, ll b) { return a + b; }
ll e() { return 0; }
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  vll a(N);
  rep(i, N) cin >> a[i];
  segment_tree<ll, op, e> seg(a);
  rep(_, Q) {
    int qt;
    cin >> qt;
    if (qt == 0) {
      int p, x;
      cin >> p >> x;
      seg.set(p, seg.get(p) + x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << seg.prod(l, r) << '\n';
    }
  }
}
