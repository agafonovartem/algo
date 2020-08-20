#include <iostream>
#include <vector>

using std::vector;
using std::max;

int lcs2(vector<int> &a, vector<int> &b) {
  int n = a.size();
  int m = b.size();
  vector <vector <int>> dp;
  dp.assign(n + 1, vector<int> (m + 1, 0));
  for (int i = 0; i <= n; i++){
      dp[i][0] = 0;
  }
  for (int i = 0; i <= m; i++){
      dp[0][i] = 0;
  }
  for (int i = 1; i <= n; i++){
      for (int j = 1; j <= m; j++){
          if (a[i-1] == b[j-1]){
              dp[i][j] = max(max(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1] + 1);
          } else{
              dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
          }
      }
  }
  return dp[n][m];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
