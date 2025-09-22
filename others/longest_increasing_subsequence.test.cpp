#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"
#include "others/longest_increasing_subsequence.hpp"

#include "template.hpp"
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  auto ans = longest_increasing_subsequence(A);
  cout << ans.size() << endl;
  rep(i, ans.size()) cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
}
