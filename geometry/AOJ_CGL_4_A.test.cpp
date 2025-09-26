#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A"
#include "geometry/core.hpp"
#include "template.hpp"
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vi x(n), y(n);
  Polygon g(n);
  rep(i, n) {
    cin >> x[i] >> y[i];
    g[i] = Point(x[i], y[i]);
  }
  vi res = convex_hull(g);
  pair<int, int> mn = {1 << 30, 1 << 30};
  int mni = -1, siz = res.size();
  rep(i, siz) {
    if (chmin(mn, make_pair(y[res[i]], x[res[i]]))) mni = i;
  }
  cout << siz << endl;
  rep(i, siz) cout << x[res[(mni + i) % siz]] << ' ' << y[res[(mni + i) % siz]]
                   << '\n';
}
