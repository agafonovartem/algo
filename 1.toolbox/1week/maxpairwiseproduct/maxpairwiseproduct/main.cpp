#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;


int bin_search_lower(vector<int> &points, int x){ // первый элемент меньше
    int ans = -1;
    int low = 0;
    int high = points.size() - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if (points[mid] >= x){
            high = mid - 1;
        }
        else{
            low = mid + 1;
            ans = low;
        }
    }
    //std::cout << "BIN SEARCH LOWER FOUND " << ans << '\n';
    return ans;
}

int bin_search_greater(vector<int> &points, int x){ // первый элемент меньше
    int ans = -1;
    int low = 0;
    int high = points.size() - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if (points[mid] <= x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
            ans = high;
        }
    }
    //std::cout << "BIN SEARCH GREATER FOUND " << ans << '\n';
    return ans;
}


vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    sort(points.begin(), points.end());
    for (size_t i = 0; i < starts.size(); i++){
        std::cout << "i = " << i << " ";
        int lower = bin_search_lower(points, starts[i]);
        std::cout << "LOWER = " << lower << " ";
        int greater = bin_search_greater(points, ends[i]);
        std::cout << "GRATER = " << greater << '\n';
        if (lower - greater > 0){
            cnt[i] = lower - greater - 1;
        } else{
            cnt[i] = 0;
        }
    }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
