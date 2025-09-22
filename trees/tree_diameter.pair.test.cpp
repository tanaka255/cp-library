#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "trees/tree_diameter.hpp"

#include "template.hpp"
vector<vector<pair<int, ll>>> g;
vector<int> path;
void dfs(int u, int prev, int t) {
  path.emplace_back(u);
  if (u == t) {
    cout << path.size() << endl;
    rep(i, path.size()) cout << path[i] << " \n"[i + 1 == (int)path.size()];
  }
  for (auto& [v, _] : g[u]) {
    if (v == prev) continue;
    dfs(v, u, t);
  }
  path.pop_back();
}
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  cin >> N;
  g.assign(N, {});
  rep(i, N - 1) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }
  auto [u, v, X] = tree_diameter(g);
  cout << X << ' ';
  dfs(u, -1, v);
}
