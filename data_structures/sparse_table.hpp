#pragma once
#include "template.hpp"

template <class S, S (*op)(S, S), S (*e)()>
struct sparse_table {
  int n;
  vector<vector<S>> st;

  sparse_table() : n(0) {}
  sparse_table(const vector<S>& v) : n(v.size()) {
    if (n == 0) return;
    int log_n = 0;
    while ((1 << log_n) <= n) ++log_n;
    st.assign(log_n, vector<S>(n));

    st[0] = v;
    rep(k, log_n - 1) {
      for (int i = 0; i + (1 << (k + 1)) <= n; ++i) {
        st[k + 1][i] = op(st[k][i], st[k][i + (1 << k)]);
      }
    }
  }

  S prod(int l, int r) {
    if (l >= r) return e();
    int k = 31 - __builtin_clz(r - l);
    return op(st[k][l], st[k][r - (1 << k)]);
  }
};
