#pragma once
#include "template.hpp"

vector<int> longest_increasing_subsequence(const vector<int>& v,
                                           bool strictly = true) {
  if (v.empty()) return {};
  vector<int> dp, idx, prev(v.size());
  rep(i, v.size()) {
    auto it = strictly ? lower_bound(dp.begin(), dp.end(), v[i])
                       : upper_bound(dp.begin(), dp.end(), v[i]);
    int pos = it - dp.begin();
    if (it == dp.end()) {
      dp.emplace_back(v[i]);
      idx.emplace_back(i);
    } else {
      *it = v[i];
      idx[pos] = i;
    }
    prev[i] = (0 < pos) ? idx[pos - 1] : -1;
  }
  vector<int> ret;
  for (int i = idx.back(); i != -1; i = prev[i]) ret.emplace_back(i);
  ranges::reverse(ret);
  return ret;
}
