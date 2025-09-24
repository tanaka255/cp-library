#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_2_A"
#include "geometry/core.hpp"
#include "template.hpp"
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q;
  cin >> q;
  rep(_, q) {
    vector<Point> p(4);
    rep(i, 4) {
      double x, y;
      cin >> x >> y;
      p[i] = Point(x, y);
    }
    Line s1(p[0], p[1]), s2(p[2], p[3]);
    if (is_parallel(s1, s2)) {
      cout << 2 << '\n';
    } else if (is_orthogonal(s1, s2)) {
      cout << 1 << '\n';
    } else {
      cout << 0 << '\n';
    }
  }
}
