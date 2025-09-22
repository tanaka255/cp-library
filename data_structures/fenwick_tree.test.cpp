#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "data_structures/fenwick_tree.hpp"

#include "template.hpp"
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  fenwick_tree<ll> fw(N);
  rep(i, N) {
    int a;
    cin >> a;
    fw.add(i, a);
  }
  rep(_, Q) {
    int qt;
    cin >> qt;
    if (qt == 0) {
      int p, x;
      cin >> p >> x;
      fw.add(p, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << fw.sum(l, r) << '\n';
    }
  }
}
