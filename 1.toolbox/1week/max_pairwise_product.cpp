#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <time.h>


long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                ((long long)numbers[first]) * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    int n = numbers.size();
    int argmax_1 = -1;
    for (int i = 0; i < n; i++){
        if (argmax_1 == - 1 || numbers[i] > numbers[argmax_1]){
            argmax_1 = i;
        }
    }
    
    int argmax_2 = -1;
    for (int j = 0; j < n; j++){
        if ((numbers[j] > numbers[argmax_2] || argmax_2 == -1) && j != argmax_1){
            argmax_2 = j;
        }
    }
    
    //std::cout << argmax_1 << "\n";
    //std::cout << argmax_2 << "\n";
    
    long long max_product = ((long long) numbers[argmax_1]) * numbers[argmax_2];

    return max_product;
}


int main() {
    /*int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }*/

    //std::cout << MaxPairwiseProductFast(std::vector<int> (100'000, 0)) << "\n";
    
    
    // TESTING
    /*srand(time(NULL));
    
    while (true) {
        int n = rand() % 1000 + 2;
        std::cout << n << "\n";
        std::vector <int> a;
        for (int i = 0; i < n; i++){
            a.push_back(rand() % 100000);
        }
        for (int i = 0; i < n; i++){
            std::cout << a[i] << " ";
        }
        
        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProductFast(a);
        if (res1 != res2){
            std::cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
            break;
        }
        else{
            std::cout << "OK \n";
        }
    }*/
    
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    //std::cout << MaxPairwiseProductFast(std::vector<int> (100'000, 0)) << "\n";
    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}



