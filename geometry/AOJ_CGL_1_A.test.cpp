#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A"
#define ERROR 0.00000001
#include "geometry/core.hpp"
#include "template.hpp"
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  Point p1(x1, y1), p2(x2, y2);
  cout << fixed << setprecision(20);
  int q;
  cin >> q;
  rep(_, q) {
    double x, y;
    cin >> x >> y;
    Point p(x, y);
    Point ans = projection(p1, p2, p);
    cout << ans.real() << ' ' << ans.imag() << '\n';
  }
}
