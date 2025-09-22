#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"
#include "data_structures/lazy_segment_tree.hpp"

#include "template.hpp"
int op(int a, int b) { return min(a, b); }
int e() { return numeric_limits<int>::max(); }
int mapping(int a, int b) { return a == e() ? b : a; }
int composition(int a, int b) { return a == e() ? b : a; }
int id() { return numeric_limits<int>::max(); }
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  lazy_segment_tree<int, op, e, int, mapping, composition, id> seg(n);
  rep(_, q) {
    int qt;
    cin >> qt;
    if (qt == 0) {
      int s, t, x;
      cin >> s >> t >> x;
      ++t;
      seg.apply(s, t, x);
    } else {
      int s, t;
      cin >> s >> t;
      ++t;
      cout << seg.prod(s, t) << '\n';
    }
  }
}
