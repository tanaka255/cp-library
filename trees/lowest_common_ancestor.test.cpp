#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"
#include "trees/lowest_common_ancestor.hpp"

#include "template.hpp"
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  rep(u, n) {
    int k;
    cin >> k;
    rep(_, k) {
      int v;
      cin >> v;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
  }
  lowest_common_ancestor lca(g);
  int q;
  cin >> q;
  rep(_, q) {
    int u, v;
    cin >> u >> v;
    cout << lca.query(u, v) << '\n';
  }
}
