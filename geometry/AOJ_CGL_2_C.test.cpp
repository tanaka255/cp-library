#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C"
#define ERROR 0.00000001
#include "geometry/core.hpp"
#include "template.hpp"
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
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
    Point ans = cross_point(s1, s2);
    cout << ans.real() << ' ' << ans.imag() << '\n';
  }
}
