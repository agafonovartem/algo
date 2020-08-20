#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;


int get_count_in_range(vector<int> &a, int a_, int left, int right){
    int cntr = 0;
    for (int i = left; i < right; i++){
        if (a[i] == a_){
            cntr++;
        }
    }
    return cntr;
}


int get_majority_element(vector<int> &a, int left, int right) {
    if (left == right) return -1;
    if (left + 1 == right) return a[left];
    int mid = left + (right - left)/2;
    //std::cout << "mid = " << mid << std::endl;
    int a_left = get_majority_element(a, left, mid);
    //std::cout << "a_left = " << a_left << std::endl;
    int a_right = get_majority_element(a, mid, right);
    //std::cout << "a_right = " << a_right << std::endl;
    if (a_left == a_right){
        return a_left;
    }
    else {
        int cntr_left = get_count_in_range(a, a_left, left, right);
        int cntr_right = get_count_in_range(a, a_right, left, right);
        
        if (cntr_left < cntr_right && cntr_right > (right - left)/2){
            return a_right;
        }
        else if (cntr_left > cntr_right && cntr_left > (right - left)/2) {
            return a_left;
        }
        else{
            return -1;
        }
    }
    return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
