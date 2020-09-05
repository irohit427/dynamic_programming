#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
  int n = nums.size(), maxLen = 1;
  vector<int> dp(n, 1), count(n, 1);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (nums[j] < nums[i]) {
        // dp[i] = max(dp[i], dp[j] + 1);
        if (dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          count[i] = count[j];
        } else if (dp[i] == dp[j] + 1) {
          count[i]+= count[j];
        }
      }
    }
    maxLen = max(maxLen, dp[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (dp[i] == maxLen)) {
      ans += count[i];
    }
  }
  return ans;
}
