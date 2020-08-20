#include <iostream>
#include <vector>

using std::vector;
using std::max;


int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
    int n = a.size();
    int m = b.size();
    int k = c.size();
    vector<vector<vector<int>>> dp (n + 1, vector<vector<int>> (m + 1, vector <int>(k + 1, 0)));;
  
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int l = 1; l <= k; l++){
                if (a[i-1] == b[j-1] && a[i-1] == c[l-1]){
                    dp[i][j][l] = max(max(dp[i][j-1][l], dp[i-1][j][l]), max(dp[i-1][j-1][l-1] + 1, dp[i][j][l-1]));
                } else{
                    dp[i][j][l] = max(max(dp[i][j-1][l], dp[i-1][j][l]), dp[i][j][l-1]);
                }
            }
        }
    }
    
    
    return dp[n][m][k];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
