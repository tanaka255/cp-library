#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C"
#define ERROR 0.000001
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
  cout << fixed << setprecision(20);
  int q;
  cin >> q;
  rep(_, q) {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Line l = Line(Point(x1, y1), Point(x2, y2));
    cout << area(convex_cut(g, l)) << '\n';
  }
}
