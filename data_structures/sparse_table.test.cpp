#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "data_structures/sparse_table.hpp"

#include "template.hpp"
int op(int a, int b) { return min(a, b); }
int e() { return 1 << 30; }
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  rep(i, N) cin >> a[i];
  sparse_table<int, op, e> st(a);
  rep(_, Q) {
    int l, r;
    cin >> l >> r;
    cout << st.prod(l, r) << '\n';
  }
}
