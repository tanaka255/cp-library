#pragma once
#include "data_structure/sparse_table.hpp"
#include "template.hpp"
struct lowest_common_ancestor {
  using P = pair<int, int>;
  static P op(P a, P b) { return min(a, b); }
  static P e() { return {1 << 30, -1}; }

  int n;
  vvi g;
  vi depth, pos;
  vector<P> tour;
  sparse_table<P, op, e> st;

  lowest_common_ancestor(const vvi& _g, int root = 0)
      : n(_g.size()), g(_g), depth(_g.size()), pos(_g.size()) {
    dfs(root, -1, 0);
    st = sparse_table<P, op, e>(tour);
  }

  void dfs(int u, int p, int d) {
    depth[u] = d;
    pos[u] = tour.size();
    tour.emplace_back(d, u);
    for (int v : g[u]) {
      if (v == p) continue;
      dfs(v, u, d + 1);
      tour.emplace_back(d, u);
    }
  }

  int query(int u, int v) {
    int l = pos[u], r = pos[v];
    if (l > r) swap(l, r);
    return st.prod(l, r + 1).second;
  }

  int dist(int u, int v) {
    int l = query(u, v);
    return depth[u] + depth[v] - 2 * depth[l];
  }
};
