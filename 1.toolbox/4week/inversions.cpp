#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;


long long make_merge(vector<int> &a, vector<int> &b, size_t left, size_t ave, size_t right){
    int i = left;
    int j = ave;
    int k = i;
    long long number_of_inversions = 0;
    while(i < ave && j < right){
        if (a[i] <= a[j]){
            b[k] = a[i];
            k++;
            i++;
        }
        else{
            //std::cout << "INVERSION " << i << " " << j << '\n';
            b[k] = a[j];
            number_of_inversions += ave -  i ;//???
            k++;
            j++;
            
        }
    }
    while (i < ave){
        b[k] = a[i];
        k++;
        i++;
    }
    while (j < right){
        b[k] = a[j];
        k++;
        j++;
    }
    for (int i = left; i < right; i++){
        a[i] = b[i];
    }
    return number_of_inversions;
}


long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
    //std::cout << "mid = " << ave << '\n';
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  // соединить два массива в правильном порядке
    number_of_inversions += make_merge(a, b, left, ave, right);
    
    
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
    /*for (size_t i = 0; i < a.size(); i++) {
      std::cout << a[i] << " ";
    }*/
}
