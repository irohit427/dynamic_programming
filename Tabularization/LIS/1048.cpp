#include <bits/stdc++.h>
using namespace std;

static bool compare(const string& a, const string& b) {
  return a.length() < b.length();
}

int longestStrChain(vector<string>& words) {
  int n = words.size();
  map<string, int> dp;
  int ans = 0;
  sort(words.begin(), words.end(), compare);

  for (string word : words) {
    int l = word.length();
    for (int i = 0; i < word.length(); i++) {
      dp[word] = max(dp[word], dp[word.substr(0, i) + word.substr(i + 1, l - i)] + 1);
      ans = max(ans, dp[word]);
    }
  }
  return ans;
}
