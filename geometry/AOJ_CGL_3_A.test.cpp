#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A"
#define ERROR 0.00000001
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
  cout << fixed << setprecision(20) << area(g) << endl;
}
