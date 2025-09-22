#pragma once
#include "template.hpp"
struct union_find {
  vi par;

  union_find(int n) : par(n, -1) {}

  int root(int x) {
    if (par[x] < 0) return x;
    return par[x] = root(par[x]);
  }

  bool merge(int u, int v) {
    int x = root(u);
    int y = root(v);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  bool same(int x, int y) { return root(x) == root(y); }

  int size(int x) { return -par[root(x)]; }
};
