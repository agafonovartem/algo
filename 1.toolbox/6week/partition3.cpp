#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A) {
    int sum = 0;
    for (const auto &item : A){
        sum += item;
    }
    //std::cout << sum << '\n';
    if (sum % 3 != 0){
        return 0;
    }
    int n = sum / 3;
    vector<vector<vector<int>>> dp (n + 1, vector<vector<int>> (n + 1, vector <int>(A.size() + 1, 0)));
    dp[0][0][0] = 1;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            for (int k = 1; k <= A.size(); k++){
                dp[i][j][k] = dp[i][j][k-1];
                if (A[k-1] <= i){
                    dp[i][j][k] = dp[i][j][k] | dp[i - A[k-1]][j][k-1] ;
                }
                if (A[k-1] <= j){
                    dp[i][j][k] = dp[i][j][k] | dp[i][j - A[k-1]][k-1] ;
                }
                //std::cout << "dp[" << i <<"][" << j << "][" << k << "] = " << dp[i][j][k] << '\n';
            }
        }
    }
    
    return dp[n][n][A.size()];
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
