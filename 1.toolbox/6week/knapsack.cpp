#include <iostream>
#include <vector>

using std::vector;
using std::min;
int optimal_weight(int W, const vector<int> &w) {
  //write your code here
    vector<vector<int>> dp;
    dp.assign(W + 1, vector<int> (w.size() + 1, 0));
    for (int i = 1; i <= W; i++){
        for (int j = 1; j <= w.size(); j++){
            dp[i][j] = dp[i][j-1];
            if (w[j - 1] <= i){
                int val =  dp[i - w[j-1]][j-1] + w[j-1];
                if (val > dp[i][j]){
                    dp[i][j] = val;
                }
            }
        }
    }
    
    return dp[W][w.size()];
    /*
    i2nt current_weight = 0;
    for (size_t i = 0; i < w.size(); ++i) {
        if (current_weight + w[i] <= W) {
            current_weight += w[i];
        }
    }
    return current_weight;*/
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
