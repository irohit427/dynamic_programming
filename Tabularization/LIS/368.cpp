#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
  int n = nums.size();
  if (n == 0) return {};
  vector<int> count(n, 1);

  sort(nums.begin(), nums.end());

  // LIS Snippet
  for (int i = 1; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (nums[i] % nums[j] == 0) {
        count[i] = max(count[i], count[j] + 1);
      }
    }
  }

  // find max index
  int maxIndex = 0;
  for (int i = 1; i < n; i++) {
    maxIndex = count[i] > count[maxIndex] ? i : maxIndex;
  }

  // constructing longest subset
  vector<int> ans;
  int temp = nums[maxIndex];
  int currentCount = count[maxIndex];
  for (int i = maxIndex; i >= 0; i--) {
    if (temp % nums[i] == 0 && currentCount == count[i]) {
      ans.push_back(nums[i]);
      temp = nums[i];
      currentCount--;
    }
  }
  return result;
}
