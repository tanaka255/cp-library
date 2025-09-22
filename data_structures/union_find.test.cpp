#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "data_structures/union_find.hpp"

#include "template.hpp"
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  union_find uf(N);
  rep(_, Q) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 0)
      uf.merge(u, v);
    else
      cout << uf.same(u, v) << '\n';
  }
}
