#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C"
#include "geometry/core.hpp"
#include "template.hpp"
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  Polygon g(n);
  rep(i, n) {
    double x, y;
    cin >> x >> y;
    g[i] = Point(x, y);
  }
  int q;
  cin >> q;
  rep(_, q) {
    double x, y;
    cin >> x >> y;
    Point p(x, y);
    cout << polygon_point_containment(g, p) << '\n';
  }
}
