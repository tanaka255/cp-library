#pragma once
#include "template.hpp"
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
struct lazy_segment_tree {
  int n, size, log;
  vector<S> d;
  vector<F> lz;

  lazy_segment_tree() : lazy_segment_tree(0) {}
  lazy_segment_tree(int _n) : lazy_segment_tree(vector<S>(_n, e())) {}
  lazy_segment_tree(const vector<S>& v) : n(v.size()) {
    log = 0;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    d.assign(2 * size, e());
    lz.assign(size, id());
    rep(i, n) d[size + i] = v[i];
    for (int i = size - 1; 1 <= i; --i) update(i);
  }

  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }

  void all_apply(int k, F f) {
    d[k] = mapping(f, d[k]);
    if (k < size) lz[k] = composition(f, lz[k]);
  }

  void push(int k) {
    all_apply(2 * k, lz[k]);
    all_apply(2 * k + 1, lz[k]);
    lz[k] = id();
  }

  void set(int p, S x) {
    p += size;
    for (int i = log; 1 <= i; --i) push(p >> i);
    d[p] = x;
    for (int i = 1; i <= log; ++i) update(p >> i);
  }

  S get(int p) {
    p += size;
    for (int i = log; 1 <= i; --i) push(p >> i);
    return d[p];
  }

  S prod(int l, int r) {
    if (l >= r) return e();
    l += size, r += size;
    for (int i = log; 1 <= i; --i) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }
    S sml = e(), smr = e();
    while (l < r) {
      if (l & 1) sml = op(sml, d[l++]);
      if (r & 1) smr = op(d[--r], smr);
      l >>= 1, r >>= 1;
    }
    return op(sml, smr);
  }

  void apply(int p, F f) {
    p += size;
    for (int i = log; 1 <= i; --i) push(p >> i);
    d[p] = mapping(f, d[p]);
    for (int i = 1; i <= log; ++i) update(p >> i);
  }

  void apply(int l, int r, F f) {
    if (l >= r) return;
    l += size, r += size;
    for (int i = log; 1 <= i; --i) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }
    int l0 = l, r0 = r;
    while (l < r) {
      if (l & 1) all_apply(l++, f);
      if (r & 1) all_apply(--r, f);
      l >>= 1, r >>= 1;
    }
    l = l0, r = r0;
    for (int i = 1; i <= log; ++i) {
      if (((l >> i) << i) != l) update(l >> i);
      if (((r >> i) << i) != r) update((r - 1) >> i);
    }
  }
};
