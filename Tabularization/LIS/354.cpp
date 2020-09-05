#include <bits/stdc++.h>
using namespace std;

int maxEnvelopes(vector<vector<int>>& envelopes) {
  int n = envelopes.size();
  if (n == 0 || n == 1)
    return n;

  sort(envelopes.begin(), envelopes.end());
  vector<int> dp(n, 0);
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
        dp[i] = max (dp[i], dp[j] + 1);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, dp[i]);
  }
  return ans;
}
