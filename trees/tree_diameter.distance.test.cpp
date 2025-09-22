#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A"
#include "trees/tree_diameter.hpp"

#include "template.hpp"
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  cin >> N;
  vector<vector<pair<int, ll>>> g(N);
  rep(i, N - 1) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }
  auto ans = get<2>(tree_diameter(g));
  cout << ans << endl;
}
