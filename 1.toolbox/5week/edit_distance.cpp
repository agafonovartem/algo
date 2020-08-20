#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::min;

int edit_distance(const string &str1, const string &str2) {
    int n = str1.size();
    int m = str2.size();
    vector <vector <int>> dp;
    dp.assign(n + 1, vector<int> (m + 1, 0));
    for (int i = 0; i <= n; i++){
        dp[i][0] = i;
    }
    for (int i = 0; i <= m; i++){
        dp[0][i] = i;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int insertion = dp[i][j-1] + 1;
            int deletion = dp[i-1][j] + 1;
            int match = dp[i-1][j-1];
            int mismatch = dp[i-1][j-1] + 1;
            if (str1.at(i-1) == str2.at(j-1)){
                dp[i][j] = min(min(insertion, deletion), match);
            } else{
                dp[i][j] = min(min(insertion, deletion), mismatch);
            }
        }
    }
    return dp[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
