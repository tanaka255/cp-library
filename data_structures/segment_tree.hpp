#pragma once
#include "template.hpp"
template <class S, S (*op)(S, S), S (*e)()>
struct segment_tree {
  int n, size;
  vector<S> d;

  segment_tree() : segment_tree(0) {}
  segment_tree(int _n) : segment_tree(vector<S>(_n, e())) {}
  segment_tree(const vector<S>& v) : n(v.size()) {
    size = 1;
    while (size < n) size <<= 1;
    d.assign(2 * size, e());
    rep(i, n) d[size + i] = v[i];
    for (int i = size - 1; 1 <= i; --i) update(i);
  }

  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }

  void set(int p, S x) {
    p += size;
    d[p] = x;
    while (1 < p) {
      p >>= 1;
      update(p);
    }
  }

  S get(int p) { return d[p + size]; }

  S prod(int l, int r) {
    S sml = e(), smr = e();
    l += size, r += size;
    while (l < r) {
      if (l & 1) sml = op(sml, d[l++]);
      if (r & 1) smr = op(d[--r], smr);
      l >>= 1, r >>= 1;
    }
    return op(sml, smr);
  }
};
