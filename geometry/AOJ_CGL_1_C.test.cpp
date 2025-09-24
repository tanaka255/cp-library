#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C"
#include "geometry/core.hpp"
#include "template.hpp"
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  double x0, y0, x1, y1;
  cin >> x0 >> y0 >> x1 >> y1;
  Point p0(x0, y0), p1(x1, y1);
  int q;
  cin >> q;
  rep(_, q) {
    double x2, y2;
    cin >> x2 >> y2;
    Point p2(x2, y2);
    int ans = ccw(p0, p1, p2);
    switch (ans) {
      case COUNTER_CLOCKWISE:
        cout << "COUNTER_CLOCKWISE\n";
        break;
      case CLOCKWISE:
        cout << "CLOCKWISE\n";
        break;
      case ONLINE_BACK:
        cout << "ONLINE_BACK\n";
        break;
      case ONLINE_FRONT:
        cout << "ONLINE_FRONT\n";
        break;
      case ON_SEGMENT:
        cout << "ON_SEGMENT\n";
        break;
    }
  }
}
