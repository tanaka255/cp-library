#pragma once
#include "template.hpp"
template <typename T>
struct fenwick_tree {
  int n;
  vector<T> bit;

  fenwick_tree(int _n) : n(_n), bit(_n + 1, 0) {}

  void add(int i, T x) {
    ++i;
    while (i <= n) {
      bit[i] += x;
      i += i & -i;
    }
  }

  T sum(int i) {
    T s = 0;
    while (i) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }

  T sum(int l, int r) { return sum(r) - sum(l); }
};
