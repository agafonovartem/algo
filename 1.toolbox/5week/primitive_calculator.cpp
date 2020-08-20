#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;
/*vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}*/

/*
int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}*/

using namespace std;


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long dp[n+1];
    
    
  
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= n; i++){
        if (i % 2 == 0 && i % 3 == 0){
            dp[i] = min(min(dp[i / 3], dp[i / 2]), dp[i - 1]) + 1;
        }
        else if (i % 2 == 0 ){
            dp[i] = min( dp[i / 2], dp[i - 1]) + 1;
        }
        else if (i % 3 == 0 ){
            dp[i] = min( dp[i / 3], dp[i - 1]) + 1;
        }
        else{
            dp[i] = dp[i - 1] + 1;
        }
    }
    
    
    long x = n;
    vector<long> ans;
    while(x > 0){
        ans.push_back(x);
        if (x % 3 == 0 && dp[x] - 1 == dp[x/3]){
            x = x/3;
        } else if (x % 2 == 0 && dp[x] - 1 == dp[x/2]){
            x = x/2;
        } else {
            x = x - 1;
        }
    }
    
   
    
    cout << dp[n] << endl;
    for (long i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
    return 0;
}

