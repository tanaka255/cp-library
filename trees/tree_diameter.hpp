#pragma once
#include "template.hpp"
tuple<int, int, ll> tree_diameter(const vector<vector<pair<int, ll>>>& g) {
  function<pair<ll, int>(int, int)> dfs = [&](int u, int prev) {
    pair<ll, int> ret = {0, u};
    for (const auto& [v, w] : g[u]) {
      if (v == prev) continue;
      auto [mx, mxv] = dfs(v, u);
      ret = max(ret, make_pair(mx + w, mxv));
    }
    return ret;
  };
  int u = dfs(0, -1).second;
  auto [d, v] = dfs(u, -1);
  return {u, v, d};
}
