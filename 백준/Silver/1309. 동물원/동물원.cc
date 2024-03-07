#include <bits/stdc++.h>
using namespace std;

const int MOD = 9901;
int dp[100001][3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  dp[1][0] = 1;
  dp[1][1] = 1;
  dp[1][2] = 1;

  int n;
  cin >> n;

  for (int i = 2; i <= n; i++) {
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
    dp[i][0] %= MOD;
    dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
    dp[i][1] %= MOD;
    dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
    dp[i][2] %= MOD;
  }

  int sum = dp[n][0] + dp[n][1] + dp[n][2];
  cout << sum % 9901 << "\n";

  return 0;
}